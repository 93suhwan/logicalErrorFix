#include <bits/stdc++.h>
using namespace std;
bool isPrime[50000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> primes;
  fill(isPrime, isPrime + 50000, true);
  for (int i = 2; i < 50000; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i + i; j < 50000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 - 1 << ' ' << n / 2 << ' ' << 1 << '\n';
    } else {
      for (int p : primes) {
        if ((n - 1) % p != 0) {
          cout << p << ' ' << n - 1 - p << ' ' << 1 << '\n';
          break;
        }
      }
    }
  }
}
