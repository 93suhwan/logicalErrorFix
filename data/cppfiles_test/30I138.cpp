#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int solve(char c) {
  int l = 0, r = n - 1;
  int ret = 0;
  while (l < r) {
    if (s[l] != s[r]) {
      if (s[l] == c) {
        l++;
        ret++;
        continue;
      } else if (s[r] == c) {
        r--;
        ret++;
      } else
        return -1;
    }
    l++;
    r--;
  }
  return ret;
}
int main(void) {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int ans = n + 9;
    int temp;
    for (char c = 'a'; c <= 'z'; c++) {
      temp = solve(c);
      if (temp >= 0) ans = min(ans, temp);
    }
    if (ans > n)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
