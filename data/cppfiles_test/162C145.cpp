#include <bits/stdc++.h>
using namespace std;
inline ll qpow(ll x, ll a) {
  ll ret = 1, k = x;
  for (; a; a >>= 1, k = k * k)
    if (a & 1) ret = ret * k;
  return ret;
}
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(a % b, b);
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == ' - ') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + int(ch - '0');
    ch = getchar();
  }
  return x * f;
}
ll xor_n(ll n) {
  ll t = n & 3;
  if (t & 1) return t / 2ll ^ 1;
  return t / 2ll ^ n;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll r = exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - a / b * y;
  return r;
}
int mod = 998244353;
inline ll mqpow(ll x, ll a) {
  ll ret = 1, k = x;
  for (; a; a >>= 1, k = k * k % mod)
    if (a & 1) ret = ret * k % mod;
  return ret;
}
ll abs_(ll x) { return x < 0 ? -x : x; }
int n;
ll a[200010];
ll b[200010];
bool check(ll mid) {
  for (int i = 0; i < n; i++) {
    b[i] = 0;
  }
  for (int i = n - 1; i >= 2; i--) {
    if (a[i] + b[i] >= mid) {
      ll tmp = a[i] - max(0ll, (mid - b[i]));
      if (tmp < 0) {
        continue;
      }
      tmp /= 3;
      b[i - 1] += tmp;
      b[i - 2] += tmp * 2;
    } else
      return false;
  }
  if (a[0] + b[0] >= mid && a[1] + b[1] >= mid)
    return true;
  else
    return false;
}
int bs(int l, int r) {
  while (l < r) {
    ll mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
int main(void) {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << bs(1, 1e9) << '\n';
  }
}
