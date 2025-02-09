#include <iostream>

using namespace std;

int board[15][15];

void operate_queen(int x, int y, int dir) {
    for (int i = 0; i < 15; i++) {
        board[x][i] += dir;
    }

    for (int i = 0; i < 15; i++) {
        board[i][y] += dir;
    }

    int i = x, j = y;
    while(i < 15 && j < 15) {
        board[i][j] += dir;
        i++;
        j++;
    }

    i = x, j = y;
    while(i < 15 && 0 < j) {
        board[i][j] += dir;
        i++;
        j--;
    }

    i = x, j = y;
    while(0 < i && j < 15) {
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

int run(int x, int N) {
    if (x == N) {
        return 1;
    }
    int sum = 0;
    for (int j = 1; j <= N; j++) {
        if (board[x+1][j] == 0) {
            operate_queen(x+1, j, 1);
            sum += run(x + 1, N);
            operate_queen(x+1, j, -1);
        }
    }

    return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        board[i][j] = 0;
    }
  }

  int N;
  cin >> N;

  cout << run(0, N);

  return 0;
}