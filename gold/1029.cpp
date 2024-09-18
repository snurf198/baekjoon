#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int map[16][16];
int dp[16][(1<<15)][10];
int N;

int solve(int cur, long long visited, int prevPrice) {
  if (dp[cur][visited][prevPrice] != -1) return dp[cur][visited][prevPrice];
  int result = 1;

  for(int next = 1; next <= N; next++) {
    if(visited & (1 << (next-1))) continue;
    if(map[cur][next] < prevPrice) continue;

    result = max(result, solve(next, visited | (1 << (next-1)), map[cur][next]) + 1);
  }

  dp[cur][visited][prevPrice] = result;

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    string s;

    cin >> s;
    for (int j = 1; j <= N; j++) {
      map[i][j] = s[j-1] - '0';
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(1, 1, 0) << '\n';

  return 0;
}