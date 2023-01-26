#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 2e5 + 100;
int n;
long long inv[N], f[N];
int a[N];
void solve() {
  cin >> n;
  int t = 0;
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  long long cnt = 2;
  while (cnt < n && a[cnt] == a[1]) cnt++;
  long long ans;
  ans = f[n];
  if (a[0] == a[1] + 1) {
    ans = (ans * inv[cnt]) % mod * (cnt - 1) % mod;
    printf("%lld\n", ans);
    return;
  } else if (a[0] > a[1] + 1)
    ans = 0;
  printf("%lld\n", ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = 1;
  for (int i = 1; i <= N; i++) f[i] = f[i - 1] * i % mod;
  inv[1] = 1;
  for (int i = 2; i <= N; i++)
    inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}
