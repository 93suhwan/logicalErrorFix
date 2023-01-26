#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const double eps = 1e-8;
const double pi = acos(-1);
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int cnt = 0;
    bool flag0 = false, flag1 = false, flag2 = false;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') flag0 = true;
      if (s[i] == '1') flag1 = true;
      if (s[i] == '2') flag2 = true;
      if (s[i] == '0' && s[i + 1] != '0') cnt++;
    }
    if (s[s.size() - 1] == '0') cnt++;
    if (!flag0)
      cnt = min(cnt, 0);
    else if (!flag1)
      cnt = min(cnt, 1);
    else if (!flag2)
      cnt = min(cnt, 2);
    cout << cnt << endl;
  }
  return 0;
}
