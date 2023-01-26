#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 3e5 + 10;
const int md = 1e9 + 7;
inline int add(int x, int y) { return (x += y) >= md ? x -= md : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x += md : x; }
inline int mul(int x, int y) { return 1ll * x * y % md; }
inline int qpow(int x, ll n, int mod = md) {
  int r = 1;
  while (n > 0) {
    if (n & 1) r = 1ll * r * x % mod;
    n >>= 1;
    x = 1ll * x * x % mod;
  }
  return r;
}
inline int inv(int x) { return qpow(x, md - 2); }
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) b[i] = a[(i + n - d) % n];
    int c = 0, d1 = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] & b[i])) c++;
      if (a[i]) d1++;
    }
    c = d1 - c;
    ;
    if (!d1) {
      cout << "0\n";
      continue;
    }
    if (!c) {
      cout << "-1\n";
      continue;
    }
    if (d1 % c)
      d1 = d1 / c + 1;
    else
      d1 = d1 / c;
    cout << d1 << "\n";
  }
}
