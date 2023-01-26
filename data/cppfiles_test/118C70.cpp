#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18), P = 998244353;
int n, d[N], fac[N];
int bp(int x, int y) {
  int r = 1;
  for (; y; y = y >> 1, x = 1ll * x * x % P)
    if (y & 1) r = 1ll * r * x % P;
  return r;
}
void Inc(int& x, int y) {
  if ((x += y) >= P) x -= P;
}
void Dec(int& x, int y) {
  if ((x -= y) < 0) x += P;
}
namespace NTT {
int n, f[N], g[N], w[N], tr[N];
void ntt(int f[], bool o) {
  for (int i = 0; i < n; i++)
    if (tr[i] > i) swap(f[i], f[tr[i]]);
  for (int p = 1; p < n; p = p << 1) {
    w[0] = 1, w[1] = bp(3, (P - 1) / (2 * p));
    if (o) w[1] = bp(w[1], P - 2);
    for (int i = 2; i < p; i++) w[i] = 1ll * w[i - 1] * w[1] % P;
    for (int l = 0; l < n; l += p * 2) {
      for (int t = l; t < l + p; t++) {
        int tmp = 1ll * w[t - l] * f[t + p] % P;
        f[t + p] = f[t] - tmp;
        if (f[t + p] < 0) f[t + p] += P;
        f[t] += tmp;
        if (f[t] >= P) f[t] -= P;
      }
    }
  }
}
vector<int> mul(const vector<int>& a, const vector<int>& b) {
  if (a.size() == 0 || b.size() == 0) return {};
  int t = a.size() + b.size() - 1;
  for (n = 1; n < t; n = n << 1)
    ;
  for (int i = 0; i < n; i++) f[i] = i < a.size() ? a[i] : 0;
  for (int i = 0; i < n; i++) g[i] = i < b.size() ? b[i] : 0;
  for (int i = 1; i < n; i++) tr[i] = (tr[i >> 1] >> 1) + (i & 1 ? n >> 1 : 0);
  ntt(f, 0), ntt(g, 0);
  for (int i = 0; i < n; i++) f[i] = 1ll * f[i] * g[i] % P;
  ntt(f, 1);
  vector<int> res(t);
  int tmp = bp(n, P - 2);
  for (int i = 0; i < t; i++) res[i] = 1ll * f[i] * tmp % P;
  return res;
}
}  // namespace NTT
using NTT::mul;
vector<int> work(int l, int r) {
  if (l == r) return {1, d[l] - (l != 1)};
  int mid = (l + r) >> 1;
  return mul(work(l, mid), work(mid + 1, r));
}
int main() {
  scanf("%d", &n), fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  for (int i = 2, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    d[x]++, d[y]++;
  }
  vector<int> f = work(1, n);
  int ans = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (i & 1)
      Dec(ans, 1ll * f[i] * fac[n - i] % P);
    else
      Inc(ans, 1ll * f[i] * fac[n - i] % P);
  }
  printf("%d", ans);
}
