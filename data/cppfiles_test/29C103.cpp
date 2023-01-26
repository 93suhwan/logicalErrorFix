#include <bits/stdc++.h>
using namespace std;
long long n, a1, a2, sa, M = 3e5, ak, s1[300005], s2[300005];
void f1(long long p, long long q) {
  while (p <= M) {
    s1[p] += q;
    p += (p & -p);
  }
}
void f2(long long p, long long q) {
  while (p <= M) {
    s2[p] += q;
    p += (p & -p);
  }
}
long long g1(long long p) {
  long long re = 0;
  while (p >= 1) {
    re += s1[p];
    p -= (p & -p);
  }
  return re;
}
long long g2(long long p) {
  long long re = 0;
  while (p >= 1) {
    re += s2[p];
    p -= (p & -p);
  }
  return re;
}
int main() {
  long long i, j, k, t, st, la;
  cin >> n;
  for (k = 1; k <= n; k++) {
    scanf("%lld", &ak);
    a1 += (k - 1) * ak;
    a1 -= g1(ak);
    a2 += sa;
    st = 0;
    for (i = 0;; i++) {
      la = min((i + 1) * ak - 1, M);
      t = g2(la);
      a2 -= (t - st) * ak * i;
      st = t;
      if ((i + 1) * ak - 1 >= M) break;
    }
    sa += ak;
    for (i = 1; i * ak <= M; i++) {
      f1(i * ak, ak);
    }
    f2(ak, 1);
    printf("%lld ", a1 + a2);
  }
  return 0;
}
