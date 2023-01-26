#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto check = [&](string &s, long long p) {
    string t = to_string(p);
    char _t = '#';
    for (long long i = 0; i < (long long)s.size(); ++i) {
      if (s[i] == '_') continue;
      if (s[i] == 'X') {
        if (_t == '#')
          _t = t[i];
        else if (_t != t[i])
          return false;
        continue;
      }
      if (s[i] != t[i]) return false;
    }
    return true;
  };
  string s;
  cin >> s;
  if ((long long)s.size() == 1) {
    long long ans = 0;
    if (s == "0") ans = 1;
    cout << ans << "\n";
  } else {
    long long ans = 0;
    long long start = pow(10ll, (long long)s.size() - 1ll);
    start += 24ll;
    start /= 25ll;
    start *= 25ll;
    for (long long i = start; i < (long long)pow(10ll, (long long)s.size());
         i += 25ll) {
      ans += check(s, i);
    }
    cout << ans << "\n";
  }
  return 0;
}
