#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  vector<bool> result;

  cin >> a >> b >> c;

  while(!(a == 0 && b == 0 && c == 0)) {
    long long a2 = a * a;
    long long b2 = b * b;
    long long c2 = c * c;

    if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2)) {
      result.push_back(true);
    } else {
      result.push_back(false);
    }
    cin >> a >> b >> c;
  }


  for(int i = 0; i < result.size(); i++) {
    cout << (result[i] ? "right" : "wrong") << '\n';
  }

  return 0;
}