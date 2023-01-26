#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1\n";
  } else {
    if (n & 1) {
      n--;
    }
    if (n % 4 == 0) {
      cout << n - 1 << "\n";
      for (long long i = 1; i <= n; i++) {
        if (i != (n / 2)) {
          cout << i << " ";
        }
      }
      cout << "\n";
    } else {
      cout << n - 2 << "\n";
      for (long long i = 1; i <= n; i++) {
        if (i != (n / 2) and (i != 2)) {
          cout << i << " ";
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
