#include <bits/stdc++.h>
unsigned long long tmp[131073], invn;
int a_[131072];
inline int ksm(unsigned long long a, int b) {
  int ans = 1;
  while (b)
    (b & 1) && (ans = a * ans % 998244353), a = a * a % 998244353, b >>= 1;
  return ans;
}
void init(int n) {
  for (int i = 1; i < n; i++)
    a_[i] = i & 1 ? a_[i ^ 1] | n >> 1 : a_[i >> 1] >> 1;
  for (int i = tmp[0] = 1, j = ksm(3, (998244353 - 1) / n); i <= n; i++)
    tmp[i] = tmp[i - 1] * j % 998244353;
  invn = ksm(n, 998244353 - 2);
}
void ntt(int a[], int n, bool typ) {
  int p;
  for (int i = 1; i < n; i++)
    if (a_[i] < i) p = a[i], a[i] = a[a_[i]], a[a_[i]] = p;
  if (typ)
    for (int i = 1, d = n >> 1; d; i <<= 1, d >>= 1)
      for (int j = 0; j < n; j += i << 1)
        for (int k = 0; k < i; k++)
          p = tmp[n - d * k] * a[i + j + k] % 998244353,
          (a[i + j + k] = a[j + k] + 998244353 - p) >= 998244353 &&
              (a[i + j + k] -= 998244353),
          (a[j + k] += p) >= 998244353 && (a[j + k] -= 998244353);
  else
    for (int i = 1, d = n >> 1; d; i <<= 1, d >>= 1)
      for (int j = 0; j < n; j += i << 1)
        for (int k = 0; k < i; k++)
          p = tmp[d * k] * a[i + j + k] % 998244353,
          (a[i + j + k] = a[j + k] + 998244353 - p) >= 998244353 &&
              (a[i + j + k] -= 998244353),
          (a[j + k] += p) >= 998244353 && (a[j + k] -= 998244353);
  if (typ)
    for (int i = 0; i < n; i++) a[i] = invn * a[i] % 998244353;
}
void getinv(int n, int a[], int b[]) {
  static int tmp[131072];
  memset(b, 0, sizeof(int) * (n << 1));
  b[0] = ksm(a[0], 998244353 - 2);
  for (int i = 1; i < n; i <<= 1) {
    init(i << 2);
    memset(tmp, 0, sizeof(int) * (i << 2));
    memcpy(tmp, a, sizeof(int) * (i << 1));
    ntt(tmp, i << 2, 0);
    ntt(b, i << 2, 0);
    for (int j = 0; j < i << 2; j++)
      b[j] = (1ull * (998244353 - tmp[j]) * b[j] % 998244353 + 2) * b[j] %
             998244353;
    ntt(b, i << 2, 1);
    memset(b + (i << 1), 0, sizeof(int) * (i << 1));
  }
}
int n, m, a[131072], b[131072], d0[131072], d1[131072], len, ans;
void work(int v) {
  if (v == 1) {
    for (int i = 0; i < len; i++) a[i] = 1;
    ans = 1;
    return;
  }
  work(v >> 1);
  memset(d0, 0, sizeof(int) * (len << 1));
  memset(d1, 0, sizeof(int) * (len << 1));
  for (int i = 0; i < len; i++) (i & 1 ? d1 : d0)[i] = a[i];
  if (v & 1) ++d1[1] == 998244353 && (d1[1] = 0);
  memset(a, 0, sizeof(int) * (len << 1));
  for (int i = 0; i < len; i++) a[i] = d1[i] ? 998244353 - d1[i] : 0;
  ++a[0] == 998244353 && (a[0] = 0);
  getinv(len, a, b);
  if (v == m || !(n & 1)) {
    int Ans = 0;
    for (int i = 1; i <= n; i += 2)
      Ans = (1ull * d1[i] * b[n - i] % 998244353 * i + Ans) % 998244353;
    if (!(n & 1))
      ans = (2ull * ans + Ans) % 998244353;
    else
      ans = Ans;
    if (v == m) return;
  }
  init(len << 1);
  ntt(d0, len << 1, 0);
  for (int i = 0; i < len << 1; i++) d0[i] = 1ull * d0[i] * d0[i] % 998244353;
  ntt(d0, len << 1, 1);
  memset(d0 + len, 0, sizeof(int) * len);
  ntt(d0, len << 1, 0);
  ntt(b, len << 1, 0);
  for (int i = 0; i < len << 1; i++) a[i] = 1ull * d0[i] * b[i] % 998244353;
  ntt(a, len << 1, 1);
  for (int i = 1; i < len; i += 2)
    (a[i] += d1[i]) >= 998244353 && (a[i] -= 998244353);
  if (v & 1) a[1] ? a[1]-- : a[1] = 998244353 - 1;
}
int main() {
  scanf("%d%d", &n, &m);
  len = n << 1;
  while (len ^ len & -len) len ^= len & -len;
  work(m);
  printf("%d\n", ans);
}
