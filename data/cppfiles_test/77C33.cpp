#include <bits/stdc++.h>
using namespace std;
const int maxn = 1E6 + 10;
const int maxq = 1e3 + 11;
const int mad = 1e9 + 7;
int b[maxq][maxq];
string s[maxq][maxq];
vector<pair<int, int> > G[maxq][maxq];
int v = 0;
int mark[maxq][maxq];
vector<int> ans;
string bi(int a) {
  string s;
  for (int i = 8; i != 0; i /= 2) {
    if (a >= i) {
      s += '1';
      a -= i;
    } else {
      s += '0';
    }
  }
  return s;
}
void node(string s, int i, int j) {
  if (s[0] == '0') {
    G[i][j].push_back({i - 1, j});
  }
  if (s[1] == '0') {
    G[i][j].push_back({i, j + 1});
  }
  if (s[2] == '0') {
    G[i][j].push_back({i + 1, j});
  }
  if (s[3] == '0') {
    G[i][j].push_back({i, j - 1});
  }
}
void dfs(int i, int j) {
  v++;
  mark[i][j] = 1;
  for (int k = 0; k < G[i][j].size(); k++) {
    int u1 = G[i][j][k].first, u2 = G[i][j][k].second;
    if (mark[u1][u2] == 0) {
      dfs(u1, u2);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      s[i][j] = bi(b[i][j]);
      node(s[i][j], i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mark[i][j] == 0) {
        dfs(i, j);
        ans.push_back(v);
        v = 0;
      }
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
