#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > i + 1) {
        ans = max(ans, a[i] - i - 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
