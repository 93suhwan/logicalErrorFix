#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  long long ab = 0, ba = 0;
  for (long long i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b')
      ab++;
    else if (s[i] == 'b' && s[i + 1] == 'a')
      ba++;
  }
  return ab == ba;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    long long n = s.size();
    if (check(s)) {
      cout << s << endl;
      continue;
    }
    long long c = 200;
    string ans = "";
    for (char x = 'a'; x <= 'b'; x++) {
      for (char y = 'a'; y <= 'b'; y++) {
        string t = s;
        t[0] = x;
        t[n - 1] = y;
        if (check(t)) {
          long long c1 = (s[0] != t[0]) + (s[n - 1] != t[n - 1]);
          if (c1 < c) {
            ans = t;
            c = c1;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
