#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 750000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
struct LCT {
  int fa[maxn + 5], son[maxn + 5][2];
  int val[maxn + 5], sum[maxn + 5], lz[maxn + 5];
  int isedge[maxn + 5], sum_is[maxn + 5];
  bool rev[maxn + 5];
  void init(int n, int m) {
    for (auto i = 1; i <= n; i++) fa[i] = son[i][0] = son[i][1] = 0;
    for (auto i = 1; i <= n; i++) rev[i] = 0, lz[i] = -1;
    for (auto i = 1; i <= n; i++) val[i] = sum[i] = 0;
    for (auto i = 1; i <= n; i++) isedge[i] = sum_is[i] = i > m;
  }
  void pushup(int x) {
    sum_is[x] = isedge[x] | sum_is[son[x][0]] | sum_is[son[x][1]];
    sum[x] = val[x] | sum[son[x][0]] | sum[son[x][1]];
  }
  void push_rev(int x) {
    if (!x) return;
    rev[x] ^= 1;
    swap(son[x][0], son[x][1]);
  }
  void push_lz(int x, int y) {
    if (!x) return;
    lz[x] = y;
    if (isedge[x]) val[x] = y;
    if (sum_is[x]) sum[x] = y;
  }
  bool isrt(int x) { return son[fa[x]][0] != x && son[fa[x]][1] != x; }
  void pushdown(int x) {
    if (rev[x]) {
      push_rev(son[x][0]);
      push_rev(son[x][1]);
      rev[x] = 0;
    }
    if (lz[x] != -1) {
      push_lz(son[x][0], lz[x]);
      push_lz(son[x][1], lz[x]);
      lz[x] = -1;
    }
  }
  void rot(int x) {
    int y = fa[x], z = fa[y];
    int l = son[y][1] == x, r = l ^ 1;
    if (!isrt(y)) son[z][son[z][1] == y] = x;
    fa[son[x][r]] = y;
    fa[y] = x;
    fa[x] = z;
    son[y][l] = son[x][r];
    son[x][r] = y;
    pushup(y);
  }
  stack<int> sta;
  void splay(int x) {
    sta.push(x);
    for (int i = x; !isrt(i); i = fa[i]) sta.push(fa[i]);
    while ((int)sta.size()) pushdown(sta.top()), sta.pop();
    while (!isrt(x)) {
      int y = fa[x], z = fa[y];
      if (!isrt(y)) {
        if ((son[y][0] == x) ^ (son[z][0] == y))
          rot(x);
        else
          rot(y);
      }
      rot(x);
    }
    pushup(x);
  }
  void access(int x) {
    for (int l = 0; x; l = x, x = fa[x]) {
      splay(x);
      son[x][1] = l;
      pushup(x);
    }
  }
  int findrt(int x) {
    access(x);
    splay(x);
    while (son[x][0]) pushdown(x), x = son[x][0];
    return x;
  }
  void reroot(int x) {
    access(x);
    splay(x);
    push_rev(x);
  }
  void link(int x, int y) {
    reroot(x);
    fa[x] = y;
  }
  void cut(int x, int y) {
    reroot(x);
    access(y);
    splay(y);
    int l = son[y][0];
    son[y][0] = fa[l] = 0;
    pushup(y);
  }
  void demo(int n) {
    for (auto i = 1; i <= n; i++)
      if (0) puts("No effect.");
  }
} lct;
pii ed[maxn + 5];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  lct.init(n + m, n);
  int j = 1;
  ll ans = 0;
  for (auto i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed[i] = {u, v};
    while (lct.findrt(u) == lct.findrt(v)) {
      if (0) puts("No effect.");
      lct.reroot(u);
      lct.access(v);
      lct.splay(v);
      if (0) puts("No effect.");
      if (lct.sum[v] == 0) break;
      auto [x, y] = ed[j];
      int e = j + n;
      lct.reroot(x);
      lct.access(y);
      lct.splay(e);
      int j2 = lct.val[e];
      lct.demo(n + m);
      if (j2) {
        auto [a, b] = ed[j2];
        lct.reroot(a);
        lct.access(b);
        lct.splay(b);
        lct.push_lz(b, 0);
      }
      lct.cut(e, x);
      lct.cut(e, y);
      if (j2) {
        int f = j2 + n;
        lct.link(f, ed[j2].first);
        lct.link(f, ed[j2].second);
      }
      j++;
    }
    if (0) puts("No effect.");
    if (lct.findrt(u) == lct.findrt(v)) {
      lct.reroot(u);
      lct.access(v);
      lct.splay(v);
      lct.push_lz(v, i);
    } else {
      lct.link(i + n, u);
      lct.link(i + n, v);
    }
    ans += i - j + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
