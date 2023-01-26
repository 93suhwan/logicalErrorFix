#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 998244353;
int fact[maxn];
int add(int a, int b) { return (a + b) % mod; }
int minuse(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int b) {
  if (!b) return 1;
  if (b == 1) return a;
  int res = pwr(a, b / 2);
  res = mul(res, res);
  if (b % 2) res = mul(res, a);
  return res;
}
int inv(int a) { return pwr(a, mod - 2); }
int comb(int n, int r) {
  int res = fact[n];
  res = mul(res, inv(fact[r]));
  res = mul(res, inv(fact[n - r]));
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  int a = 0, b = 0, c = 0, d = 0;
  int x = 0, y = 0;
  int fa = 0, fb = 0, fc = 0, fd = 0;
  int cnt = 0;
  int n;
  cin >> n;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    char c1, c2;
    cin >> c1 >> c2;
    if (c2 == 'B')
      c2 = 'W';
    else if (c2 == 'W')
      c2 = 'B';
    if (c1 == 'B')
      a++;
    else if (c1 == 'W')
      c++;
    else
      x++;
    if (c2 == 'B')
      b++;
    else if (c2 == 'W')
      d++;
    else
      y++;
    if (c1 == '?' || c2 == '?') {
      if (c1 == 'B') fb++;
      if (c2 == 'B') fa++;
      if (c1 == 'W') fd++;
      if (c2 == 'W') fc++;
      if (c1 == '?' && c2 == '?') cnt++;
    }
    if (c1 != '?' && c2 != '?' && c1 != c2) ok = false;
  }
  int ans = 0;
  for (int i = max(a, b); i <= n; i++) {
    if (i - a <= x && i - b <= y && c + x - (i - a) == d + y - (i - b)) {
      ans = add(ans, mul(comb(x, i - a), comb(y, i - b)));
    }
  }
  a += fa;
  b += fb;
  c += fc;
  d += fd;
  if (ok && a == b && c == d) {
    int res = pwr(2, cnt);
    if (!a) res = minuse(res, 1);
    if (!c) res = minuse(res, 1);
    ans = minuse(ans, res);
  }
  cout << ans;
  return 0;
}
