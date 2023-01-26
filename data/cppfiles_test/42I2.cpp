#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, l[200015], r[200015], p[200015], val[200015];
bool is[200015];
namespace fenwick {
int D[200015 << 1];
void add(int p, int v) {
  for (; p <= (n << 1); p += ((p) & (-p))) (D[p] += v) %= mod;
}
int query(int p) {
  int res = 0;
  for (; p; p -= ((p) & (-p))) (res += D[p]) %= mod;
  return res;
}
}  // namespace fenwick
using namespace fenwick;
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d%d", &l[i], &r[i]);
  for (int i = (1); i <= (n); i++) p[i] = i;
  sort(p + 1, p + n + 1, [&](int u, int v) { return r[u] < r[v]; });
  int t, tt;
  scanf("%d", &t);
  for (int i = (1); i <= (t); i++) scanf("%d", &tt), is[tt] = 1;
  for (int i = (1); i <= (n); i++) {
    int u = p[i];
    val[u] = query(r[u]) - query(l[u]) + 1;
    add(l[u], val[u]);
  }
  int L = 1, ans = 0;
  for (int i = (n); i >= (1); i--) {
    int u = p[i];
    if (is[u] && L <= l[u]) {
      (ans += query(l[u]) - query(L - 1)) %= mod;
      L = l[u] + 1;
    }
    add(l[u], mod - val[u]);
  }
  printf("%d\n", ans);
  return 0;
}
