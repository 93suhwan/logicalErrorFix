#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int cost[N][N];
vector<vector<vector<int>>> dp;
string s, t;
int n, m;
int pf[N];
int pfc[N];
int z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z[n - 1];
}
int K;
const int inf = 1e9 + 5;
int solve(int i, int j, int k) {
  if (k < 0) return inf;
  if (i == n) {
    if (k) return inf;
    return 0;
  }
  int &res = dp[i][j][k];
  if (~res) return res;
  res = inf;
  int c = 0;
  if (s[i] != t[j]) c++;
  int dc = c ^ 1;
  {
    int nj = j + 1;
    int nk = k;
    if (nj == m) {
      nk = k - 1;
      nj = pf[m - 1];
    }
    res = min(res, c + solve(i + 1, nj, nk));
    res = min(res, dc + solve(i + 1, pfc[j], k));
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> s >> t;
  K = n - m + 2;
  dp = vector<vector<vector<int>>>(
      n + 1, vector<vector<int>>(m + 1, vector<int>(n - m + 3)));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < K; k++) dp[i][j][k] = -1;
    }
  }
  pf[m - 1] = z_function(t);
  for (int i = 0; i < m; i++) {
    string temp;
    for (int j = 0; j < i; j++) temp += t[j];
    if (t[i] == '0')
      temp += '1';
    else
      temp += '0';
    pfc[i] = z_function(temp);
  }
  for (int k = 0; k < K; k++) {
    int ans = solve(0, 0, k);
    if (ans >= inf)
      cout << -1 << " ";
    else
      cout << ans << " ";
  }
}
