#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 9;
const int SZ = N * 2;
const int sigma = 26;
char s[N];
int cur, rk[N][N];
int tot, last, nxt[SZ][sigma], len[SZ], link[SZ];
vector<int> ch[SZ], pos[SZ];
bool cmp(int u, int v) {
  return s[pos[u][0] + len[link[u]]] < s[pos[v][0] + len[link[v]]];
}
template <int N, int sigma>
struct Suffix_Automaton {
  void init(int n) {
    tot = last = 0;
    link[0] = -1;
    memset(nxt, 0, (n * 2 + 5) * sigma * sizeof(int));
    for (int i = 0; i < n * 2 + 5; ++i) {
      ch[i].clear();
      pos[i].clear();
    }
  }
  void add_char(int c) {
    int p = last, cur = last = ++tot;
    len[cur] = len[p] + 1;
    while (~p && !nxt[p][c]) {
      nxt[p][c] = cur;
      p = link[p];
    }
    if (p == -1) {
      link[cur] = 0;
      return;
    }
    int q = nxt[p][c];
    if (len[q] == len[p] + 1) {
      link[cur] = q;
      return;
    }
    int _q = ++tot;
    len[_q] = len[p] + 1;
    memcpy(nxt[_q], nxt[q], sigma * sizeof(int));
    link[_q] = link[q];
    link[q] = link[cur] = _q;
    while (~p && nxt[p][c] == q) {
      nxt[p][c] = _q;
      p = link[p];
    }
  }
  void dfs(int u) {
    for (int v : ch[u]) {
      dfs(v);
      for (int p : pos[v]) pos[u].push_back(p);
    }
  }
  void dfs2(int u) {
    sort(ch[u].begin(), ch[u].end(), cmp);
    int s = len[link[u]], t = len[u];
    for (int p : pos[u]) {
      for (int d = s; d < t; ++d) {
        rk[p][p + d] = cur + d - s;
      }
    }
    cur += t - s;
    for (int v : ch[u]) dfs2(v);
  }
  void add_string(char s[], int n) {
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) {
      add_char(s[i] - 'a');
      pos[last].push_back(n - i + 1);
    }
    for (int i = 1; i <= tot; ++i) {
      ch[link[i]].push_back(i);
    }
    reverse(s + 1, s + n + 1);
    dfs(0);
    cur = 1;
    dfs2(0);
  }
};
Suffix_Automaton<N * 2, 26> sam;
struct BIT {
  int n, maxv[N * N];
  void init(int _n) {
    n = _n;
    memset(maxv, 0, (n + 5) * sizeof(*maxv));
  }
  void upd(int p, int k) {
    for (; p <= n; p += p & -p) maxv[p] = max(maxv[p], k);
  }
  int q(int p) {
    int r = 0;
    for (; p; p -= p & -p) r = max(r, maxv[p]);
    return r;
  }
} bit;
void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  sam.init(n);
  sam.add_string(s, n);
  bit.init(cur);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int p = rk[i][j];
      int r = bit.q(p - 1);
      bit.upd(p, r + 1);
    }
  }
  int ans = bit.q(cur);
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
