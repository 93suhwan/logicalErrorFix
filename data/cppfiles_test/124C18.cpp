#include <bits/stdc++.h>
using namespace std;
string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int INF = 1e9 + 7, N = 2002, M = 1e9 + 7;
void add(int& a, int b) {
  a += b;
  if (a >= M) a -= M;
}
void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i += 2) {
    if (s[i] != '?') s[i] ^= 1;
    if (t[i] != '?') t[i] ^= 1;
  }
  vector<pair<int, int> > dp(2 * n + 1);
  dp[n] = {1, 0};
  for (int i = 0; i < n; i++) {
    vector<pair<int, int> > ndp(2 * n + 1);
    for (int j = 0; j < 2 * n + 1; j++)
      if (dp[j].first) {
        for (int x = 0; x < 2; x++)
          if (s[i] != ('1' ^ x)) {
            for (int y = 0; y < 2; y++)
              if (t[i] != ('1' ^ y)) {
                int nj = j + x - y, cost = 0;
                if (!(j == n && x == 1 && y == 1)) {
                  if (x) {
                    if (j >= n)
                      add(cost, M - i);
                    else
                      add(cost, i);
                  }
                  if (y) {
                    if (j <= n)
                      add(cost, M - i);
                    else
                      add(cost, i);
                  }
                }
                add(ndp[nj].first, dp[j].first);
                add(ndp[nj].second, dp[j].second);
                add(ndp[nj].second, int(1LL * dp[j].first * cost % M));
              }
          }
      }
    swap(dp, ndp);
  }
  cout << dp[n].second << '\n';
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
