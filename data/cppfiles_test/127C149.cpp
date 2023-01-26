#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
string s, t;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  while (n--) {
    cin >> s >> t;
    int a = 0, b = 0, c = 0, ind;
    for (int j = 0; j < s.size(); ++j) {
      char i = s[j];
      if (i == 'a') ++a;
      if (i == 'b') {
        ++b;
      }
      if (i == 'c') ++c;
    }
    sort(s.begin(), s.end());
    if (t == "abc" && b > 0 && c > 0 && a > 0) {
      string ans;
      for (char i : s) {
        if (i != 'b') {
          ans += i;
        }
      }
      int i;
      for (i = ans.size() - 1; i > 0; --i) {
        if (ans[i] == 'c') {
          i++;
          break;
        }
      }
      if (i == ans.size()) {
        s = ans + string(b, 'b');
      } else {
        s = ans.substr(0, i) + string(b, 'b') + ans.substr(i);
      }
    }
    cout << s << endl;
  }
  return 0;
}
