#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a1[n], a2[n];
    for (auto &e : a1) cin >> e;
    for (auto &e : a2) cin >> e;
    long long int ans = LONG_LONG_MAX;
    long long int sum = 0;
    long long int val = accumulate(a1, a1 + n, 0ll);
    for (int i = 0; i < n; i++) {
      val -= a1[i];
      ans = min(ans, max(sum, val));
      sum += a2[i];
    }
    cout << ans << "\n";
  }
}
