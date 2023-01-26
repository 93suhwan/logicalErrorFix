#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = a[0];
    for (int i = 1; i < n; i++) ans = max(ans, a[i] - a[i - 1]);
    cout << ans << '\n';
  }
  return 0;
}
