#include <bits/stdc++.h>
using namespace std;
const long long NMAX = 2e5 + 5;
long long v[NMAX];
long long dif[NMAX];
long long d[NMAX];
void solve() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 0; i < n; ++i) scanf("%lld", &v[i]);
  long long last = n - 1;
  for (long long i = 0; i < n; ++i) {
    dif[i] = v[last] - v[i];
    last = i;
  }
  for (long long i = 0; i < n; ++i) {
    long long next = (i + 1) % n;
    d[i] = dif[i] - dif[next];
    long long check = d[i];
    if (check < 0) check *= -1;
    if (check % n) {
      printf("NO\n");
      return;
    }
    d[i] /= n;
  }
  for (long long i = n - 2; i >= 0; --i) d[i] += d[i + 1];
  if (d[0] != 0) {
    printf("NO\n");
    return;
  }
  long long sum_n = 1;
  long long sum = 0;
  for (long long i = n - 1, j = 2; i > 0; --i, ++j) {
    sum_n += j;
    sum += j * d[i];
  }
  v[0] -= sum;
  if (v[0] < 0 || v[0] % sum_n) {
    printf("NO\n");
    return;
  }
  long long nn = v[0] / sum_n;
  for (long long i = 0; i < n; ++i)
    if (nn + d[i] <= 0) {
      printf("NO\n");
      return;
    }
  printf("YES\n");
  for (long long i = 0; i < n; ++i) printf("%lld ", nn + d[i]);
  printf("\n");
}
signed main() {
  long long n;
  scanf("%lld", &n);
  for (; n; n--) solve();
  return 0;
}
