#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mx = max(mx, v[i]);
    }
    int k = v.back();
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > k) {
        ans++;
        k = v[i];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
