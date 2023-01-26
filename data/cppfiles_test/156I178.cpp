#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long sum[N];
int a[N];
void solve() {
  int n;
  long long k, s = 0;
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  if (s <= k) {
    puts("0");
    return;
  }
  if (n == 1) {
    printf("%lld\n", a[1] - k);
    return;
  }
  sort(a + 1, a + 1 + n);
  sum[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  long long res = INF;
  for (int i = n; i >= 2; i--) {
    int cnt = n - i + 1;
    long long cur = s - k - sum[i] + 1LL * a[1] * cnt;
    long long t = cur / (cnt + 1);
    while (t * (cnt + 1) < cur) t++;
    res = min(res, t + cnt);
  }
  printf("%lld\n", res);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
