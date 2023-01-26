#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    int n = a.size(), m = s.size();
    int i = n - 1, j = m - 1;
    string ans;
    bool o = 0;
    while (i >= 0) {
      if (a[i] > s[j]) {
        if (j == 0 || s[j - 1] != '1') {
          o = 1;
          break;
        } else {
          int ac = 10 * int(s[j - 1] - '0') + int(s[j] - '0');
          int ac2 = int(a[i] - '0');
          int df = ac - ac2;
          string add = to_string(df);
          ans += add;
        }
        i--;
        j -= 2;
      } else {
        int df = int(s[j] - '0') - int(a[i] - '0');
        string add = to_string(df);
        if (!(add == "0" && i == 0 && j == 0)) ans += add;
        i--;
        j--;
      }
      if (i >= 0 && j < 0) {
        o = 1;
        break;
      }
    }
    if (o)
      cout << -1 << '\n';
    else {
      while (j >= 0) ans += s[j--];
      reverse((ans).begin(), (ans).end());
      cout << ans << '\n';
    }
  }
}
