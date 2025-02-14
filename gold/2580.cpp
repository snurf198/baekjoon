#include <iostream>

using namespace std;

int X[10];
int X_c[10];
int Y[10];
int Y_c[10];
int G[10];
int G_c[10];
int sudoku[10][10];
int total_count = 0;

bool check_overlap(int num, int x, int y) {
    int check = 1 << (num-1);
    int g_x = (x+2) / 3;
    int g_y = (y+2) / 3;
    int g_i = 3*(g_y-1) + g_x;
    return ((X[x] | Y[y] | G[g_i]) & check) != 0;
}

void add_number(int num, int x, int y) {
    sudoku[y][x] = num;

    if (num > 0) {
        int num_1 = num - 1;
        X[x] |= (1 << num_1);
        X_c[x]++;
        Y[y] |= (1 << num_1);
        Y_c[y]++;
        int g_x = (x+2) / 3;
        int g_y = (y+2) / 3;
        int g_i = 3*(g_y-1) + g_x;
        G[g_i] |= (1 << num_1);
        G_c[g_i]++;
        total_count++;
    }

}

void del_number(int x, int y) {
    int temp = sudoku[y][x];
    sudoku[y][x] = 0;
    int num_1 = temp - 1;
    X[x] ^= (1 << num_1);
    X_c[x]--;
    Y[y] ^= (1 << num_1);
    Y_c[y]--;
    int g_x = (x+2) / 3;
    int g_y = (y+2) / 3;
    int g_i = 3*(g_y-1) + g_x;
    G[g_i] ^= (1 << num_1);
    G_c[g_i]--;
    total_count--;
}

bool is_full() {
    return total_count == 81;
}

int solve() {
    if (is_full()) return 1;
    
    for (int y = 1; y < 10; y++) {
        for (int x = 1; x < 10; x++) {
            if (sudoku[y][x] == 0) {
                for (int k = 1; k < 10; k++) {
                    if(check_overlap(k, x, y)) continue;
                    add_number(k, x, y);
                    if(solve() == 1) return 1;
                    del_number(x, y);
                }

                return -1;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int elem;

    for (int i = 1; i < 10; ++i) {
        X[i] = 0;
        X_c[i] = 0;
        Y[i] = 0;
        Y_c[i] = 0;
        G[i] = 0;
        G_c[i] = 0;
    }

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            cin >> elem;
            add_number(elem, j, i);
        }
    }

    cout << endl;
    
    solve();

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            cout << sudoku[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}