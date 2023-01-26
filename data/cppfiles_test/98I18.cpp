#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string key;
    cin >> key;
    string s;
    cin >> s;
    long long ans = 0;
    for (long long i = 1; i < s.length(); i++) {
      long long r = key.find(s[i]) - key.find(s[i - 1]);
      ans += abs(r);
    }
    cout << ans << endl;
  }
}
