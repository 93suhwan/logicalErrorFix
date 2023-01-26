#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char a[2][N];
bool s[N];
void solve() {
  int n;
  cin >> n;
  a[0][0] = a[1][0] = '5';
  a[0][n + 1] = a[1][n + 1] = '5';
  memset(s, true, sizeof s);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (a[0][i] == '0' && a[1][i] == '1' || a[0][i] == '1' && a[1][i] == '0') {
      res += 2;
    } else {
      if (a[0][i] == '0' && s[i] == true) {
        if (a[0][i - 1] == '1' && a[1][i - 1] == '1' && s[i - 1] == true) {
          res += 2;
          s[i] = false;
          s[i - 1] = false;
        } else if (a[0][i + 1] == '1' && a[1][i + 1] == '1' &&
                   s[i + 1] == true) {
          res += 2;
          s[i] = false;
          s[i + 1] = false;
        } else if (a[1][i - 1] == '0' && a[0][i - 1] == '0' &&
                   s[i - 1] == true) {
          s[i - 1] = false;
          res++;
        }
      } else if (a[1][i] == '1' && s[i] == true) {
        if (a[1][i - 1] == '0' && a[0][i - 1] == '0' && s[i - 1] == true) {
          res += 2;
          s[i - 1] = false;
          s[i] = false;
        } else if (a[0][i + 1] == '0' && a[1][i + 1] == '0' &&
                   s[i + 1] == true) {
          res += 2;
          s[i + 1] = false;
          s[i] = false;
        }
      }
    }
  }
  if (a[0][n] == '0' && a[1][n] == '0' && s[n] == true) res++;
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
