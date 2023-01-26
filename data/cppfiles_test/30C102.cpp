#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int re = 0x7fffffff;
    for (int i = 0; i < 26; i++) {
      int l = 0, r = s.size() - 1;
      bool f = 0;
      int ree = 0;
      while (r > l) {
        if (s[l] != s[r]) {
          if (s[l] == ('a' + i) && (s[l + 1] == s[r] || l + 1 == r)) {
            ree++;
            l++;
          } else if (s[l] == ('a' + i) && s[l + 1] == s[l]) {
            l++;
            ree++;
            continue;
          } else if (s[r] == ('a' + i) && (s[l] == s[r - 1] || l == r - 1)) {
            ree++;
            r--;
          } else if (s[r] == ('a' + i) && s[r - 1] == s[r]) {
            ree++;
            r--;
            continue;
          } else {
            f = 1;
            break;
          }
        }
        l++;
        r--;
      }
      if (f == 0) {
        re = min(ree, re);
      }
    }
    if (re == 0x7fffffff)
      cout << -1 << endl;
    else
      cout << re << endl;
  }
  return 0;
}
