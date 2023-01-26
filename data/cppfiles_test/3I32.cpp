#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, ss = "";
  cin >> s;
  bool bb = 0, tt = 0, bc = 0, bd = 0;
  long long n = s.size(), i;
  long long ans = 0;
  if (s.size() == 1) {
    if (s[0] == '0' || (s[0] == 'X' || s[0] == '_')) ans = 1;
  } else if (s.size() == 2) {
    if (s == "25") ans = 1;
    if (s == "75") ans = 1;
    if (s == "50") ans = 1;
    if (s == "__") ans = 3;
    if (s == "_X") ans = 3;
    if (s == "X_") ans = 3;
  } else {
    ss += s[n - 2];
    ss += s[n - 1];
    if (ss == "25") ans = 1;
    if (ss == "75") ans = 1;
    if (ss == "50") ans = 1;
    if (ss == "00") ans = 1;
    if (ss == "__") ans = 4;
    if (ss == "_X") {
      ans = 4;
      bb = 1;
    }
    if (ss == "X_") {
      ans = 4;
      bd = 1;
    }
    if (ss == "XX") {
      ans = 1;
      bc = 1;
    }
    if (s[0] == '0')
      ans = 0;
    else if (s[0] == '_')
      ans *= 9;
    else if (s[0] == 'X') {
      if (bb)
        ans = 2;
      else if (bc)
        ans = 0;
      else if (bd) {
        ans = 3;
      } else {
        ans *= 9;
      }
    }
    for (i = 1; i < n - 2; i++) {
      if (s[i] == '_')
        ans *= 10;
      else if (s[i] == 'X')
        tt = 1;
    }
    if (tt && (!bc && (!bd && !bb))) ans *= 10;
  }
  cout << ans;
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
