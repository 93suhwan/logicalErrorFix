#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
long long n, k;
int a[15];
long long rc[15], p[15], ans;
void solve() {
  scanf("%d%d", &n, &k);
  k++;
  scanf("%d", &a[1]);
  rc[1] = 1;
  long long now = 1, tmp;
  int ss = 0;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
    tmp = 1;
    while (ss < a[i]) now *= 10, tmp *= 10, ss++;
    p[i - 1] = tmp - 1;
    rc[i] = now;
  }
  ans = 0;
  for (int i = 1; i < n; i++) {
    if (k >= p[i])
      ans += p[i] * rc[i], k -= p[i];
    else {
      ans += rc[i] * k;
      k = 0;
    }
  }
  if (k) ans += rc[n] * k;
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
