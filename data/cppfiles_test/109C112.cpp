#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] != '0') {
        ans += s[i] - '0' + 1;
        if (i == n - 1) ans--;
      }
    }
    cout << ans << '\n';
  }
}
