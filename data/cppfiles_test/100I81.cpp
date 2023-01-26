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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    int idx = 0;
    while (idx < n - 1 && ((a[idx] - ans) <= 0 || a[idx + 1] >= 2 * a[idx])) {
      ans += a[idx] - ans;
      idx++;
    }
    cout << a[idx] - ans << '\n';
    ;
  }
  return 0;
}
