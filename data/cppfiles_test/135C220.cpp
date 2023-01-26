#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 2 * k; i++) {
      ans += a[i];
    }
    int j = n - k - 1;
    for (int i = n - 1; i >= n - k; i--) {
      ans += a[j--] / a[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
