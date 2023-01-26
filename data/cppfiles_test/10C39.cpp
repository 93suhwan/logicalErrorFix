#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
void INPUT(bool F = 0) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (F) {
    freopen(
        "name"
        ".in",
        "r", stdin);
    freopen(
        "name"
        ".out",
        "w", stdout);
  }
}
const long long M = 1e9 + 7;
void add(long long &a, long long b) {
  a += b;
  if (a >= M)
    a -= M;
  else if (a < 0)
    a += M;
}
long long mult(long long a, long long b) { return 1ll * a * b % M; }
long long binpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = mult(ans, a);
    b /= 2;
    a = mult(a, a);
  }
  return ans;
}
signed main() {
  INPUT();
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long _x = max(x1, x2), _x1 = min(x1 + r - 1, x2 + r - 1);
  long long _y = max(y1, y2), _y1 = min(y1 + c - 1, y2 + c - 1);
  long long inter =
      max((long long)0, _x1 - _x + 1) * max((long long)0, _y1 - _y + 1);
  long long ans = 1;
  long long free = n * m - 2 * r * c + inter;
  ans = binpow(k, free);
  if (inter != r * c)
    ans = mult(ans, binpow(k, r * c - inter));
  else
    ans = mult(ans, binpow(k, r * c));
  cout << ans;
  return 0;
}
