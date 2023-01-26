#include <bits/stdc++.h>
using namespace std;
const int M = 2e3 + 10;
const int md = 1e9 + 7;
void add(pair<int, int>& a, pair<int, int> b, int x = 0) {
  a.first += b.first;
  if (a.first >= md) a.first -= md;
  a.second += b.second;
  if (a.second >= md) a.second -= md;
  a.second += (x * 1ll * b.first) % md;
  if (a.second >= md) a.second -= md;
}
vector<int> get(char c) {
  if (c != '?') return {c - '0'};
  return {0, 1};
}
pair<int, int> dp[M][M][3][3];
int n;
string s, t;
pair<int, int> f(int i, int j, int oki = 2, int okj = 2) {
  if (i >= n and j >= n) {
    return {1, 0};
  }
  pair<int, int>& ans = dp[i][j][oki][okj];
  if (ans.first != -1) return ans;
  ans = {0, 0};
  pair<int, int> now;
  if (oki > 1 or okj > 1) {
    vector<int> sv(1, 0), tv(1, 0);
    if (i < n) sv = get(s[i]);
    if (j < n) tv = get(t[j]);
    if (oki < 2) sv = {oki};
    if (okj < 2) tv = {okj};
    for (int ok1 : sv)
      for (int ok2 : tv) {
        add(ans, f(i, j, ok1, ok2));
      }
  } else {
    if (oki and okj) {
      add(ans, f(i + 1, j + 1, 2, 2), abs(i - j));
    } else {
      if (!oki and !okj and i < n and j < n) {
        add(ans, f(i + 1, j + 1, 2, 2));
      } else if (!okj and j < n) {
        add(ans, f(i, j + 1, oki, 2));
      } else if (!oki and i < n) {
        add(ans, f(i + 1, j, 2, okj));
      }
    }
  }
  return ans;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int testCases;
  cin >> testCases;
  while (testCases--) {
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i += 2) {
      if (s[i] != '?') s[i] = s[i] == '0' ? '1' : '0';
      if (t[i] != '?') t[i] = t[i] == '0' ? '1' : '0';
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int oki : {0, 1, 2})
          for (int okj : {0, 1, 2}) dp[i][j][oki][okj] = {-1, -1};
      }
    }
    cout << f(0, 0).second << "\n";
  }
  return 0;
}
