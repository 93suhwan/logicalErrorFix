#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
void debug(int cnt, ...) {
  va_list list;
  va_start(list, cnt);
  for (int i = (0); i < (cnt); i++) {
    cout << va_arg(list, int) << "//";
  }
  cout << endl;
}
void init_code() {
  freopen("input.txt", "r", stdin);
  freopen("ouput.txt", "w", stdout);
}
int t, n, m, k;
char a[100][100];
bool vs[100][100], check;
bool solve() {
  for (int i = (n); i >= (1); i--) {
    for (int j = (1); j <= (m); j++) {
      if (a[i][j] == '*') {
        int d = 0;
        while (i - d >= 1 && j - d >= 1 && j + d <= m &&
               a[i - d][j - d] == '*' && a[i - d][j + d] == '*')
          d++;
        if (d <= k && !vs[i][j]) return 0;
        if (d > k) {
          int d = 0;
          while (i - d >= 1 && j - d >= 1 && j + d <= m &&
                 a[i - d][j - d] == '*' && a[i - d][j + d] == '*') {
            d++;
            vs[i - d][j - d] = vs[i - d][j + d] = 1;
          }
        }
      }
    }
  }
  return 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> t; t--;) {
    cin >> n >> m >> k;
    memset(vs, 0, sizeof vs);
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++) cin >> a[i][j];
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
