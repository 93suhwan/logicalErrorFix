#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    k -= 2;
    string ans = "NO";
    long long mx = (n * (n - 1)) / 2;
    if (k < 0 || m < n - 1 || m > mx) {
      goto fin;
    }
    if (n == 1) {
      if (k >= 0) {
        ans = "YES";
      }
    } else if (m == mx) {
      if (k >= 1) {
        ans = "YES";
      }
    } else {
      if (k >= 2) {
        ans = "YES";
      }
    }
  fin:
    cout << ans << endl;
  }
  return 0;
}
