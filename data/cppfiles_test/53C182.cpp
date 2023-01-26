#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    char c;
    cin >> n >> c;
    string str;
    cin >> str;
    str = " " + str;
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      if (str[i] != c) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << 0 << endl;
      continue;
    }
    ok = 0;
    for (int i = 1; i <= n; i++) {
      bool flag = 1;
      for (int j = i; j <= n; j += i) {
        if (str[j] != c) {
          flag = 0;
          break;
        }
      }
      if (flag == 1) {
        cout << 1 << endl << i << endl;
        ok = 1;
        break;
      }
    }
    if (ok == 0) cout << 2 << endl << n << " " << n - 1 << endl;
  }
  return 0;
}
