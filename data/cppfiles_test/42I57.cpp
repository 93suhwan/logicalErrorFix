#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n;
struct rw {
  int a, b, id;
} s[N];
template <int N>
struct fenwt {
  using F = long long;
  F a[N + 1];
  void add(int x, F w) {
    for (; x <= N; x += x & -x) a[x] += w;
  }
  F query(int x) {
    F ret = 0;
    for (; x; x -= x & -x) ret += a[x];
    return ret;
  }
  F get(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }
};
fenwt<N> S;
int mp[N], at[N], dp[N], suf[N];
int f[N], rdp[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> s[i].a >> s[i].b, s[i].id = i;
  sort(s + 1, s + n + 1, [&](rw a, rw b) { return a.a < b.a; });
  for (int i = (1); i <= (n); ++i) mp[s[i].id] = i, at[i] = s[i].b;
  for (int i = (n); i >= (1); --i) {
    dp[i] = 1;
    (dp[i] += S.query(s[i].b) % mod) %= mod;
    rdp[i] = dp[i];
    suf[i] = (suf[i + 1] + dp[i]) % mod;
    S.add(s[i].b, dp[i]);
  }
  int q;
  cin >> q;
  int mx = 0, cmx = 0, amx = 0;
  while (q--) {
    int x;
    cin >> x, x = mp[x];
    vis[x] = 1;
    mx = max(mx, s[x].b);
    cmx = max(cmx, x);
    amx = max(amx, s[x].a);
  }
  int ns = 0;
  for (int i = (1); i <= (n); ++i) {
    if (vis[i]) {
      (ns += rdp[i]) %= mod;
    } else {
      if (i <= cmx) {
        if (s[i].b <= mx) (ns += rdp[i]) %= mod;
      } else {
        if (s[i].b <= amx) (ns += rdp[i]) %= mod;
      }
    }
  }
  cout << ns << '\n';
  return 0;
}
