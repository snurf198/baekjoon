#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A, B;

  scanf("%d %d", &A, &B);
  vector<bool> isNotPrime(B+1);
  vector<int> count(B-A+1);

  isNotPrime[0] = true;
  isNotPrime[1] = true;

  for (int i = 2; i <= B; i++) {
    if(isNotPrime[i]) continue;

    for (int j = 2; j <= B/i; j++) {
      isNotPrime[i*j] = true;

      int mulOfPNum = i*j;
      int temp = mulOfPNum;
      if ((mulOfPNum - A) >= 0) {
        while((temp % i == 0)) {
          count[mulOfPNum-A]++;
          temp /= i;
        }
      }
    }
  }

  int result = 0;

  for (int i = 0; i <= B-A; i++) {
    if(!isNotPrime[count[i]]) result++;
  }

  printf("%d\n", result);

  return 0;
}