#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
const int mod = 998244353;
int a[mx], y, z;
long long sum[mx];
int as[mx], bs[mx];
bool v[mx];
map<int, int> r[mx];
int query(long long i, int x) {
  long long ans = 0;
  if (i == 0) return 0;
  if (x == 1) return sum[i];
  if (x < 20) {
    int d = r[i][x];
    if (d != 0) return d;
  }
  if (x == as[i]) {
    return bs[i];
  }
  if (a[i] <= x)
    z = a[i];
  else {
    y = (x + a[i] - 1) / x;
    ans = (ans + i * (y - 1)) % mod;
    z = a[i] / y;
  }
  int k = (ans + query(i - 1, z)) % mod;
  if (x < 20) {
    r[i][x] = k;
  } else {
    as[i] = x;
    bs[i] = k;
  }
  return k;
}
void oyl(int n) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = (sum[i - 1] + i * a[i] - i) % mod;
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + query(i - 1, a[i])) % mod;
  }
  printf("%lld\n", ans);
  return;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    oyl(n);
    if (t != 0)
      for (int _ = 1; _ <= n; _++) {
        r[_].clear();
        as[_] = 0;
        bs[_] = 0;
      }
  }
  return 0;
}
