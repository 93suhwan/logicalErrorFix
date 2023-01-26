#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a(n, 0);
    vector<long long> ans(n, 0);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0) {
      for (long long i = 0; i < n; i += 2) {
        ans[i] = a[i + 1];
        ans[i + 1] = -a[i];
      }
    } else {
      for (long long i = 3; i < n; i += 2) {
        ans[i] = a[i + 1];
        ans[i + 1] = -a[i];
      }
      b = 0, c = 1, d = 2;
      if (a[c] + a[d] == 0) {
        swap(c, b);
      }
      if (a[c] + a[d] == 0) {
        swap(b, d);
      }
      ans[b] = a[c] + a[d];
      ans[c] = -a[b];
      ans[d] = -a[b];
    }
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
