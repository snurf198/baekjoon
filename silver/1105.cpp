#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string L, R;

  cin >> L >> R;

  if (L.length() != R.length()) {
    cout << 0 << '\n';

    return 0;
  }

  int result = 0;

  for (int i = 0; i < L.length(); i++) {
    if(L[i] == R[i]) {
      if (L[i] == '8') {
        result++;
      }
    } else break;
  }

  cout << result << '\n';

  return 0;
}