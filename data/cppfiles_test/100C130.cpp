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
    long long ans = LLONG_MIN;
    long long p = 0;
    for (int x : a) {
      ans = max(ans, x - p);
      p = x;
    }
    cout << ans << '\n';
  }
  return 0;
}
