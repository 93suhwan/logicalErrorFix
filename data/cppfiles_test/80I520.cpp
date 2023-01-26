#include <bits/stdc++.h>
using namespace std;
long long int binpowmod(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return binpowmod(n, p - 2, p);
}
int main() {
  long long int t, n, j, k, i, f, h, l, r, t1, t2, a, b, x, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    f = 0;
    x = -1;
    for (i = 0; i < n; ++i) {
      if (s[i] == '0') {
        f = 1;
        x = i;
        break;
      }
    }
    if (f) {
      if (x <= n / 2) {
        cout << x << " " << n << " " << x + 1 << " " << n << "\n";
      } else {
        cout << 1 << " " << x << " " << 1 << " " << x - 1 << "\n";
      }
    } else
      cout << 1 << " " << n / 2 << " " << n / 2 << " " << n << "\n";
  }
  return 0;
}
