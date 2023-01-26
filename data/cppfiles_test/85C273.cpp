#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = 0;
    long long n = s.length();
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') ans++;
      while (i < n && s[i] == '0') {
        i++;
      }
    }
    cout << min(2ll, ans) << "\n";
  }
  return 0;
}
