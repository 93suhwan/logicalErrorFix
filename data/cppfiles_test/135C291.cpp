#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    int ans = 0;
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= n - k; i--) ans += v[i - k] / v[i];
    for (int i = 0; i < n - 2 * k; i++) ans += v[i];
    cout << ans << endl;
  }
}
