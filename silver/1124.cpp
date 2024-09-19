#include <iostream>
#include <cstring>

using namespace std;

bool isPrime[100001];
int lnum[100001];
int count[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A, B;

  cin >> A >> B;

  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 1; i <= 100001; i++) {
    lnum[i] = i;
  }

  for (int i = 2; i <= B; i++) {
    if(!isPrime[i]) continue;

    for (int j = 2; j <= B/i; j++) {
      isPrime[i*j] = false;
      while(lnum[i*j] % i == 0) {
        lnum[i*j] /= i;
        count[i*j]++;
      }
    }
  }

  int result = 0;

  for (int i = A; i <= B; i++) {
    if(isPrime[count[i]]) result++;
  }

  cout << result << '\n';

  return 0;
}