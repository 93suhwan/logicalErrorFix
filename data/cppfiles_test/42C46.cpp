#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mod = 1e9 + 7;
struct node {
  long long x, y, h;
};
struct node a[200005];
bool cmp(node A, node B) { return A.y < B.y; }
bool vis[200005];
long long tr[400005];
long long lowbit(long long k) { return k & -k; }
void xi(long long k, long long w) {
  while (k) {
    tr[k] += w;
    tr[k] = (tr[k] + mod) % mod;
    k -= lowbit(k);
  }
  return;
}
long long fi(long long k) {
  long long cnt = 0;
  while (k <= 400000) {
    cnt += tr[k];
    k += lowbit(k);
    cnt = (cnt + mod) % mod;
  }
  return cnt % mod;
}
long long dp[400005];
signed main() {
  long long ans = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld %lld", &a[i].x, &a[i].y);
    a[i].h = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  cin >> m;
  long long t1;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &t1);
    vis[t1] = 1;
  }
  xi(2 * n, 1);
  long long num = 0, no;
  for (long long i = 1; i <= n; i++) {
    dp[i] = fi(a[i].x);
    xi(a[i].x, dp[i]);
  }
  long long pv = 1;
  for (long long i = n; i > 0; i--) {
    xi(a[i].x, (mod - dp[i]) % mod);
    if (vis[a[i].h] && a[i].x >= pv) {
      ans += fi(pv);
      ans %= mod;
      pv = a[i].x;
    }
  }
  cout << ans;
  return 0;
}
