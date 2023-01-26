#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ret = 0, t = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') t = -1, c = getchar();
  while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
  return ret * t;
}
const int MAXN = 1001000;
int N, n, m, d;
pair<int, int> a[MAXN], b[MAXN];
int buc[MAXN];
bool cmpb(pair<int, int> x, pair<int, int> y) { return x.first < y.first; }
int B[MAXN], top;
inline int Hash(int x) { return lower_bound(B + 1, B + top + 1, x) - B; }
int f[MAXN], to[MAXN], pre[MAXN];
vector<int> asks[MAXN];
vector<pair<int, int> > v[MAXN];
struct qwq {
  pair<int, int> x;
  bool operator<(const qwq &tmp) const { return x.second < tmp.x.second; }
};
multiset<qwq> s;
namespace BIT {
int t[MAXN];
inline int lowbit(int x) { return x & -x; }
inline int sum(int x) {
  int ret = 0;
  while (x) ret += t[x], x -= lowbit(x);
  return ret;
}
inline void add(int x, int k) {
  while (x <= top) t[x] += k, x += lowbit(x);
}
}  // namespace BIT
int main() {
  N = read(), d = read();
  int i, j;
  B[top = 1] = d;
  for (i = 1; i <= N; i++) {
    int x = read(), y = read();
    if (x < d) continue;
    y = max(y, d);
    B[++top] = x, B[++top] = y;
    if (x >= y)
      b[++m] = make_pair(x, y);
    else
      a[++n] = make_pair(x, y);
  }
  sort(B + 1, B + top + 1);
  top = unique(B + 1, B + top + 1) - B - 1;
  for (i = 1; i <= n; i++)
    a[i].first = Hash(a[i].first), a[i].second = Hash(a[i].second),
    v[a[i].first].push_back(a[i]), s.insert({a[i]});
  for (i = 1; i <= m; i++)
    b[i].first = Hash(b[i].first), b[i].second = Hash(b[i].second);
  for (i = 1; i < top; i++)
    if (!s.empty()) {
      to[i] = (*s.begin()).x.second;
      asks[to[i]].push_back(i);
      for (auto j : v[i]) s.erase(s.find({j}));
    }
  for (i = 1; i <= m; i++) ++buc[b[i].second];
  for (i = 1; i <= top; i++) buc[i] += buc[i - 1];
  sort(b + 1, b + m + 1);
  for (i = top, j = m; i >= 1; i--) {
    while (j && b[j].first == i) BIT::add(b[j].second, 1), --j;
    for (auto k : asks[i])
      pre[k] = (BIT::sum(top) - BIT::sum(k)) - (buc[top] - buc[i]);
  }
  f[1] = buc[1];
  for (i = 1; i < top; i++) {
    f[i + 1] = max(f[i + 1], f[i] + buc[i + 1] - buc[i]);
    f[to[i]] = max(f[to[i]], f[i] + pre[i] + 1);
  }
  int ans = 0;
  for (i = 1; i <= top; i++) ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
