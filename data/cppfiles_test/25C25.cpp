#include <bits/stdc++.h>
using namespace std;
inline int M(int x) { return (x >= 998244353) ? (x - 998244353) : x; }
inline int M1(int x) { return (x < 0) ? (x + 998244353) : x; }
inline int ksm(int p, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * p % 998244353;
    k >>= 1;
    p = 1ll * p * p % 998244353;
  }
  return res;
}
int wn[262145], rev[262145 << 1];
inline void Make(int u) {
  int i, j, w, len = 1;
  while (len <= u) len <<= 1;
  for (i = 1; i < len; i <<= 1) {
    w = ksm(3, (998244353 - 1) / (i << 1));
    wn[i] = 1;
    for (j = 1; j < i; j++) wn[i + j] = 1ll * wn[i + j - 1] * w % 998244353;
  }
  for (i = 1; i <= len; i <<= 1)
    for (j = 0; j < i; j++)
      rev[i + j] = (rev[i + (j >> 1)] >> 1) | ((j & 1) * (i >> 1));
}
inline void NTT(int deal[], int len, int opt) {
  int i, j, k, x, y;
  for (i = 0; i < len; i++)
    if (i > rev[len + i]) swap(deal[i], deal[rev[len + i]]);
  for (i = 1; i < len; i <<= 1)
    for (j = 0; j < len; j += (i << 1))
      for (k = 0; k < i; k++)
        x = deal[j + k], y = 1ll * wn[i + k] * deal[i + j + k] % 998244353,
        deal[j + k] = M(x + y), deal[i + j + k] = M1(x - y);
  if (!opt) {
    int inv = 998244353 - (998244353 / len);
    for (i = 0; i < len; i++) deal[i] = 1ll * deal[i] * inv % 998244353;
    reverse(deal + 1, deal + len);
  }
}
inline int Getl(int u) {
  int len = 1;
  while (len <= u) len <<= 1;
  return len;
}
int fac[262145], inv[262145], I[262145], t1[262145], t2[262145], t3[262145],
    t4[262145];
void INV(int *A, int *B, int n) {
  if (n == 1) {
    B[0] = ksm(A[0], 998244353 - 2);
    return;
  }
  int i, mid = (n + 1) >> 1, l1 = Getl(mid - 1 + n - 1), l2 = Getl(n - 1);
  INV(A, B, mid);
  if (51 * l1 < 80 * l2) {
    memcpy(t1, A, sizeof(int) * n);
    memcpy(t2, B, sizeof(int) * mid);
    NTT(t1, l1, 1);
    NTT(t2, l1, 1);
    for (i = 0; i < l1; i++)
      t1[i] = M1(-1ll * t2[i] * t1[i] % 998244353 * t2[i] % 998244353);
    NTT(t1, l1, 0);
    memcpy(B + mid, t1 + mid, sizeof(int) * (n - mid));
    memset(t1, 0, sizeof(int) * l1);
    memset(t2, 0, sizeof(int) * l1);
  } else {
    memcpy(t1, A, sizeof(int) * n);
    memcpy(t2, B, sizeof(int) * mid);
    NTT(t1, l2, 1);
    NTT(t2, l2, 1);
    for (i = 0; i < l2; i++) t1[i] = M1(-1ll * t1[i] * t2[i] % 998244353);
    NTT(t1, l2, 0);
    memset(t1, 0, sizeof(int) * mid);
    NTT(t1, l2, 1);
    for (i = 0; i < l2; i++) t1[i] = 1ll * t1[i] * t2[i] % 998244353;
    NTT(t1, l2, 0);
    memcpy(B + mid, t1 + mid, sizeof(int) * (n - mid));
    memset(t1, 0, sizeof(int) * l2);
    memset(t2, 0, sizeof(int) * l2);
  }
}
inline void Der(int *A, int *B, int n) {
  for (int i = 1; i < n; i++) B[i - 1] = 1ll * i * A[i] % 998244353;
  B[n - 1] = 0;
}
inline void Int(int *A, int *B, int n) {
  B[0] = 0;
  for (int i = 0; i < n - 1; i++) B[i + 1] = 1ll * A[i] * I[i + 1] % 998244353;
}
int n, m, hf, f[262145], g[262145], ls[262145], fr[262145];
inline void LNH(int *A, int *B, int n) {
  for (int i = 0; i <= n; i++) t3[i] = 1ll * A[i] * (m - i) % 998244353;
  INV(A, t4, n);
  int i, len = Getl(n - 1 + n - 1);
  NTT(t3, len, 1);
  NTT(t4, len, 1);
  for (i = 0; i < len; i++) B[i] = 1ll * t3[i] * t4[i] % 998244353;
  NTT(B, len, 0);
  memset(t3, 0, sizeof(int) * len);
  memset(t4, 0, sizeof(int) * len);
}
inline int dwk(int x, int k) {
  return 1ll * fr[x - hf] * ls[k - (x - hf)] % 998244353;
}
inline int sg(int x) {
  x = (x >> 1) + x;
  return (x & 1) ? (998244353 - 1) : 1;
}
int main() {
  Make(200000);
  fac[0] = 1;
  for (int i = 1; i < 262145; i++) fac[i] = 1ll * fac[i - 1] * i % 998244353;
  inv[262145 - 1] = ksm(fac[262145 - 1], 998244353 - 2);
  for (int i = 262145 - 2; i >= 0; i--)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % 998244353;
  scanf("%d%d", &n, &m);
  hf = m >> 1;
  int i;
  fr[0] = ls[0] = 1;
  for (i = 1; i <= n; i++)
    ls[i] = 1ll * ls[i - 1] * (hf - i + 1) % 998244353,
    fr[i] = 1ll * fr[i - 1] * (hf + i) % 998244353;
  if (m & 1) {
    for (i = 0; i <= n; i++)
      f[i] = 1ll *
             ((i & 1)
                  ? (1ll * inv[i] * dwk(hf + ((i - 1) >> 1) + 1, i) % 998244353)
                  : (1ll * inv[i] * dwk(hf + (i >> 1), i) % 998244353) %
                        998244353) *
             sg(i) % 998244353;
  } else {
    for (i = 0; i <= n; i++)
      f[i] = 1ll *
             ((i & 1) ? (1ll * inv[i] * dwk(hf + ((i - 1) >> 1), i) % 998244353)
                      : (1ll * inv[i] * dwk(hf + (i >> 1), i) % 998244353) %
                            998244353) *
             sg(i) % 998244353;
  }
  LNH(f, g, n + 1);
  printf("%d", g[n]);
  return 0;
}
