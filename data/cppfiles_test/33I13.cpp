#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    long long a[n + 5], m = 0;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > m) {
        m = a[i];
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == m) {
        if (i - 1 >= 0) {
          ans = max(ans, a[i] * a[i - 1]);
        }
        if (i + 1 < n) {
          ans = max(ans, a[i] * a[i + 1]);
        }
      }
    }
    cout << ans << endl;
  }
}
