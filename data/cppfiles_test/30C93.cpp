#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int t;
int n;
char s1[100010];
int flag[30];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(s1, 0, sizeof s1);
    memset(flag, 1, sizeof flag);
    cin >> n;
    cin >> s1;
    for (char c = 'a'; c <= 'z'; c++) {
      int c1 = 0, c2 = n - 1;
      while (c1 < c2) {
        while (c1 < n && s1[c1] == c) c1++;
        while (c2 >= 0 && s1[c2] == c) c2--;
        if (c1 >= c2) break;
        if (s1[c1] == s1[c2])
          c1++, c2--;
        else {
          flag[c - 'a'] = 0;
          break;
        }
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 26; i++) {
      if (flag[i] == 0) continue;
      int c1 = 0, c2 = n - 1;
      int s = 0;
      while (c1 <= c2) {
        if (s1[c1] == s1[c2])
          c1++, c2--;
        else {
          if (s1[c1] == 'a' + i)
            c1++, s++;
          else
            c2--, s++;
        }
      }
      ans = min(ans, s);
    }
    if (ans == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
