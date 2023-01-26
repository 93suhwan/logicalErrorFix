#include <bits/stdc++.h>
using namespace std;
const int mmax = 1e5 + 3;
int t, num;
string s;
int fun(char c) {
  int l = 0, r = num - 1;
  int min_char = 0;
  bool b = true;
  while (l <= r) {
    if (s[r] == s[l]) {
      r--;
      l++;
    } else {
      if (s[l] == c) {
        l++;
        min_char++;
      } else if (s[r] == c) {
        r--;
        min_char++;
      } else {
        b = false;
        break;
      }
    }
  }
  if (b)
    return min_char;
  else
    return -1;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> num;
    cin >> s;
    int ans = mmax;
    for (char i = 'a'; i <= 'z'; i++) {
      int cnt = fun(i);
      if (cnt != -1) ans = min(ans, cnt);
    }
    if (ans == mmax)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
