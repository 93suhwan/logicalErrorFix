#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i = 1;
    long long int ans = 1;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int sus = 0;
    if (a[0] == 1) {
      ans += 1;
    } else if (a[0] == 0) {
      ans += 0;
    }
    for (i = 1; i < n; i++) {
      if (a[i] == 0 && a[i - 1] == 1) {
        ans += 0;
      } else if (a[i] == 0 && a[i - 1] == 0) {
        sus = 1;
        break;
      } else if (a[i] == 1 && a[i - 1] == 1) {
        ans += 5;
        ;
      } else if (a[i] == 1 && a[i - 1] == 0) {
        ans += 1;
      }
    }
    if (sus == 1) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
