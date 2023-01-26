#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int h = 1;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == 1) {
        if (i > 0 && a[i - 1] == 1)
          h += 5;
        else
          h += 1;
      }
      if (a[i] == 0) {
        if (i > 0 && a[i - 1] == 0) {
          h = -1;
          break;
        }
      }
    }
    cout << h << "\n";
  }
}
