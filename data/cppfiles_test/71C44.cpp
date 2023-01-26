#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long res = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res * flag;
}
void print(pair<long long, long long> A) {
  cerr << A.first << ' ' << A.second << "XXX\n";
}
const long long N = 2e5 + 20;
long long D(pair<long long, long long> A, pair<long long, long long> B) {
  return (A.first - B.first) * (A.first - B.first) +
         (A.second - B.second) * (A.second - B.second);
}
long double sqr(long double A) { return sqrt(A); }
const long double eps = 1e-8;
long long cmp(long double a, long double b) {
  if (fabs(a - b) <= eps) return 0;
  return a < b ? -1 : 1;
}
pair<long long, long long> a[N], te;
long long n, s;
long long D(long long A, long long B) { return D(a[A], a[B]); }
mt19937 rnd(time(0));
bool isl(long long ie[3]) {
  long double d[3];
  long long ct = -1;
  for (long long i = (0), stOxrj = (2); i <= stOxrj; ++i)
    for (long long j = (i + 1), stOxrj = (2); j <= stOxrj; ++j)
      d[++ct] = sqr(D(a[ie[i]], a[ie[j]]));
  sort(d, d + 3);
  return !cmp(d[0] + d[1], d[2]);
}
long long nd[10][10], isg[N];
vector<long long> guan;
signed main() {
  n = read();
  s = read();
  for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
    a[i].first = read(), a[i].second = read();
  te = a[s];
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  if (n <= 2) {
    printf("%.10Lf\n", sqr(D(a[1], a[n])));
    return 0;
  }
  if (n <= 3) {
    for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
      if (te == a[i]) s = i;
    long double ans = 1e18;
    for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
      if (i != s) ans = min(ans, sqr(D(a[i], a[s])));
    for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
      for (long long j = (i + 1), stOxrj = (n); j <= stOxrj; ++j)
        if (i != s && j != s) ans += sqr(D(a[i], a[j]));
    printf("%.10Lf\n", ans);
    return 0;
  }
  long long ie[3];
  while (1) {
    for (long long i = (0), stOxrj = (2); i <= stOxrj; ++i)
      ie[i] = rnd() % n + 1;
    long long flg = 0;
    for (long long i = (0), stOxrj = (2); i <= stOxrj; ++i)
      for (long long j = (i + 1), stOxrj = (2); j <= stOxrj; ++j)
        if (ie[i] == ie[j]) flg = 1;
    if (flg) continue;
    if (isl(ie)) break;
  }
  for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i) {
    ie[2] = i;
    if (!isl(ie)) {
      swap(a[i], a[n]);
      break;
    }
  }
  sort(a + 1, a + n);
  for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
    if (te == a[i]) s = i;
  isg[s] = isg[1] = isg[n - 1] = isg[n] = 1;
  long long whe = 0, qwq = 1e18;
  for (long long i = (1), stOxrj = (n - 1); i <= stOxrj; ++i)
    if (qwq > D(i, n)) qwq = D(i, n), whe = i;
  isg[whe] = isg[whe - 1] = isg[whe + 1] = 1;
  isg[s] = isg[s - 1] = isg[s + 1] = 1;
  for (long long i = (1), stOxrj = (n); i <= stOxrj; ++i)
    if (isg[i]) guan.push_back(i);
  long double ans = sqr(qwq) * 2;
  ans += sqr(D(1, n - 1)) + min(sqr(D(1, s)), sqr(D(s, n - 1)));
  long long sz = guan.size(), p[15];
  for (long long i = (0), stOxrj = (sz - 1); i <= stOxrj; ++i) p[i] = i;
  do {
    if (guan[p[0]] != s) continue;
    long double nans = 0;
    bool vs[15];
    memset(vs, 0, sizeof(vs));
    for (long long i = (1), stOxrj = (sz - 1); i <= stOxrj; ++i) {
      nans += sqr(D(guan[p[i - 1]], guan[p[i]]));
      long long mn = min(p[i - 1], p[i]);
      long long mx = max(p[i - 1], p[i]);
      if (mx == sz - 1) continue;
      for (long long i = (mn), stOxrj = (mx - 1); i <= stOxrj; ++i) vs[i] = 1;
    }
    bool ok = 1;
    for (long long i = (0), stOxrj = (sz - 3); i <= stOxrj; ++i)
      if (guan[i + 1] - guan[i] != 1 && !vs[i]) ok = 0;
    if (ok) ans = min(ans, nans);
  } while (next_permutation(p, p + sz));
  printf("%.10Lf\n", ans);
  return 0;
}
