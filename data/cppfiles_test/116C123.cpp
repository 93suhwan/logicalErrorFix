#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)998244353;
const int N = (int)5e5 + 5;
const int M = (int)1e6 + 5;
int _ = 1;
ll n, ans;
ll a[N];
ll num[N], maxn[N];
void work() {
  ans = 0;
  scanf("%lld", &n);
  for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (ll i = 0; i <= n + 1; i++) num[i] = maxn[i] = 0;
  for (ll i = 1; i <= n; i++) {
    if (a[i] - 1 >= 0) ans = (ans + num[a[i] - 1] + maxn[a[i] - 1]) % mod;
    ans = (ans + maxn[a[i]]) % mod;
    ans = (ans + num[a[i] + 1] + maxn[a[i] + 1]) % mod;
    if (a[i] <= 1) ans = (ans + 1) % mod;
    if (a[i] - 1 >= 0) {
      num[a[i] - 1] = num[a[i] - 1] * 2 % mod;
      num[a[i] - 1] = (num[a[i] - 1] + maxn[a[i] - 1]) % mod;
    }
    num[a[i] + 1] = num[a[i] + 1] * 2 % mod;
    maxn[a[i] + 1] = maxn[a[i] + 1] * 2 % mod;
    maxn[a[i] + 1] = (maxn[a[i] + 1] + maxn[a[i]]) % mod;
    if (!a[i])
      maxn[1]++;
    else if (a[i] == 1)
      num[0]++;
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &_);
  while (_--) {
    work();
  }
  return 0;
}
