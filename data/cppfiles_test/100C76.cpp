#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, ans = 0, c;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ans = a[i];
        c = a[i];
      } else {
        ans = max(ans, a[i] - c);
        c += a[i] - c;
      }
    }
    cout << ans << endl;
  }
}
