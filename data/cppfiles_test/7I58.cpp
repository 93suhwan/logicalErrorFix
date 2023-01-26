#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream &operator<<(ostream &o, const pair<T, S> &p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream &>::type operator<<(
    ostream &o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
string s, t;
int n, m, lc = 0, dp[501][501][501], lcp[501];
int r(int i, int k, int l) {
  if (l == m) k--, l = lc;
  if (i >= n) return dp[i][k][l] = k ? 1000000007 : 0;
  if (~dp[i][k][l]) return dp[i][k][l];
  int cx = s[i] == t[l] ? 0 : 1;
  dp[i][k][l] = min(r(i + 1, k, l + 1) + cx, r(i + 1, k, lcp[l]) + 1 - cx);
  return dp[i][k][l] = min(1000000007, dp[i][k][l]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> m >> s >> t;
  for (int j = 1; j < (m); ++j) {
    bool ok = true;
    for (int k = 0; k < (m - j); ++k)
      if (t[k] - t[j + k]) ok = false;
    if (ok) lc = max(lc, m - j);
  }
  for (int l = 0; l < (m); ++l) {
    string q = t.substr(0, l) + (t[l] == '0' ? "1" : "0");
    for (int j = 0; j < (q.size()); ++j) {
      bool ok = true;
      for (int k = 0; k < (j); ++k)
        if (t[k] - q[q.size() - j + k]) ok = false;
      if (ok) lcp[l] = max(lcp[l], j);
    }
  }
  for (int i = 0; i < (n - m + 2); ++i) {
    int ans = r(0, i, 0);
    cout << (ans >= 1000000007 ? -1 : ans) << ' ';
  }
  cout << '\n';
}
