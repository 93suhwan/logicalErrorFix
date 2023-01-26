#include <bits/stdc++.h>
const long long N = 998244353;
using namespace std;
long long a[1000], i;
long long b[1000];
long long deal1(long long x) {
  long long n = 1, sum = 0;
  i = 1;
  while (x) {
    if (x % 10 != 0) {
      sum += x % 10;
      a[i++] = x % 10 * n;
    }
    n *= 10;
    x /= 10;
  }
  return (sum);
}
int main() {
  long long n, m, l = 0, sum, zz, mm;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    zz = 0;
    sum = 0, mm = 0;
    scanf("%lld %lld", &m, &l);
    zz = deal1(m);
    if (l <= zz) {
      long long j;
      for (j = 1; j < l; j++) {
        b[j] = a[j];
        mm += a[j];
      }
      b[l] = m - mm;
      for (long long o = 1; o <= l; o++) printf("%lld ", b[o]);
      puts("");
    } else {
      long long j, num = 1;
      for (j = 1; j <= zz; j++) {
        b[j] = a[j];
      }
      for (j = zz + 1; j <= l; j++) {
        if (b[num] == 1)
          j--, num++;
        else
          b[num]--, b[j] = 1;
      }
      for (long long o = 1; o <= l; o++) printf("%lld ", b[o]);
      puts("");
    }
  }
}
