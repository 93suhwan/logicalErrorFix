#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, ss = "";
  cin >> s;
  bool bb = 0, tt = 0, bc = 0, bd = 0, uu = 0, bkk = 0, bbc = 0;
  long long n = s.size(), i;
  long long ans = 0;
  if (s.size() == 1) {
    if (s[0] == '0' || (s[0] == 'X' || s[0] == '_')) ans = 1;
  } else if (s.size() == 2) {
    if (s == "25")
      ans = 1;
    else if (s == "75")
      ans = 1;
    else if (s == "50")
      ans = 1;
    else if (s == "__")
      ans = 3;
    else if (s == "_X")
      ans = 3;
    else if (s == "X_")
      ans = 3;
    else if (s[0] == '2' || (s[0] == '7' || s[0] == '5')) {
      if (s[1] == '_' || s[1] == 'X') ans = 1;
    } else if (s[1] == '5') {
      ans = 2;
    } else if (s[1] == '0') {
      ans = 1;
    }
  } else {
    ss += s[n - 2];
    ss += s[n - 1];
    if (ss == "25")
      ans = 1;
    else if (ss == "75")
      ans = 1;
    else if (ss == "50")
      ans = 1;
    else if (ss == "00")
      ans = 1;
    else if (ss == "__")
      ans = 4;
    else if (ss == "_X") {
      ans = 4;
      bb = 1;
    } else if (ss == "X_") {
      ans = 4;
      bd = 1;
    } else if (ss == "XX") {
      ans = 1;
      bc = 1;
    } else if (s[n - 2] == '2' ||
               (s[n - 2] == '7' || (s[n - 2] == '5' || s[n - 2] == '0'))) {
      if (s[n - 1] == 'X') {
        ans = 1;
        bkk = 1;
        if (s[0] == 'X' && (s[n - 2] == '0' || s[n - 2] == '5')) {
          cout << "0";
          return 0;
        }
      } else if (s[n - 1] == '_') {
        ans = 1;
      }
    } else if (s[n - 2] == '_') {
      if (s[n - 1] == '5')
        ans = 2;
      else if (s[n - 1] == '0')
        ans = 2;
    } else if (s[n - 2] == 'X') {
      if (s[n - 1] == '5') {
        ans = 2;
        bbc = 1;
      } else if (s[n - 1] == '0') {
        if (s[0] == 'X')
          ans = 1;
        else
          ans = 2;
      }
    }
    if (s[0] == '0')
      ans = 0;
    else if (s[0] == '_')
      ans *= 9;
    else if (s[0] == 'X') {
      uu = 1;
      if (bb)
        ans = 2;
      else if (bc)
        ans = 0;
      else if (bd) {
        ans = 3;
      } else if (!bbc && (!bkk)) {
        ans *= 9;
      }
    }
    for (i = 1; i < n - 2; i++) {
      if (s[i] == '_')
        ans *= 10;
      else if (s[i] == 'X')
        tt = 1;
    }
    if (tt && (!bc && (!bd && ((!bb && !uu) && ((!bbc && !bkk)))))) ans *= 10;
  }
  cout << ans;
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
