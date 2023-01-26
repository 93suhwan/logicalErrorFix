#include <bits/stdc++.h>
using namespace std;
void neive(long long n, bool prime[]) {
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] != 0) {
      for (long i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
}
long long power(long long x, long long y, long long Mod) {
  long long res = 1;
  x = x % Mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % Mod;
    y = y >> 1;
    x = (x * x) % Mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tk;
  cin >> tk;
  while (tk--) {
    long long n;
    cin >> n;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    } else if (n <= 8) {
      cout << 20 << endl;
      continue;
    } else if (n <= 10) {
      cout << 25 << endl;
      continue;
    }
    if (n % 2 == 0) {
      cout << (n * 5) / 2 << endl;
    } else {
      cout << ((n + 1) * 5) / 2 << endl;
    }
  }
  return 0;
}
