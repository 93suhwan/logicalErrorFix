#include <bits/stdc++.h>
using namespace std;
const int mxm = 1e9 + 7;
const int mx = 1e7 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    long long ans = -LONG_MAX;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 100) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          long long h = (long long)(i + 1) * (j + 1);
          h -= k * (a[i] | a[j]);
          ans = max(ans, h);
        }
      }
    } else {
      for (int i = n - 101; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          long long h = (long long)(i + 1) * (j + 1);
          h -= k * (a[i] | a[j]);
          ans = max(ans, h);
        }
      }
    }
    cout << ans << "\n";
  }
}
