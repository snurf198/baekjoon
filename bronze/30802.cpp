#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int counts[6];
  int T, P;
  int t = 0, p, o;

  cin >> N;
  cin >> counts[0] >> counts[1] >> counts[2] >> counts[3] >> counts[4] >> counts[5];
  cin >> T >> P;

  p = N / P;
  o = N % P;

  for (int i = 0; i < 6; i++) {
    int resid = (counts[i] % T == 0) ? 0 : 1;
    t += (counts[i] / T) + resid;
  }

  cout << t << '\n';
  cout << p << ' ' << o << '\n';

  return 0;
}