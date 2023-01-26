#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
using namespace std;
int main() {
  int ncase;
  cin >> ncase;
  while (ncase--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss;
    ss = s;
    sort(ss.begin(), ss.end());
    if (ss[0] == '1') {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
      continue;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        flag = i;
        break;
      }
    }
    flag++;
    if (flag < n / 2 + 1)
      cout << flag << " " << n << " " << flag + 1 << " " << n << "\n";
    else
      cout << 1 << " " << flag << " " << 1 << " " << flag - 1 << "\n";
  }
  return 0;
}
