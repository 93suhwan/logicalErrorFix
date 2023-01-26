#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 47;
const int nax = 2 * (int)1e5 + 10;
struct vertex {
  int next[2];
  bool leaf;
  int p;
  int pch;
  int link;
  int go[2];
};
vertex t[550];
int sz;
void init() {
  t[0].p = t[0].link = -1;
  memset(t[0].next, 255, sizeof t[0].next);
  memset(t[0].go, 255, sizeof t[0].go);
  sz = 1;
}
void add_string(const string& s) {
  int v = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    int c = s[i] - '0';
    if (t[v].next[c] == -1) {
      memset(t[sz].next, 255, sizeof t[sz].next);
      memset(t[sz].go, 255, sizeof t[sz].go);
      t[sz].link = -1;
      t[sz].p = v;
      t[sz].pch = c;
      t[v].next[c] = sz++;
    }
    v = t[v].next[c];
  }
  t[v].leaf = true;
}
int go(int v, int c);
int get_link(int v) {
  if (t[v].link == -1)
    if (v == 0 || t[v].p == 0)
      t[v].link = 0;
    else
      t[v].link = go(get_link(t[v].p), t[v].pch);
  return t[v].link;
}
int go(int v, int c) {
  if (t[v].go[c] == -1)
    if (t[v].next[c] != -1)
      t[v].go[c] = t[v].next[c];
    else
      t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
  return t[v].go[c];
}
int dp[501][501][503];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  init();
  add_string(b);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= n - m + 1; k++) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n - m + 1; k++) {
        int nw = go(j, 1);
        dp[i + 1][nw][k + t[nw].leaf] =
            min(dp[i + 1][nw % m][k + t[nw].leaf], dp[i][j][k] + (a[i] != '1'));
        nw = go(j, 0);
        dp[i + 1][nw][k + t[nw].leaf] =
            min(dp[i + 1][nw % m][k + t[nw].leaf], dp[i][j][k] + (a[i] != '0'));
      }
    }
  }
  for (int k = 0; k <= n - m + 1; k++) {
    int mn = INF;
    for (int j = 0; j <= m; j++) {
      mn = min(mn, dp[n][j][k]);
    }
    if (mn == INF)
      cout << -1 << ' ';
    else
      cout << mn << ' ';
  }
}
