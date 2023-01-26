#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, inv2 = 499122177, inv6 = 166374059;
int n, m, f1[150001], f2[150001], f3[150001], s1[150001], s2[150001],
    s3[150001], ans[150001], invf[150001], invv[21], g[21][150001],
    id[21][150001], ff[150001], ss;
inline int add(int a, int b) {
  int c = a + b;
  if (c >= mod) c = c - mod;
  return c;
}
inline int del(int a, int b) {
  int c = a - b;
  if (c < 0) c = c + mod;
  return c;
}
inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b = b >> 1;
  }
  return s;
}
inline int getlen(int a) {
  int s = 0;
  while ((1 << s) < a) s++;
  return s;
}
inline void ntt(int a[], int cnt, bool fl) {
  int len = (1 << cnt);
  for (int i = 0; i < len; i++)
    if (i < id[cnt][i]) swap(a[i], a[id[cnt][i]]);
  for (int k = 1; k <= cnt; k++) {
    int len2 = (1 << k);
    int mid = (1 << (k - 1));
    for (int i = 0; i < len; i = i + len2) {
      for (int j = 0; j < mid; j++) {
        int x = a[i + j];
        int y = mul(a[i + mid + j], g[k][j]);
        a[i + j] = add(x, y);
        a[i + mid + j] = del(x, y);
      }
    }
  }
  if (fl) return;
  for (int i = 0; i < len; i++) a[i] = mul(a[i], invv[cnt]);
  reverse(a + 1, a + len);
}
void inv(int a[], int b[], int len) {
  b[0] = ksm(a[0], mod - 2);
  int cnt = getlen(len) + 1, sum = 2;
  for (int i = 1; i < cnt; i++) {
    for (int j = 0; j < sum; j++) ff[j] = a[j];
    sum = sum << 1;
    ntt(ff, i + 1, 1);
    ntt(b, i + 1, 1);
    for (int j = 0; j < sum; j++) {
      b[j] = del(add(b[j], b[j]), mul(ff[j], mul(b[j], b[j])));
      ff[j] = 0;
    }
    ntt(b, i + 1, 0);
    for (int j = sum >> 1; j < sum; j++) b[j] = 0;
  }
  for (int i = len; i < sum; i++) b[i] = 0;
}
void init() {
  int cnt = getlen(n + n + 2);
  invv[0] = 1;
  g[0][0] = 1;
  for (int i = 1; i <= cnt; i++) {
    int sum = (1 << i), s = (1 << (i - 1));
    g[i][0] = 1;
    g[i][1] = ksm(3, (mod - 1) / sum);
    id[i][1] = s;
    invv[i] = ksm(sum, mod - 2);
    for (int j = 2; j < sum; j++) {
      g[i][j] = mul(g[i][1], g[i][j - 1]);
      if (j & 1)
        id[i][j] = (id[i][j >> 1] >> 1) + s;
      else
        id[i][j] = (id[i][j >> 1] >> 1);
    }
  }
}
int getans1(int a) { return mul(mul(a, add(a, 1)), inv2); }
int getans2(int a) {
  return mul(mul(mul(a, add(a, 1)), add(mul(a, 2), 1)), inv6);
}
void ins(int a) {
  int cnt = getlen(n + n + 2);
  int len = (1 << cnt);
  for (int i = 0; i < len; i++) {
    s1[i] = f1[i];
    s2[i] = f2[i];
    s3[i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    s3[i] = mul(s1[i], i);
    s1[i] = del(0, s1[i]);
  }
  s1[0] = add(s1[0], 1);
  inv(s1, invf, n + 1);
  ntt(invf, cnt, 1);
  ntt(s3, cnt, 1);
  for (int i = 0; i < len; i++) {
    ans[i] = mul(s3[i], invf[i]);
    s3[i] = 0;
    invf[i] = 0;
    s1[i] = 0;
  }
  ntt(ans, cnt, 0);
  for (int i = n + 1; i < len; i++) ans[i] = 0;
  ss = add(ss, mul(ans[n], a));
}
void solve(int a, int c) {
  if (a == 1) {
    f1[1] = 1;
    f2[0] = 1;
    if (!(n & 1)) ss = add(ss, c);
    return;
  }
  solve(a / 2, add(c, c));
  int cnt = getlen(n + n + 2);
  int len = (1 << cnt);
  ntt(f2, cnt, 1);
  for (int i = 0; i < len; i++) f2[i] = mul(f2[i], f2[i]);
  ntt(f2, cnt, 0);
  for (int i = n + 1; i < len; i++) f2[i] = 0;
  for (int i = 0; i <= n; i++) f3[i] = del(0, f1[i]);
  f3[0] = add(f3[0], 1);
  inv(f3, invf, n + 1);
  ntt(f1, cnt, 1);
  ntt(invf, cnt, 1);
  ntt(f2, cnt, 1);
  for (int i = 0; i < len; i++) {
    ans[i] = add(mul(f2[i], invf[i]), f1[i]);
    f2[i] = 0;
    invf[i] = 0;
    f1[i] = 0;
    f3[i] = 0;
  }
  ntt(ans, cnt, 0);
  for (int i = n + 1; i < len; i++) ans[i] = 0;
  ans[0] = 1;
  ans[1] = (a + 1) / 2;
  ans[2] = getans1(a - (a + 1) / 2);
  ans[3] = getans2(a - (a + 1) / 2);
  for (int i = 0; i <= n; i++) {
    if (i & 1)
      f1[i] = ans[i];
    else
      f2[i] = ans[i];
  }
  if (!(n & 1)) ins(c);
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  solve(m, 1);
  if (n & 1) ins(1);
  printf("%d\n", ss);
}
