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
    vector<ll> sum(n);
    sum[0] = 0;
    if (n > 1) {
      sum[1] = a[1];
      if (n > 2) {
        for (int i = 2; i < n; i++) {
          sum[i] = sum[i - 1] + a[i];
        }
      }
    }
    for (ll y = 0; y < n; y++) {
      int x = a[0] + (sum[n - y - 1] - k + y) / (y + 1);
      ans[t] = min(ans[t], x + y);
    }
    ans[t] = max(ans[t], (ll)0);
  }
  for (int t = 0; t < T; t++) {
    cout << ans[t] << endl;
  }
  return 0;
}
