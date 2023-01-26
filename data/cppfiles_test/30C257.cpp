#include <bits/stdc++.h>
using namespace std;
const int mmax = 1e5 + 3;
int t, num;
string s;
char a[2];
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
    int l = 0, r = num - 1;
    while (l <= r) {
      if (s[r] == s[l]) {
        r--;
        l++;
      } else {
        a[0] = s[l];
        a[1] = s[r];
        break;
      }
    }
    if (l > r) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < 2; i++) {
      int cnt = fun(a[i]);
      if (cnt != -1) ans = min(ans, cnt);
    }
    if (ans == mmax)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
