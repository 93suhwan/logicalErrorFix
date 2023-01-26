#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<string> a(n - 2);
    for (string &i : a) {
      cin >> i;
    }
    string ans = a[0];
    long long d = 0;
    for (long long i = 1; i <= n - 3; i++) {
      if (a[i][0] == a[i - 1][1]) {
        ans += a[i][1];
      } else {
        d = 1;
        ans += a[i];
      }
    }
    if (d == 0) {
      ans += 'a';
    }
    cout << ans << "\n";
  }
  return 0;
}
