#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e3 + 5;
ll ksm(ll a, ll n) {
  ll ans = 1;
  while (n) {
    if (n % 2) ans = (a * ans);
    a = (a * a);
    n /= 2;
  }
  return ans;
}
void solve() {
  ll a[maxn], dp[maxn], ten[maxn], n, k, now;
  for (int i = 0; i <= 10; i++) {
    ten[i] = ksm(10, i) - 1;
  }
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  now = n + 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = ten[a[i] - a[i - 1]] + dp[i - 1];
    if (k < dp[i]) {
      now = i;
      break;
    }
  }
  cout << (ten[a[now - 1]] + 1) * (k - dp[now - 1] + 2) - 1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
