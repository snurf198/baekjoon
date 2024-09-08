#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long min, max;

  cin >> min >> max;

  long i = 2;
  long tmp = min;
  long k;
  vector<bool> bitmap(max - min + 1, false);

  while ((i * i) <= max) {
    long squared = i * i;
    long a = (tmp % squared == 0) ? 0 : 1;
    k = (tmp / squared) + a;

    while ((squared * k) <= max) {
      bitmap[squared * k - min] = true;
      k++;
    }

    i++;
  }

  int result = 0;

  for (int j = 0; j < max - min + 1; j++) {
    if (!bitmap[j]) result++;
  }

  cout << result << "\n";

  return 0;
}