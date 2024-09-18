#include <iostream>

using namespace std;

int A[50][50];
int B[50][50];
int N, M;

bool compare_matrix(int(&X)[50][50], int(&Y)[50][50]) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (X[i][j] != Y[i][j]) return false;
    }
  }  

  return true;
}

void flip(int(&X)[50][50], int a, int b) {
  for (int i = a; i < a + 3; i++) {
    for (int j = b; j < b + 3; j++) {
      X[i][j] = !X[i][j];
    }
  }
}

int solve() {
  int max_x = M - 3;
  int max_y = N - 3;
  int count = 0;

  for (int i = 0; i <= max_y; i++) {
    for (int j = 0; j <= max_x; j++) {
      if(A[i][j] != B[i][j]) {
        flip(A, i, j);
        count++;
      }
    }
  }

  if (compare_matrix(A, B)) return count;

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      A[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      B[i][j] = s[j] - '0';
    }
  }

  cout << solve() << '\n';

  return 0;
}