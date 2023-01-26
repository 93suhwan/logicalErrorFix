#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    long long sum = 0;
    int i, j, l;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0, l = 1; l <= k; ++l, ++i) {
      sum += a[i + k] / a[i];
    }
    for (int i = 2 * k; i < n; ++i) {
      sum += a[i];
    }
    cout << sum << endl;
  }
  return 0;
}
