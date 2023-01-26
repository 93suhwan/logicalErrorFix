#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 2e5 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int tv[maxn];
void solve() {
  long long int n, k, cur = 1, ans = 0, w, d;
  cin >> n >> k;
  if (n & 1) {
    w = 0;
  } else {
    w = 1;
  }
  if (n & 1) {
    d = 1 + tv[n - 1];
  } else {
    d = tv[n - 1] - 1;
  }
  for (long long int i = k - 1; i >= 0; i--) {
    long long int h = 1ll * w * cur * tv[i] % md;
    ans += h;
    cur *= d;
    cur %= md;
  }
  ans += cur;
  ans %= md;
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tv[0] = 1;
  for (long long int i = 1; i < maxn; i++) {
    tv[i] = (tv[i - 1] << 1);
    if (tv[i] >= md) tv[i] -= md;
  }
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
