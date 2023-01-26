#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
namespace IO {
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char a = getchar();
  for (; !isdigit(a); a = getchar())
    if (a == '-') f = 1;
  for (; isdigit(a); a = getchar()) x = x * 10 + a - '0';
  if (f) x = -x;
}
inline int read() {
  int x;
  read(x);
  return x;
}
inline i64 readll() {
  i64 x;
  read(x);
  return x;
}
}  // namespace IO
using IO ::read;
using IO ::readll;
const int N = 3e5 + 10;
const i64 INF_I = 2e9;
const i64 INF_II = 1e18;
using vi = vector<int>;
int n;
int a[N], b[N];
vector<pair<int, int> > e[N * 5];
int tr[N << 2], tot, bel[N << 2];
void build(int x, int l, int r) {
  tr[x] = ++tot;
  if (l == r) {
    e[tr[x]].push_back({l + b[l], 0});
    bel[tr[x]] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  e[tr[x]].push_back({tr[(x << 1)], 0});
  e[tr[x]].push_back({tr[(x << 1 | 1)], 0});
}
void link(int x, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    e[v].push_back({tr[x], 1});
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) link((x << 1), l, mid, L, R, v);
  if (R > mid) link((x << 1 | 1), mid + 1, r, L, R, v);
}
void solve() {
  n = read();
  for (int i = (0); i <= (n); i++) e[i].clear();
  for (int i = (1); i <= (n); i++) a[i] = read();
  for (int i = (1); i <= (n); i++) b[i] = read();
  tot = n;
  build(1, 1, n);
  for (int i = (n); i >= (1); i--) {
    if (i - a[i] <= 0)
      e[i].push_back({0, 1});
    else {
      link(1, 1, n, i - a[i], i, i);
    }
  }
  static int dis[N * 5], vis[N * 5], pre[N * 5];
  for (int i = (0); i <= (tot); i++) dis[i] = INF_I, vis[i] = 0, pre[i] = -1;
  priority_queue<pair<int, int> > q;
  dis[n] = 0;
  q.push({0, n});
  while (q.size()) {
    int x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto p : e[x]) {
      int y = p.first;
      int w = p.second;
      if (dis[y] > dis[x] + w) {
        dis[y] = dis[x] + w;
        pre[y] = x;
        q.push({-dis[y], y});
      }
    }
  }
  if (dis[0] == INF_I) {
    printf("-1\n");
    for (int i = (0); i <= (tot); i++) e[i].clear();
    return;
  }
  printf("%d\n", dis[0]);
  vector<int> ans;
  int x = 0;
  while (1) {
    if (x == n) break;
    ans.push_back(x);
    x = pre[x];
  }
  for (int i = (ans.size() - 1); i >= (1); i--) {
    if (ans[i] <= n) cout << bel[pre[ans[i]]] << ' ';
  }
  cout << 0 << endl;
  for (int i = (0); i <= (tot); i++) e[i].clear();
}
int main() {
  int Case = 1;
  while (Case--) solve();
  return 0;
}
