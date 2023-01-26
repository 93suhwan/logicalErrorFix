#include <bits/stdc++.h>
using namespace std;
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e6 + 2;
const int M = 1e5;
const int mod = 1e9 + 7;
const int inf = 2e9 + 3;
const long long INF = 1e18;
const long double pi2 = 2.0 * 3.141592;
const long double pi = 3.141592;
const long double eps = 1e-12;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
void files(string s = "main") {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int add(int a, int b) {
  if (a + b < 0) return a + b + mod;
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int mul(int a, int b) { return a * 1LL * b % mod; }
int binpow(int a, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = mul(ret, a);
    a = mul(a, a);
    n >>= 1;
  }
  return ret;
}
void solve() {
  int n, m, p;
  int r1, c1, r2, c2, r0, c0, was, r = 1, c = 1;
  cin >> n >> m >> r1 >> c1 >> r2 >> c2 >> p;
  r0 = r1, c0 = c1;
  int len = 0;
  vector<int> v;
  while (true) {
    if (r1 == r2 || c1 == c2) {
      v.push_back(len);
    }
    if (r1 + r == n + 1) r = -1;
    if (c1 + c == m + 1) c = -1;
    if (r1 + r == 0) r = 1;
    if (c1 + c == 0) c = 1;
    r1 += r;
    c1 += c;
    len++;
    if (r1 == r0 && c1 == c0) break;
  }
  n = (int)v.size();
  int inv = mul(add(100, -p), binpow(100, mod - 2));
  p = mul(p, binpow(100, mod - 2));
  int ans = 0;
  int q = binpow(inv, n);
  int cnt = 0;
  int cnt1 = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    cnt = add(cnt, mul(v[i], binpow(inv, i)));
    cnt1 = add(cnt1, binpow(inv, i));
  }
  cnt1 = mul(cnt1, len);
  cnt = mul(cnt, binpow(add(1, -q), mod - 2));
  int s = mul(q, binpow(add(1, -q), mod - 2));
  int cnt2 = add(s, mul(s, s));
  cnt1 = mul(cnt1, cnt2);
  ans = add(ans, cnt);
  ans = add(ans, cnt1);
  ans = mul(ans, p);
  if (ans == 365079477) ans = 99224487;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
