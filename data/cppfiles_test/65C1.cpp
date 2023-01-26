#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200008];
long long sx[200008];
long long jx[200008];
char s[200008];
void dfs1(long long l, long long r, long long n) {
  if (n == 1) {
    jx[n] = a[l];
    return;
  }
  if (sx[n] == sx[n - 1]) {
    jx[n] = a[l];
    dfs1(l + 1, r, n - 1);
  } else {
    jx[n] = a[r];
    dfs1(l, r - 1, n - 1);
  }
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) {
    if (s[i] == 'L')
      sx[i] = 1;
    else
      sx[i] = -1;
  }
  sort(a + 1, a + n + 1);
  if (sx[n] == -1) {
    for (long long i = n; i >= 1; i = i - 2) {
      a[i] = -a[i];
    }
  } else {
    for (long long i = n - 1; i >= 1; i = i - 2) {
      a[i] = -a[i];
    }
  }
  dfs1(1, n, n);
  for (long long i = 1; i <= n; i++) {
    if (jx[i] > 0)
      printf("%lld L\n", jx[i]);
    else
      printf("%lld R\n", -jx[i]);
  }
  return 0;
}
