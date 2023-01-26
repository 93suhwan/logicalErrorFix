#include <bits/stdc++.h>
using namespace std;
char buf[100000], *p1(buf), *p2(buf);
inline int read() {
  int x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  return f ? x : -x;
}
using ll = long long;
const int N = 2e2 + 10;
int n, mod;
int fc[N], fv[N];
inline void chk(int &x) {
  x -= mod;
  x += x >> 31 & mod;
}
inline int mll(int x, int y) { return (ll)x * y % mod; }
inline int ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = mll(x, x))
    if (y & 1) ret = mll(ret, x);
  return ret;
}
inline void input() {
  n = read(), mod = read();
  return;
}
inline void pref(const int lim) {
  fc[0] = 1;
  for (int i = 1; i <= lim; i++) fc[i] = mll(fc[i - 1], i);
  fv[lim] = ksm(fc[lim], mod - 2);
  for (int i = lim; i >= 1; i--) fv[i - 1] = mll(fv[i], i);
  return;
}
bool vis[N][N][50];
int dp[N][N][50];
int frst;
int calc(int cnt, int sum, int cur, int lim) {
  if (vis[cnt][sum][cur]) return dp[cnt][sum][cur];
  vis[cnt][sum][cur] = true;
  int &ret = dp[cnt][sum][cur];
  ret = 0;
  if (cur <= lim - 1 && cnt < cur) return ret;
  if (cur == lim) {
    if (cnt < n) ret = fv[n - cnt];
    return ret;
  }
  int x = n + 1 - cur - frst;
  for (int j = 0; cnt + j <= n && sum + j * x <= frst; j++)
    chk(ret += mll(calc(cnt + j, sum + j * x, cur + 1, lim), fv[j]));
  return ret;
}
inline void work() {
  pref(n);
  int ans = 0;
  for (int lim = 0; lim <= 32; lim++) {
    memset(vis, 0, sizeof(vis));
    frst = n + 1 - lim;
    chk(ans += calc(0, 0, 0, lim));
  }
  cout << mll(ans, fc[n]) << '\n';
  return;
}
inline void solve() {
  input();
  work();
  return;
}
int main() {
  solve();
  return 0;
}
