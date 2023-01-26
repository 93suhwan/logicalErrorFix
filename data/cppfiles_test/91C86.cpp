#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
const int MOD = 998244353;
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long add(long long a, long long b) { return (a + b) % MOD; }
const int N = 1e5 + 2;
const int S = 702;
int b[2][S];
int siz[N];
int dp[2][S];
int a[N];
void init(int i) {
  auto &bb = b[i % 2];
  int x = a[i];
  siz[i] = 0;
  for (int k = 1; k <= min(S, x); ++k) {
    if (siz[i] and x / k == bb[siz[i] - 1]) break;
    bb[siz[i]++] = x / k;
  }
  for (int val = 1; val <= min(S, x); ++val) {
    if (x / (x / val) != val) break;
    bb[siz[i]++] = val;
  }
  sort(bb, bb + siz[i]);
  siz[i] = unique(bb, bb + siz[i]) - bb;
}
void solve() {
  int n, res;
  cin >> n;
  fill(siz, siz + n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  fill(dp[0], dp[0] + S, 0);
  fill(dp[1], dp[1] + S, 0);
  res = 0;
  init(n);
  dp[n % 2][siz[n]] = 1;
  int sz, x, y, ad, k, pos, s, idx;
  for (int i = n - 1; i >= 1; --i) {
    init(i);
    auto &b1 = b[(i + 1) % 2];
    sz = siz[i + 1];
    auto &bb = b[i % 2];
    s = siz[i];
    auto &cur = dp[i % 2];
    fill(cur, cur + S, 0);
    cur[s] = 1;
    auto &nxt = dp[(i + 1) % 2];
    idx = 0;
    for (int j = 0; j < sz; ++j) {
      ad = nxt[j + 1];
      if (ad == 0) continue;
      y = b1[j];
      if (a[i] <= y) {
        cur[s] = add(cur[s], ad);
        continue;
      }
      k = (a[i] + y - 1) / y;
      x = a[i] / k;
      while (idx < s and bb[idx] < x) ++idx;
      assert(idx < s and bb[idx] == x);
      pos = idx + 1;
      cur[pos] = add(cur[pos], ad);
      res = add(res, mul(k - 1, mul(ad, i)));
    }
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
