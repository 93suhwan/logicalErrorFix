#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int P = 998244353;
const int N = 5000 + 10;
struct SEG {
  struct Node {
    int l, r, mx;
  } t[N * N];
  void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    t[p].mx = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build((p << 1 | 1), mid + 1, r);
  }
  void update(int p, int pos, int x) {
    if (t[p].l > pos || t[p].r < pos) return;
    if (t[p].l == t[p].r && t[p].l == pos) {
      t[p].mx = max(t[p].mx, x);
      return;
    }
    update((p << 1), pos, x);
    update((p << 1 | 1), pos, x);
    t[p].mx = max(t[(p << 1)].mx, t[(p << 1 | 1)].mx);
  }
  int query(int p, int l, int r) {
    if (t[p].l > r || t[p].r < l) return 0;
    if (t[p].l >= l && t[p].r <= r) return t[p].mx;
    return max(query((p << 1), l, r), query((p << 1 | 1), l, r));
  }
} seg;
int tot;
struct SAM {
  int last, cnt, ch[N][26], mx[N], prt[N];
  map<int, int> rk[N];
  SAM() { tot = last = cnt = 1; }
  void clear() {
    last = cnt = tot = 1;
    memset(ch, 0, sizeof(ch));
    memset(mx, 0, sizeof(mx));
    memset(prt, 0, sizeof(prt));
    for (int i = 0; i < N; i++) rk[i].clear();
  }
  void add(int c) {
    int p = last, np = ++cnt;
    last = np;
    mx[np] = mx[p] + 1;
    for (; p && !ch[p][c]; p = prt[p]) ch[p][c] = np;
    if (!p)
      prt[np] = 1;
    else {
      int q = ch[p][c];
      if (mx[q] == mx[p] + 1)
        prt[np] = q;
      else {
        int nq = ++cnt;
        mx[nq] = mx[p] + 1;
        prt[nq] = prt[q];
        prt[q] = prt[np] = nq;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        for (; ch[p][c] == q; p = prt[p]) ch[p][c] = nq;
      }
    }
  }
  void dfs(int u, int len) {
    rk[u][len] = tot++;
    for (int i = 0; i < 26; i++) {
      if (ch[u][i]) {
        dfs(ch[u][i], len + 1);
      }
    }
  }
  void solve() {
    clear();
    int n;
    string s;
    cin >> n >> s;
    for (auto i : s) add(i - 'a');
    dfs(1, 0);
    int m = n * (n + 1) / 2;
    seg.build(1, 1, m);
    int ans = 0;
    for (int i = 0, p = 1; i < n; i++) {
      p = 1;
      for (int j = 1; j + i - 1 < n; j++) {
        p = ch[p][s[i + j - 1] - 'a'];
        int r = rk[p][j];
        int f = seg.query(1, 1, r) + 1;
        seg.update(1, r, f);
        ans = max(ans, f);
      }
    }
    cout << ans << '\n';
  }
} sam;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    sam.solve();
  }
  return 0;
}
