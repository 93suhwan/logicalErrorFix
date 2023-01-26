#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long sum[N], k, s;
int a[N], n;
long long f(long long i) {
  long long x = a[1] - i;
  int l = 2, r = n;
  int cnt = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (sum[mid] - (n - mid + 1) * x + i >= s - k) {
      cnt = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (1LL * i + n - cnt + 1 == 7411872) cout << "i = " << i << endl;
  if (cnt != -1) return 1LL * i + n - cnt + 1;
  return INF;
}
void solve() {
  s = 0;
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
  long long t = k / n;
  long long l = max(0LL, a[1] - t), r = 1e9, lans, rans;
  for (int i = 1; i <= 500; i++) {
    if (l <= r) {
      long long lmid = l + (r - l) / 3;
      long long rmid = r - (r - l) / 3;
      lans = f(lmid), rans = f(rmid);
      if (lans <= rans)
        r = rmid - 1;
      else
        l = lmid + 1;
    }
  }
  printf("%lld\n", min(lans, rans));
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
