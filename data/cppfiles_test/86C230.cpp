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
    for (int i = 0; i < str1.size(); i++) {
      if (str1[i] != str2[i]) {
        ans += 2;
        st[i] = true;
      } else {
        if (!st[i] && str1[i] == '0') {
          if (i - 1 >= 0 && !st[i - 1] && str1[i - 1] == '1' &&
              str2[i - 1] == '1') {
            ans += 2;
            st[i - 1] = true;
            st[i] = true;
          } else if (i + 1 < n && !st[i + 1] && str1[i + 1] == '1' &&
                     str2[i + 1] == '1') {
            ans += 2;
            st[i + 1] = true;
            st[i] = true;
          } else if (!st[i]) {
            ans += 1;
            st[i] = true;
          }
        } else if (!st[i]) {
          if (i - 1 >= 0 && !st[i - 1] && str1[i - 1] == '0' &&
              str2[i - 1] == '0') {
            ans += 2;
            st[i - 1] = true;
            st[i] = true;
          } else if (i + 1 < n && !st[i + 1] && str1[i + 1] == '0' &&
                     str2[i + 1] == '0') {
            ans += 2;
            st[i + 1] = true;
            st[i] = true;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
