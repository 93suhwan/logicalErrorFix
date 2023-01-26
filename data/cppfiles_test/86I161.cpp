#include <bits/stdc++.h>
using namespace std;
bool st[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(st, false, sizeof st);
    int n;
    cin >> n;
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int ans = 0;
    if (str1[0] != str2[0]) ans += 2;
    for (int i = 1; i < str1.size(); i++) {
      if (str1[i] != str2[i]) {
        ans += 2;
      } else {
        if (!st[i - 1] && !st[i] && str1[i] != str1[i - 1] &&
            str1[i - 1] == str2[i - 1]) {
          ans += 2;
          st[i - 1] = 1;
          st[i] = 1;
        } else if (i + 1 < str1.size() && !st[i + 1] && !st[i] &&
                   str1[i] != str1[i + 1] && str1[i + 1] == str2[i + 1]) {
          ans += 2;
          st[i + 1] = 1;
          st[i] = 1;
        } else {
          if (!st[i] && str1[i] == '0') {
            ans += 1;
            st[i] = 1;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
