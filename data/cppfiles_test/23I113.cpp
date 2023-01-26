#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, mod = 998244353;
char s[N][N];
int n, m;
struct pqt {
  int op[N * 4], siz[N * 4], tot, rt;
  vector<int> son[N];
  void init(int x = -1) {
    if (x != -1) n = x;
    tot = n, rt = ++tot;
    for (int i = (1); i <= (n); ++i) son[rt].push_back(i);
  }
  bool vis[N];
  int count[N], ops[N];
  int GV(int x) { return count[x] ? (count[x] == siz[x] ? 2 : 1) : 0; }
  void dfs1(int x) {
    if (x <= n)
      return count[x] = vis[x], siz[x] = 1, ops[x] = vis[x] ? 2 : 1, void();
    count[x] = siz[x] = ops[x] = 0;
    for (int v : son[x])
      dfs1(v), count[x] += count[v], siz[x] += siz[v], ops[x] |= ops[v];
  }
  bool fp[N];
  void flip(int x) {
    if (x > n) reverse(son[x].begin(), son[x].end()), fp[x] ^= 1;
  }
  void push(int x) {
    if (fp[x]) {
      for (int v : son[x]) flip(v);
      fp[x] = false;
    }
  }
  bool isok;
  int dfs2(int x, int lim) {
    if (ops[x] != 3) return x;
    push(x);
    vector<int> a[3];
    for (int v : son[x]) a[GV(v)].push_back(v);
    if (((int)a[1].size()) > 2 || (lim && ((int)a[1].size()) == 2))
      isok = false;
    if (!lim) {
      for (int i = (0); i <= (((int)son[x].size()) - 1); ++i)
        if (count[son[x][i]] == count[x])
          return son[x][i] = dfs2(son[x][i], 0), x;
    }
    if (!op[x]) {
      int ct = -1, rx = -1;
      if (((int)a[2].size()) == 1)
        ct = a[2][0];
      else if (((int)a[2].size()) > 1)
        ct = ++tot, op[ct] = 0, son[ct] = a[2];
      vector<int> t;
      if (((int)a[1].size())) {
        rx = dfs2(a[1][0], 2);
        for (int v : son[rx]) t.push_back(v);
      }
      if (~ct) t.push_back(ct);
      if (((int)a[1].size()) > 1) {
        rx = dfs2(a[1][1], 1);
        for (int v : son[rx]) t.push_back(v);
      }
      int px = t[0];
      if (((int)t.size()) > 1) px = ++tot, son[px] = t, op[px] = 1;
      if (!((int)a[0].size())) return px;
      if (lim) {
        son[x].clear(), op[x] = 1;
        int zer = a[0][0];
        if (((int)a[0].size()) > 1) zer = ++tot, op[zer] = 0, son[zer] = a[0];
        son[x].push_back(zer);
        for (int v : t) son[x].push_back(v);
        if (lim == 1) flip(x);
      } else
        son[x] = a[0], son[x].push_back(px);
    } else {
      int cnt = 0;
      vector<int> t;
      if (GV(son[x][0]) == 2 || GV(son[x][((int)son[x].size()) - 1]) == 0)
        flip(x), push(x);
      for (int v : son[x]) {
        int w = GV(v);
        if (w == 1) {
          if (cnt == 2) isok = false;
          int z = dfs2(v, 3 - (++cnt));
          for (int p : son[z]) t.push_back(p);
        } else if (w == 2) {
          t.push_back(v);
          if (cnt == 0) cnt = 1;
          if (cnt == 2) isok = false;
        } else {
          t.push_back(v);
          if (cnt == 1) cnt = 2;
        }
      }
      if (lim && cnt == 2) isok = false;
      son[x] = t;
      if (lim == 1) flip(x);
    }
    return x;
  }
  bool insert(vector<int> r) {
    for (int i = (1); i <= (n); ++i) vis[i] = false;
    for (const int &x : r) vis[x] = true;
    dfs1(rt), isok = true, rt = dfs2(rt, 0);
    return isok;
  }
  vector<int> ns;
  void output(int x) {
    if (x <= n) return ns.push_back(x), void();
    cout << x << " : " << op[x] << "\n";
    for (int v : son[x]) cout << x << " " << v << "\n";
    for (int v : son[x]) output(v);
  }
  int get(int x) {
    if (x <= n) return 1;
    int res = 1;
    if (op[x] == 0)
      for (int i = (1); i <= (((int)son[x].size())); ++i)
        res = (long long)res * i % mod;
    else
      res = (long long)res * 2 % mod;
    for (int v : son[x]) res = (long long)res * get(v) % mod;
    return res;
  }
} t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  t.init(n);
  while (m--) {
    vector<int> s;
    int q, w;
    cin >> q;
    while (q--) cin >> w, s.push_back(w);
    if (!t.insert(s)) return cout << "0\n", 0;
  }
  cout << t.get(t.rt) << "\n";
  return 0;
}
