#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.2e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
int T, n, m;
int mn[MAXN << 2], tag[MAXN << 2], BIT[MAXN];
long long Ans;
pair<int, int> b[MAXN], a[MAXN];
vector<int> v;
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
void pushup(int x) { mn[x] = min(mn[x << 1], mn[x << 1 | 1]); }
void push(int x, int v) {
  tag[x] += v;
  mn[x] += v;
}
void pushdown(int x) {
  if (tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0;
}
void update(int x, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) return push(x, v), void();
  int mid = (l + r) >> 1;
  pushdown(x);
  if (L <= mid) update(x << 1, l, mid, L, R, v);
  if (R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
  pushup(x);
}
void add(int x, int v) {
  for (; x <= n; x += ((x) & (-(x)))) BIT[x] += v;
}
int ask(int x) {
  int res = 0;
  for (; x; x -= ((x) & (-(x)))) res += BIT[x];
  return res;
}
void build(int x, int l, int r) {
  mn[x] = tag[x] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
}
void solve() {
  read(n), read(m);
  Ans = 0;
  build(1, 1, n + 1);
  v.clear();
  memset(BIT, 0, sizeof(int) * (n + 5));
  for (int i = 1; i <= n; ++i)
    read(a[i].first), a[i].second = i, v.push_back(a[i].first);
  for (int i = 1; i <= m; ++i) read(b[i].first), b[i].second = i;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = n, x; i >= 1; --i) {
    x = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
    Ans += ask(x - 1);
    add(x, 1);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; ++i) update(1, 1, n + 1, i + 1, n + 1, 1);
  for (int L = 1, R, l = 1, r; L <= m; L = R + 1) {
    R = L, r = l;
    while (r <= n && a[r].first < b[L].first) {
      update(1, 1, n + 1, a[r].second + 1, n + 1, -1);
      update(1, 1, n + 1, 1, a[r].second, 1);
      ++r;
    }
    l = r;
    while (r <= n && a[r].first == b[L].first) {
      update(1, 1, n + 1, a[r].second + 1, n + 1, -1);
      ++r;
    }
    while (R < m && b[R + 1].first == b[L].first) R++;
    Ans += 1ll * (R - L + 1) * mn[1];
    for (int i = l; i < r; ++i) update(1, 1, n + 1, 1, a[i].second, 1);
    l = r;
  }
  printf("%lld\n", Ans);
}
signed main() {
  read(T);
  while (T--) solve();
  return 0;
}
