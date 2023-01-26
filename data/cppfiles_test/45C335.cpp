#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int i;
    for (i = 0; i < n; i++) cin >> a[i];
    long long int ans = 1;
    long long int p = 1;
    for (i = 1; i < n; i++) {
      if (a[i] == a[i - 1] && a[i] == 0) {
        cout << -1 << endl;
        p = 0;
        break;
      }
      if (a[i] == a[i - 1] && a[i]) {
        ans += 5;
      }
      if (a[i] && a[i - 1] == 0) {
        ans++;
      }
    }
    if (a[0]) ans++;
    if (p) {
      cout << ans << endl;
    }
  }
}
