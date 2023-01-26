#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int idx = max(0, n - 300);
    int ans = INT_MIN;
    for (int i = idx; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = max(ans, ((i + 1) * (j + 1) - k * (v[i] | v[j])));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
