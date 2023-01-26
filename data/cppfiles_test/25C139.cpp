#include <bits/stdc++.h>
using namespace std;
long long check(string s, string t, long long pos) {
  string x = t.substr(0, pos), y = t.substr(pos);
  long long lenx = x.length(), leny = y.length();
  for (long long i = 0; i < s.length(); i++) {
    if (i + lenx - leny - 1 >= 0 && i + lenx - leny - 1 < s.length()) {
      string a = s.substr(i, lenx);
      string b = s.substr(i + lenx - leny - 1, leny);
      reverse(b.begin(), b.end());
      if (x == a && y == b) {
        return 1;
      }
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long ans = 0;
    string s, t;
    cin >> s >> t;
    for (long long i = 0; i < t.length(); i++) {
      if (check(s, t, i + 1) == 1) {
        ans = 1;
        break;
      }
    }
    if (ans == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
