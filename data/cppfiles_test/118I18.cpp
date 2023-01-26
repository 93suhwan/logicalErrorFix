#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
const int Maxn = 250010;
const int maxn = 250010 * 2;
const long long mod = 998244353, G = 3, Gi = 332748118;
long long fac[Maxn];
int n;
long long a[Maxn];
long long aa[maxn], bb[maxn], cc[maxn];
int r[maxn];
int limit = 1, L;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void NTT(long long *A, int type) {
  for (int i = 0; i < limit; i++)
    if (i < r[i]) swap(A[i], A[r[i]]);
  for (int mid = 1; mid < limit; mid <<= 1) {
    long long Wn = ksm(type == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j < limit; j += (mid << 1)) {
      long long w = 1;
      for (int k = 0; k < mid; k++, w = (w * Wn) % mod) {
        int x = A[j + k], y = w * A[j + k + mid] % mod;
        A[j + k] = (x + y) % mod, A[j + k + mid] = (x - y + mod) % mod;
      }
    }
  }
}
void NTT_mul(long long *x, long long *y, long long *z, int n, int m) {
  limit = 1;
  L = 0;
  while (limit <= n + m) limit <<= 1, L++;
  for (int i = 0; i < limit; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
  for (int i = n + 1; i < limit; i++) x[i] = 0;
  for (int i = m + 1; i < limit; i++) y[i] = 0;
  NTT(x, 1);
  NTT(y, 1);
  for (int i = 0; i < limit; i++) z[i] = x[i] * y[i] % mod;
  NTT(z, -1);
  long long inv = ksm(limit, mod - 2);
  for (int i = 0; i < limit; i++) z[i] = z[i] * inv % mod;
}
vector<long long> binary(int l, int r) {
  vector<long long> ans;
  if (l == r) {
    ans.push_back(1);
    ans.push_back(a[l]);
    return ans;
  }
  int m = (l + r) >> 1;
  vector<long long> res1 = binary(l, m);
  vector<long long> res2 = binary(m + 1, r);
  for (int i = 0; i <= m - l + 1; i++) aa[i] = res1[i];
  for (int i = 0; i <= r - m; i++) bb[i] = res2[i];
  NTT_mul(aa, bb, cc, m - l + 1, r - m);
  for (int i = 0; i <= r - l + 1; i++) ans.push_back(cc[i]);
  return ans;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 250000; i++) fac[i] = fac[i - 1] * i % Mod;
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    a[u]++, a[v]++;
  }
  for (int i = 2; i <= n; i++) a[i]--;
  vector<long long> res = binary(1, n);
  long long ans = 0;
  int x = 1;
  for (int i = 1; i <= n; i++) {
    (ans += res[i - 1] * fac[n + 1 - i] * x) %= Mod;
    x *= -1;
  }
  printf("%lld", ans);
  return 0;
}
