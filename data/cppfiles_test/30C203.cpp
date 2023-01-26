#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L = 0, R = n - 1;
    int res = 0;
    while (L < R) {
      if (s[L] != s[R]) {
        res = -1;
        bool flag = true;
        int l = L, r = R, cnt = 0;
        while (l < r) {
          if (s[l] != s[r]) {
            if (s[l] == s[L])
              cnt++, l++;
            else if (s[r] == s[L])
              cnt++, r--;
            else {
              flag = false;
              break;
            }
          } else
            l++, r--;
        }
        if (flag) res = cnt;
        flag = true;
        l = L, r = R, cnt = 0;
        while (l < r) {
          if (s[l] != s[r]) {
            if (s[l] == s[R])
              cnt++, l++;
            else if (s[r] == s[R])
              cnt++, r--;
            else {
              flag = false;
              break;
            }
          } else
            l++, r--;
        }
        if (flag) {
          res = min(cnt, res);
          if (res == -1) res = cnt;
        }
        break;
      }
      L++, R--;
    }
    cout << res << endl;
  }
}
