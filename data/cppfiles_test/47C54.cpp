#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long &i : v) {
      cin >> i;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n; i += k) {
      if (v[i] > 0) {
        break;
      }
      ans += abs(2 * v[i]);
    }
    for (int i = n - 1; i >= 0; i -= k) {
      if (v[i] < 0) {
        break;
      }
      ans += abs(2 * v[i]);
    }
    cout << ans - max(abs(v[0]), abs(v[n - 1])) << endl;
  }
  return 0;
}
