#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 1e9 + 7;
int a[N], b[N], id[N], n, nn, m, f[N], dp[N];
bool pd[N];
vector<int> ru[N];
inline int add(int x, int y) { return (x + y >= mod) ? x + y - mod : x + y; }
struct BIT {
  int c[N];
  inline int lowbit(int x) { return x & (-x); }
  inline void upd(int x, int v) {
    for (; x > 0; x -= lowbit(x)) c[x] = max(c[x], v);
  }
  inline int query(int x) {
    int ret = 0;
    for (; x <= nn; x += lowbit(x)) ret = max(ret, c[x]);
    return ret;
  }
  inline void upds(int x, int v) {
    for (; x > 0; x -= lowbit(x)) c[x] = add(c[x], v);
  }
  inline int querys(int x) {
    int ret = 0;
    for (; x <= nn; x += lowbit(x)) ret = add(ret, c[x]);
    return ret;
  }
} T1, T2;
int main() {
  scanf("%d", &n);
  nn = n << 1;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]), id[b[i]] = i;
  scanf("%d", &m);
  for (int i = 1, x; i <= m; ++i) scanf("%d", &x), pd[x] = 1;
  for (int i = 1; i <= nn; ++i) {
    if (!id[i] || !pd[id[i]]) continue;
    int x = id[i];
    int to = id[T1.query(a[x])];
    ru[to].push_back(x);
    T1.upd(a[x], b[x]);
  }
  a[n + 1] = 1;
  ru[id[T1.query(1)]].push_back(n + 1);
  for (int i = 1; i <= nn; ++i) {
    if (!id[i]) continue;
    int x = id[i];
    f[x] = add(T2.querys(a[x]), 1);
    if (pd[x]) {
      dp[x] = add(dp[x], 1);
      for (int v : ru[x]) dp[v] = add(dp[x], T2.querys(a[v]));
    }
    T2.upds(a[x], f[x]);
  }
  printf("%d\n", dp[n + 1]);
  return 0;
}
