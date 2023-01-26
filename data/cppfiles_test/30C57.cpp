#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3F3F3F3F;
const int N = 200000 + 5;
int main() {
  long long t, n;
  cin >> t;
  string s;
  while (t--) {
    cin >> n;
    cin >> s;
    long long ans = -1;
    for (int i = 0; i < 26; i++) {
      int l = 0, r = n - 1;
      char c = 'a' + i;
      long long noww = 0;
      while (l <= r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else {
          if (s[l] == c) {
            noww++;
            l++;
          } else if (s[r] == c) {
            noww++;
            r--;
          } else {
            noww = -1;
            break;
          }
        }
      }
      if (noww != -1) ans = max(ans, n - noww);
    }
    if (ans == -1)
      cout << -1 << '\n';
    else
      cout << n - ans << '\n';
  }
  return 0;
}
