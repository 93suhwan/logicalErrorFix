#include <bits/stdc++.h>
using namespace std;
long long conv(char c) { return c - 'a'; }
vector<long long> get_sa(const char *s, long long n) {
  vector<long long> sa(n);
  long long m = 26;
  vector<long long> cnt(max(n, m)), x(n), y(n);
  for (long long i = 0; i < (long long)(n); ++i) cnt[x[i] = conv(s[i])]++;
  for (long long i = 0; i < (long long)(m - 1); ++i) cnt[i + 1] += cnt[i];
  for (long long i = n - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;
  for (long long len = 1, p = 0; p + 1 < n; len <<= 1, m = p + 1) {
    p = 0;
    for (long long i = n - len; i < n; ++i) y[p++] = i;
    for (long long i = 0; i < (long long)(n); ++i)
      if (sa[i] >= len) y[p++] = sa[i] - len;
    for (long long i = 0; i < (long long)(m); ++i) cnt[i] = 0;
    for (long long i = 0; i < (long long)(n); ++i) cnt[x[i]]++;
    for (long long i = 0; i < (long long)(m - 1); ++i) cnt[i + 1] += cnt[i];
    for (long long i = n - 1; i >= 0; --i) sa[--cnt[x[y[i]]]] = y[i];
    y = x;
    p = 0;
    x[sa[0]] = 0;
    for (long long i = 0; i < (long long)(n - 1); ++i)
      x[sa[i + 1]] = sa[i] + len < n && sa[i + 1] + len < n &&
                             y[sa[i]] == y[sa[i + 1]] &&
                             y[sa[i] + len] == y[sa[i + 1] + len]
                         ? p
                         : ++p;
  }
  return sa;
}
vector<long long> get_lcp(const char *s, long long n, vector<long long> &sa) {
  vector<long long> lcp(n), rank(n);
  for (long long i = 0; i < (long long)(n); ++i) rank[sa[i]] = i;
  long long k = 0, j;
  for (long long i = 0; i < n; lcp[rank[i++]] = k) {
    if (rank[i] - 1 >= 0)
      for (k ? k-- : 0, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; ++k)
        ;
  }
  return lcp;
}
char S[5050];
long long dp[5050];
void solve() {
  memset(dp, 0, sizeof dp);
  long long n;
  cin >> n;
  cin >> S;
  vector<long long> sa = get_sa(S, n);
  vector<long long> lcp = get_lcp(S, n, sa);
  for (long long i = 0; i < n; ++i) {
    dp[i] = n - sa[i];
    long long commonbaby = 1e9;
    for (long long j = i - 1; j >= 0; --j) {
      commonbaby = min(commonbaby, lcp[j + 1]);
      if (sa[j] < sa[i]) {
        dp[i] = max(dp[i], dp[j] + n - sa[i] - commonbaby);
      }
    }
  }
  cout << *max_element(dp, dp + n) << '\n';
}
signed main(void) {
  cin.tie(0)->sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
