#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c1, c2;
    int f = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        c1 = s[i];
        c2 = s[j];
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << 0 << '\n';
      continue;
    }
    int now = 0;
    int ans = 0;
    f = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        if (s[i] == c1) {
          now += 1;
          j += 1;
        } else if (s[j] == c1) {
          now += 1;
          i -= 1;
        } else {
          f = 1;
          break;
        }
      }
    }
    int ff = 0;
    ans = now;
    now = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        if (s[i] == c2) {
          now += 1;
          j += 1;
        } else if (s[j] == c2) {
          now += 1;
          i -= 1;
        } else {
          ff = 1;
          break;
        }
      }
    }
    ans = max(now, ans);
    if (f && ff)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
