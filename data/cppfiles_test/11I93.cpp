#include <bits/stdc++.h>
const int maxn = 200005, K = 37, mod = 1e9 + 7;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int dec(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int ksm(int a, int b = mod - 2) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
int n, a[maxn];
std::pair<int, int> p[maxn];
int f[maxn], c[maxn], mx, ans;
void ins(int x, int v) {
  for (; x <= mx; x += x & -x) c[x] = std::max(c[x], v);
}
int ask(int x) {
  int res = 0xcfcfcfcf;
  for (; x; x -= x & -x) res = std::max(res, c[x]);
  return res;
}
int main() {
  memset(c, 0xcf, sizeof(c));
  memset(f, 0xcf, sizeof(f));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), p[i] = std::make_pair(i - a[i], a[i]),
                        mx = std::max(mx, a[i]);
  mx++;
  std::sort(p + 1, p + 1 + n);
  ins(1, 0);
  for (int i = 1; i <= n; i++) {
    if (i >= p[i].second) f[i] = ask(p[i].second) + 1;
    ins(p[i].second + 1, f[i]);
    ans = std::max(ans, f[i]);
  }
  printf("%d\n", ans);
  return 0;
}
