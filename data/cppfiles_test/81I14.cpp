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
pair<int, int> a[MAXN];
int b[MAXN], buc[MAXN];
int B[MAXN], top;
inline int Hash(int x) { return lower_bound(B + 1, B + top + 1, x) - B; }
int f[MAXN];
vector<pair<int, int> > v[MAXN];
struct qwq {
  pair<int, int> x;
  bool operator<(const qwq &tmp) const { return x.second < tmp.x.second; }
};
multiset<qwq> s;
int main() {
  N = read(), d = read();
  int i, j;
  B[top = 1] = d;
  for (i = 1; i <= N; i++) {
    int x = read(), y = read();
    if (x < d) continue;
    y = max(y, d);
    if (x >= y)
      b[++m] = y, B[++top] = y;
    else
      a[++n] = make_pair(x, y), B[++top] = x, B[++top] = y;
  }
  sort(B + 1, B + top + 1);
  top = unique(B + 1, B + top + 1) - B - 1;
  for (i = 1; i <= n; i++)
    a[i].first = Hash(a[i].first), a[i].second = Hash(a[i].second),
    v[a[i].first].push_back(a[i]), s.insert({a[i]});
  for (i = 1; i <= m; i++) ++buc[Hash(b[i])];
  for (i = 1; i <= top; i++) buc[i] += buc[i - 1];
  f[1] = buc[1];
  for (i = 1; i < top; i++) {
    f[i + 1] = max(f[i + 1], f[i] + buc[i + 1] - buc[i]);
    if (!s.empty()) {
      int to = (*s.begin()).x.second;
      f[to] = max(f[to], f[i] + buc[to] - buc[i] + 1);
    }
    for (auto j : v[i]) s.erase(s.find({j}));
  }
  int ans = 0;
  for (i = 1; i <= top; i++) ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
