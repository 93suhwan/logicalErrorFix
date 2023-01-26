#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '0') {
        if (i <= n / 2) {
          cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << endl;
          flag = true;
          break;
        } else {
          cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << endl;
          flag = true;
          break;
        }
      }
    }
    int sz = n / 2;
    if (!flag)
      cout << 1 << ' ' << 1 + sz - 1 << ' ' << n - sz + 1 << ' ' << n << endl;
  }
}
