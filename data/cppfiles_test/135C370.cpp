#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a[i + k] / a[i];
    }
    for (int i = 2 * k; i < n; i++) {
      ans += a[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
