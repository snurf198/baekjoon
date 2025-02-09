#include <iostream>

using namespace std;

int board[15][15];

void operate_queen(int x, int y, int dir, int N) {
    for (int i = 1; i <= N; i++) {
        board[x][i] += dir;
    }

    for (int i = 1; i <= N; i++) {
        board[i][y] += dir;
    }

    int i = x, j = y;
    while(i <= N && j <= N) {
        board[i][j] += dir;
        i++;
        j++;
    }

    i = x, j = y;
    while(i <= N && 0 < j) {
        board[i][j] += dir;
        i++;
        j--;
    }

    i = x, j = y;
    while(0 < i && j <= N) {
        board[i][j] += dir;
        i--;
        j++;
    }

    i = x, j = y;
    while(0 < i && 0 < j) {
        board[i][j] += dir;
        i--;
        j--;
    }
}

int run(int current_num_queen, int N) {
    if (current_num_queen == N) {
        return 1;
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (board[current_num_queen+1][i] == 0) {
            operate_queen(current_num_queen + 1, i, 1, N);
            sum += run(current_num_queen + 1, N);
            operate_queen(current_num_queen + 1, i, -1, N);
        }
    }

    return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
        board[i][j] = 0;
    }
  }

  cout << run(0, N);

  return 0;
}