#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.length();
    if (s[0] == 'a' and s[n - 1] == 'b') {
      s[n - 1] = 'a';
    }
    if (s[0] == 'b' and s[n - 1] == 'a') s[n - 1] = 'b';
    cout << s << "\n";
  }
  return 0;
}
