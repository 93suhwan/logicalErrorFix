#include <bits/stdc++.h>
using namespace std;
const int N = 305;
struct FenwickTree {
  int c[N];
  inline int lb(int x) { return x & -x; }
  void add(int x, int d) {
    for (; x < N; x += lb(x)) c[x] += d;
  }
  int getsum(int x) {
    int r = 0;
    for (; x; x -= lb(x)) r += c[x];
    return r;
  }
} t[N];
int n, m, sz;
struct person {
  int a, id, s;
} p[N * N], q[N * N];
int row(int i) { return (i + m - 1) / m; }
int col(int i) { return i - (row(i) - 1) * m; }
void solve(int Case) {
  scanf("%d %d", &n, &m);
  sz = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &p[++sz].a);
      p[sz].id = sz;
      q[sz] = p[sz];
    }
  }
  sort(q + 1, q + 1 + n * m, [&](person x, person y) {
    if (x.a != y.a) return x.a < y.a;
    return x.id < y.id;
  });
  for (int i = 1; i <= n * m; ++i) {
    int j = i;
    while (j + 1 <= n * m && q[j + 1].a == q[i].a) ++j;
    ;
    vector<int> pos;
    for (int k = i; k <= j; ++k) pos.push_back(k);
    sort(pos.begin(), pos.end(), [](int i, int j) { return col(i) > col(j); });
    for (int k = i; k <= j; ++k) p[q[k].id].s = pos[k - i];
    i = j;
  }
  int ans = 0;
  for (int i = 1; i <= n * m; ++i) {
    int x = row(p[i].s);
    int y = col(p[i].s);
    ans += t[x].getsum(y);
    t[x].add(y, 1);
    ;
  }
  for (int i = 1; i <= n * m; ++i) {
    int x = row(p[i].s);
    int y = col(p[i].s);
    t[x].add(y, -1);
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) solve(t);
  return 0;
}
