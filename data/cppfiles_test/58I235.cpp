#include <bits/stdc++.h>
using namespace std;
const int Max = 3e5 + 100;
const long long Mod = 1e9 + 7;
char a[3][110];
int main() {
  int t;
  int n, x;
  cin >> t;
  bool k = 0;
  while (t--) {
    k = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[1][i];
    for (int i = 1; i <= n; ++i) cin >> a[2][i];
    for (int i = 2; i <= n; ++i) {
      if (a[1][i] == '1' && a[2][i] == '1' && a[2][i - 1] == '1') {
        k = 1;
        break;
      }
    }
    if (k)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
