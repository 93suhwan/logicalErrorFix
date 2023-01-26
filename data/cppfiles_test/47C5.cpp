#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k, l1, l2, c = 0, p = 0;
    cin >> n >> k;
    long long int a[n];
    vector<long long int> x(n), y(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0) {
        x.push_back((0 - a[i]));
      } else {
        y.push_back(a[i]);
      }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    l1 = x.size();
    l2 = y.size();
    if (x[l1 - 1] > y[l2 - 1]) {
      c += x[l1 - 1];
      for (i = l1 - k - 1; i >= 0; i -= k) {
        c = c + (2 * x[i]);
      }
      for (i = l2 - 1; i >= 0; i -= k) c = c + (2 * y[i]);
    } else {
      c += y[l2 - 1];
      for (i = l2 - 1 - k; i >= 0; i -= k) c = c + (2 * y[i]);
      for (i = l1 - 1; i >= 0; i -= k) c = c + (2 * x[i]);
    }
    cout << c << "\n";
  }
  return 0;
}
