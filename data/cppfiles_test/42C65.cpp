#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int Mod = 1e9 + 7;
struct node {
  int a, b, id;
} a[N];
int n, m, x, mx, ans, f[N], s[N];
int Inc(int a, int b) { return (a += b) >= Mod ? a - Mod : a; }
int Dec(int a, int b) { return (a -= b) < 0 ? a + Mod : a; }
int Mul(int a, int b) { return 1ll * a * b % Mod; }
int fpow(int a, int b) {
  int ans = 1;
  for (; b; a = Mul(a, a), b >>= 1)
    if (b & 1) ans = Mul(ans, a);
  return ans;
}
namespace FT {
int c[N];
void reset() { memset(c, 0, sizeof(c)); }
void add(int p, int k) {
  for (int i = p; i <= n * 2; i += (i & (-i))) c[i] = Inc(c[i], k);
}
int qry(int p) {
  int ans = 0;
  for (int i = p; i; i -= (i & (-i))) ans = Inc(ans, c[i]);
  return ans;
}
int query(int l, int r) { return l > r ? 0 : qry(r) - qry(l - 1); }
}  // namespace FT
bool cmp(node a, node b) { return a.a < b.a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].a, &a[i].b), a[i].id = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &x), s[x] = 1, mx = max(mx, a[x].b);
  sort(a + 1, a + n + 1, cmp);
  for (int i = n; i >= 1; --i) {
    f[i] = Inc(FT ::qry(a[i].b), 1);
    FT ::add(a[i].b, f[i]);
  }
  FT ::reset();
  for (int i = 1; i <= n; ++i)
    if (s[a[i].id]) FT ::add(a[i].b, 1);
  for (int i = 1; i <= n; ++i) {
    if (FT ::query(a[i].b, 2 * n)) ans = Inc(ans, f[i]);
    if (s[a[i].id]) FT ::add(a[i].b, -1);
  }
  printf("%d", ans);
  return 0;
}
