#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if ((int)s.size() == 1) {
      cout << (s[0] == '0') << "\n";
      continue;
    }
    int res = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        res += (s[i - 1] == '0');
        continue;
      }
      if (i == (int)s.size() - 1) {
        res += (s[i] == '0');
      }
    }
    cout << min(res, 2) << "\n";
  }
}
