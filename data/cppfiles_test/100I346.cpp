#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 100;
int n;
long long inv[N], f[N];
int a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n, greater<int>());
  int res = 2;
  int fi = a[1], se = a[2];
  for (int i = 3; i <= n; i++) {
    if (a[i] < se) break;
    if (a[i] == se) res++;
  }
  long long ans = f[n];
  if (fi - se > 1)
    ans = 0;
  else if (fi - se == 1)
    ans = ans * inv[res] % mod * (res - 1) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = 1;
  for (int i = 1; i <= N; i++) f[i] = f[i - 1] * i % mod;
  inv[1] = 1;
  for (int i = 2; i <= N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}
