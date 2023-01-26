#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)1e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 998244353;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 1000005;
const int MAXV = 1000000;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int n, m, k;
struct Inv {
  int l, r, w;
  bool operator<(const Inv& inv) const { return w < inv.w; }
};
Inv invs[MAXN];
std::vector<int> id[MAXN];
struct Segtree {
  struct Node {
    long long minn, tag;
  };
  Node nodes[MAXN << 2];
  void push_up(int p) {
    nodes[p].minn = std::min(nodes[p << 1].minn, +nodes[p << 1 | 1].minn);
  }
  void propagate(int p, int l, int r) {
    int fa = p >> 1;
    nodes[p].tag += nodes[fa].tag;
    nodes[p].minn += nodes[fa].tag;
  }
  void push_down(int p, int l, int r) {
    if (!nodes[p].tag) return;
    int mid = (l + r) / 2;
    propagate(p << 1, l, mid);
    propagate(p << 1 | 1, mid + 1, r);
    nodes[p].tag = 0;
  }
  void update(int p, int l, int r, int x, int y, long long v) {
    if (x <= l && y >= r) {
      nodes[p].minn += v;
      nodes[p].tag += v;
      return;
    }
    push_down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) update(p << 1, l, mid, x, y, v);
    if (y > mid) update(p << 1 | 1, mid + 1, r, x, y, v);
    push_up(p);
  }
  long long query(int p, int l, int r, int x, int y) {
    if (x > y) return 0;
    if (x <= l && y >= r) {
      return nodes[p].minn;
    }
    push_down(p, l, r);
    int mid = (l + r) / 2;
    long long ans = INF64;
    if (x <= mid) ans = std::min(ans, query(p << 1, l, mid, x, y));
    if (y > mid) ans = std::min(ans, query(p << 1 | 1, mid + 1, r, x, y));
    return ans;
  }
};
Segtree tree;
void solve() {
  scanf("%d%d", &n, &m);
  std::vector<Inv> vs;
  for (int i = 0; i < n; i++) {
    int l, r, w;
    scanf("%d%d%d", &l, &r, &w);
    vs.push_back({l, r, w});
  }
  std::sort(vs.begin(), vs.end());
  int ans = vs[n - 1].w - vs[0].w;
  int l = 0, r = -1;
  while (r < n) {
    while (r + 1 < n) {
      auto& inv = vs[++r];
      tree.update(1, 1, MAXV, inv.l, inv.r, 1);
      if (tree.query(1, 1, MAXV, 1, m) > 0) break;
    }
    if (r == n - 1 || l > r) break;
    ans = std::min(ans, vs[r].w - vs[l].w);
    while (l < r) {
      auto& inv = vs[++l];
      tree.update(1, 1, MAXV, inv.l, inv.r, -1);
      if (tree.query(1, 1, MAXV, 1, m) == 0) {
        break;
      }
      ans = std::min(ans, vs[r].w - vs[l].w);
    }
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
