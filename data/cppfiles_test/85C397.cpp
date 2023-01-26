#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.size();
    int num = 0;
    if (s[0] == '0') num++;
    for (int i = 1; i < len; i++) {
      if (s[i] == '0' && s[i - 1] != '0') num++;
    }
    cout << min(2, num) << endl;
  }
  return 0;
}
