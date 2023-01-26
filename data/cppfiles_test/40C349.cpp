#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
signed main() {
  4;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> pre(n), pre2(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pre[i] = a[i];
      if (i) pre[i] += pre[i - 1];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      pre2[i] = b[i];
      if (i) pre2[i] += pre2[i - 1];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int alice = pre[n - 1];
      if (i) alice -= pre[i - 1];
      int bob = pre[n - 1] - pre[i];
      if (i) bob = max(bob, pre2[i - 1]);
      ans = min(ans, bob);
    }
    cout << ans << '\n';
  }
}
