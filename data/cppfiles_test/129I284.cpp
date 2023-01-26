#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort((a).begin(), (a).end());
    int ans = 0;
    bool worked = true;
    for (int i = 1; i <= n; i++) {
      if (a[i - 1] != i && a[i - 1] <= i * 2) {
        worked = false;
        cout << -1 << '\n';
        break;
      } else if (a[i - 1] > i) {
        ans++;
      }
    }
    if (worked) cout << ans << '\n';
  }
  return 0;
}
