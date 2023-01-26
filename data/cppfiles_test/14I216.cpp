#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
const int N = 2005;
int n, k, a[N], val[N][N];
int dp(int ind, int rem, int shift) {
  if (rem < 0) return INT_MIN;
  if (val[ind][rem] != -1) return val[ind][rem];
  if (ind == n + 1) return 0;
  return val[ind][rem] = max((ind - shift == a[ind]) + dp(ind + 1, rem, shift),
                             dp(ind + 1, rem - 1, shift + 1));
}
bool P(ll x) { return dp(1, x, 0) >= k; }
ll bsmin(ll l, ll r) {
  while (l < r) {
    ll mid = l + (r - l) / 2;
    if (P(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (!P(l)) return -1;
  return l;
}
void MAIN() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= n + 1; j++) val[i][j] = -1;
  cout << bsmin(0, n) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
