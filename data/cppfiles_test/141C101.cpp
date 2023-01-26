#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int len1 = a.size(), len2 = b.size();
    int i = len1 - 1, j = len2 - 1;
    string ans;
    bool ok = true;
    while (1) {
      if (a[i] <= b[j]) {
        char ch = (char)(b[j] - a[i] + '0');
        if (!(ch >= '0' && ch <= '9')) {
          ok = false;
          break;
        }
        ans = ch + ans;
        i--;
        j--;
      } else {
        if (j < 1) {
          ok = false;
          break;
        }
        char ch =
            (char)((b[j] - '0') + ((b[j - 1] - '0') * 10) - (a[i] - '0') + '0');
        if (!(ch >= '0' && ch <= '9')) {
          ok = false;
          break;
        }
        ans = ch + ans;
        i--;
        j -= 2;
      }
      if (i < 0 || j < 0) {
        if (i < 0 && j < 0) {
          ok = true;
          break;
        } else if (j < 0) {
          ok = false;
          break;
        } else if (i < 0) {
          ans = b.substr(0, j + 1) + ans;
          break;
        }
      }
    }
    if (ok) {
      int i = 0;
      while (ans[i] == '0') {
        i++;
      }
      cout << ans.substr(i) << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
