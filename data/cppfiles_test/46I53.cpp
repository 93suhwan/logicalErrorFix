#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    int ans = 1e9 + 7;
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[n - 1]) {
        ans = min(ans, i);
      } else if (a[i] == b[n - 2]) {
        ans = min(ans, i + 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
