#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < k; i++) {
      sum1 += (v[i] / v[n - i - 1]);
    }
    for (int i = k; i < n - k; i++) {
      sum1 += v[i];
    }
    for (int i = 0; i < 2 * k; i += 2) {
      sum2 += (v[n - i - 2] / v[n - i - 1]);
    }
    for (int i = 0; i < (n - 2 * k); i++) {
      sum2 += v[i];
    }
    cout << min(sum1, sum2) << "\n";
  }
  return 0;
}
