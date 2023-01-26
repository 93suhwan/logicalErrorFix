#include <bits/stdc++.h>
using namespace std;
struct aho_corasick {
  static const int K = 2;
  struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int cnt = 0;
    bool ok = 0;
    Vertex(int p = -1, char ch = '#') : p(p), pch(ch) {
      fill(begin(next), end(next), -1);
      fill(begin(go), end(go), -1);
    }
  };
  vector<Vertex> t;
  void init() {
    t.clear();
    t.push_back(Vertex());
  }
  void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
      int c = ch - '0';
      if (t[v].next[c] == -1) {
        t[v].next[c] = t.size();
        t.emplace_back(v, ch);
      }
      v = t[v].next[c];
    }
    t[v].leaf = true;
  }
  int get_link(int v) {
    if (t[v].link == -1) {
      if (v == 0 || t[v].p == 0)
        t[v].link = 0;
      else
        t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
  }
  int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
      if (t[v].next[c] != -1)
        t[v].go[c] = t[v].next[c];
      else
        t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
  }
} aho;
int dp[2][505][505];
string s, t;
int main() {
  aho.init();
  int n, m;
  cin >> n >> m;
  cin >> s >> t;
  aho.add_string(t);
  memset(dp, -1, sizeof(dp));
  int x = 0;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    memset(dp[x ^ 1], -1, sizeof(dp[x ^ 1]));
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (dp[x][j][k] == -1) continue;
        for (int y = 0; y < 2; y++) {
          int cur = j;
          int cnt = 0;
          if (s[i] - '0' != y) cnt++;
          cur = aho.go(cur, y + '0');
          int res = 0;
          if (aho.t[cur].leaf) res++;
          if (dp[x ^ 1][cur][k + res] == -1 ||
              dp[x ^ 1][cur][k + res] > dp[x][j][k] + cnt) {
            dp[x ^ 1][cur][k + res] = dp[x][j][k] + cnt;
          }
        }
      }
    }
    x ^= 1;
  }
  for (int i = 0; i < n - m + 2; i++) {
    int ans = 1e9;
    for (int j = 0; j <= n; j++) {
      if (dp[x][j][i] != -1) {
        if (ans > dp[x][j][i]) ans = dp[x][j][i];
      }
    }
    if (ans == 1e9) ans = -1;
    printf("%d ", ans);
  }
}
