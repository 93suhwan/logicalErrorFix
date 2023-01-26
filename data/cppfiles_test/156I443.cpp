#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  vector<ll> ans(T, 1LL << 60);
  for (int t = 0; t < T; t++) {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll A = 0;
    for (int i = 0; i < n; i++) {
      A += a[i];
    }
    if (A <= k) {
      ans[t] = 0;
      continue;
    }
    vector<ll> sum(n);
    sum[0] = 0;
    if (n == 1) {
      ans[t] = a[0] - k;
      continue;
    }
    if (n > 1) {
      sum[1] = a[1];
      if (n > 2) {
        for (int i = 2; i < n; i++) {
          sum[i] = sum[i - 1] + a[i];
        }
      }
    }
    for (ll y = 0; y < n; y++) {
      ll x = 0;
      if ((sum[n - y - 1] - k) % (y + 1) == 0) {
        x += (sum[n - y - 1] - k) / (y + 1);
      } else {
        x += ((sum[n - y - 1] - k) / (y + 1) + 1);
      }
      x += a[0];
      x = max((ll)0, x);
      ans[t] = min(ans[t], x + y);
    }
  }
  for (int t = 0; t < T; t++) {
    cout << ans[t] << endl;
  }
  return 0;
}
