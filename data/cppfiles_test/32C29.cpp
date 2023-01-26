#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
using namespace std;
const long long mod = 998244353, g = 3, ginv = 332748118, N = 4e5 + 10,
                inv2 = 499122177;
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) (ans *= x) %= mod;
    (x *= x) %= mod;
    y >>= 1;
  }
  return ans;
}
long long rr[N];
long long gg[N], gginv[N], lim[N];
long long cnt;
vector<long long> NTT(vector<long long> a, long long limit, long long type) {
  for (long long i = 0; i < limit; i++)
    if (rr[i] < i) swap(a[rr[i]], a[i]);
  for (long long mid = 1; mid < limit; mid <<= 1) {
    long long wn = type == 1 ? gg[mid << 1] : gginv[mid << 1];
    for (long long j = 0; j < limit; j += (mid << 1)) {
      long long w = 1;
      for (long long k = 0; k < mid; k++, (w *= wn) %= mod) {
        cnt++;
        long long x = a[j + k], y = w * a[j + k + mid] % mod;
        a[j + k] = (x + y) % mod;
        a[j + k + mid] = (x - y + mod) % mod;
      }
    }
  }
  if (~type) return a;
  for (long long i = 0; i < limit; i++) (a[i] *= lim[limit]) %= mod;
  return a;
}
vector<long long> add(vector<long long> a, vector<long long> b) {
  long long n = a.size(), m = b.size();
  while (n < m) a.push_back(0), n++;
  while (n > m) b.push_back(0), m++;
  for (long long i = 0; i < n; i++) (a[i] += b[i]) %= mod;
  return a;
}
vector<long long> add_(vector<long long> a, vector<long long> b) {
  long long n = a.size(), m = b.size();
  while (n < m) a.push_back(0), n++;
  while (n > m) b.push_back(0), m++;
  for (long long i = 0; i < n - 1; i++) (a[i] += b[i + 1]) %= mod;
  return a;
}
vector<long long> div(vector<long long> a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) (a[i] *= inv2) %= mod;
  return a;
}
vector<long long> mul(vector<long long> a, long long x) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) (a[i] *= x) %= mod;
  return a;
}
struct zj {
  vector<long long> a[2][2];
  zj() {
    a[0][0].push_back(0), a[0][1].push_back(0), a[1][0].push_back(0),
        a[1][1].push_back(0);
  }
};
long long n, a[N], b[N], m;
vector<long long> mul(vector<long long> a, vector<long long> b) {
  long long limit = 1, l = 0, n = a.size(), m = b.size();
  while (limit <= n + m) limit <<= 1, l++;
  for (long long i = 0; i < limit; i++)
    rr[i] = (rr[i >> 1] >> 1) | ((i & 1) << (l - 1));
  while (n < limit) a.push_back(0), n++;
  while (m < limit) b.push_back(0), m++;
  a = NTT(a, limit, 1);
  b = NTT(b, limit, 1);
  for (long long i = 0; i < limit; i++) (a[i] *= b[i]) %= mod;
  a = NTT(a, limit, -1);
  while (a.size() > 1 && a[a.size() - 1] == 0) a.pop_back();
  return a;
}
vector<long long> mul_(vector<long long> a, vector<long long> b) {
  long long n = a.size(), m = b.size();
  while (n < m) a.push_back(0), n++;
  while (n > m) b.push_back(0), m++;
  for (long long i = 0; i < n; i++) (a[i] *= b[i]) %= mod;
  return a;
}
zj merge(long long l, long long r) {
  if (l == r) {
    zj x;
    if (a[l] == 1)
      x.a[0][0].push_back(1);
    else
      x.a[1][1].push_back(2);
    return x;
  }
  long long mid = (l + r) >> 1;
  zj x = merge(l, mid), y = merge(mid + 1, r);
  zj tmp, tmpp;
  if (l + 1 == r) {
    for (long long i = 0; i < 2; i++)
      for (long long j = 0; j < 2; j++)
        for (long long ii = 0; ii < 2; ii++)
          for (long long jj = 0; jj < 2; jj++)
            tmp.a[i][j] = add(tmp.a[i][j], mul(x.a[i][ii], y.a[jj][j]));
    for (long long i = 0; i < 2; i++)
      for (long long j = 0; j < 2; j++)
        for (long long ii = 0; ii < 2; ii++)
          for (long long jj = 0; jj < 2; jj++)
            if (ii != jj)
              tmp.a[1][1] = add_(tmp.a[1][1], mul(x.a[i][ii], y.a[jj][j]));
            else if (!ii)
              tmp.a[1][1] =
                  add_(tmp.a[1][1], mul(mul(x.a[i][ii], y.a[jj][j]), 2));
            else
              tmp.a[1][1] = add_(tmp.a[1][1], div(mul(x.a[i][ii], y.a[jj][j])));
    return tmp;
  } else if (l + 2 == r) {
    for (long long i = 0; i < 2; i++)
      for (long long j = 0; j < 2; j++)
        for (long long ii = 0; ii < 2; ii++)
          for (long long jj = 0; jj < 2; jj++)
            tmp.a[i][j] = add(tmp.a[i][j], mul(x.a[i][ii], y.a[jj][j]));
    for (long long i = 0; i < 2; i++)
      for (long long j = 0; j < 2; j++)
        for (long long ii = 0; ii < 2; ii++)
          for (long long jj = 0; jj < 2; jj++)
            if (ii != jj)
              tmp.a[i][1] = add_(tmp.a[i][1], mul(x.a[i][ii], y.a[jj][j]));
            else if (!ii)
              tmp.a[i][1] =
                  add_(tmp.a[i][1], mul(mul(x.a[i][ii], y.a[jj][j]), 2));
            else
              tmp.a[i][1] = add_(tmp.a[i][1], div(mul(x.a[i][ii], y.a[jj][j])));
    return tmp;
  }
  long long limit = 1, llll = 0, lena = 0, lenb = 0;
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      lena = max(lena, (long long)x.a[i][j].size());
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      lenb = max(lenb, (long long)y.a[i][j].size());
  while (limit <= lena + lenb) limit <<= 1, llll++;
  for (long long i = 0; i < limit; i++)
    rr[i] = (rr[i >> 1] >> 1) | ((i & 1) << (llll - 1));
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      while (x.a[i][j].size() < limit) x.a[i][j].push_back(0);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      while (y.a[i][j].size() < limit) y.a[i][j].push_back(0);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      while (tmp.a[i][j].size() < limit) tmp.a[i][j].push_back(0);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      while (tmpp.a[i][j].size() < limit) tmpp.a[i][j].push_back(0);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) x.a[i][j] = NTT(x.a[i][j], limit, 1);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) y.a[i][j] = NTT(y.a[i][j], limit, 1);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      for (long long ii = 0; ii < 2; ii++)
        for (long long jj = 0; jj < 2; jj++)
          tmp.a[i][j] = add(tmp.a[i][j], mul_(x.a[i][ii], y.a[jj][j]));
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      for (long long ii = 0; ii < 2; ii++)
        for (long long jj = 0; jj < 2; jj++)
          if (ii != jj)
            tmpp.a[i][j] = add(tmpp.a[i][j], mul_(x.a[i][ii], y.a[jj][j]));
          else if (!ii)
            tmpp.a[i][j] =
                add(tmpp.a[i][j], mul(mul_(x.a[i][ii], y.a[jj][j]), 2));
          else
            tmpp.a[i][j] = add(tmpp.a[i][j], div(mul_(x.a[i][ii], y.a[jj][j])));
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) tmp.a[i][j] = NTT(tmp.a[i][j], limit, -1);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      tmpp.a[i][j] = NTT(tmpp.a[i][j], limit, -1);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      tmp.a[i][j] = add_(tmp.a[i][j], tmpp.a[i][j]);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      while (tmp.a[i][j].size() > 1 && tmp.a[i][j][tmp.a[i][j].size() - 1] == 0)
        tmp.a[i][j].pop_back();
  return tmp;
}
signed main() {
  scanf("%lld", &m);
  for (long long mid = 1; mid < N; mid <<= 1)
    gg[mid] = qpow(g, (mod - 1) / mid),
    gginv[mid] = qpow(ginv, (mod - 1) / mid), lim[mid] = qpow(mid, mod - 2);
  for (long long i = 1; i <= m; i++) scanf("%lld", &b[i]);
  for (long long i = 1; i <= m;) {
    a[++n] = b[i];
    for (long long j = 0; j < b[i]; j++) {
      if (i + j > m) return printf("0\n"), 0;
      if (b[i + j] != b[i]) return printf("0\n"), 0;
    }
    i = i + b[i];
  }
  zj ans = merge(1, n);
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) {
      while (ans.a[i][j].size() <= n + 1) ans.a[i][j].push_back(0);
    }
  for (long long i = 1; i <= n; i++)
    (ans.a[0][0][i] += ans.a[0][1][i] + ans.a[1][0][i] + ans.a[1][1][i]) %= mod;
  long long now = 1, ANS = 0;
  for (long long i = 1; i <= n; i++) {
    (now *= i) %= mod;
    (ANS += ((n - i + 1) & 1 ? 1 : -1) * now * ans.a[0][0][i] % mod) %= mod;
    (ANS += mod) %= mod;
  }
  return printf("%lld", ANS), 0;
}
