#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char a[2][N];
bool s[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  memset(s, true, sizeof s);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[1][i] == '0' && a[2][i] == '1' ||
        a[1][i] == '1' && a[2][i] == '0' && s[i] == true) {
      sum += 2;
      s[i] = false;
      continue;
    }
    if (a[1][i] == '0' && a[2][i] == '0' && s[i] == true) {
      if (a[1][i - 1] == '0' && a[2][i - 1] == '0') {
        sum++;
        s[i - 1] = false;
      } else if (a[1][i - 1] == '1' && a[2][i - 1] == '1' && s[i - 1] == true) {
        sum += 2;
        s[i - 1] = false;
        s[i] = false;
      }
    }
  }
  if (a[1][n] == '0' && a[2][n] == '0' && a[1][n - 1] == '0' &&
      a[2][n - 1] == '0')
    sum++;
  else if (a[1][n] == '1' && a[2][n] == '1' && a[1][n - 1] == '0' &&
           a[2][n - 1] == '0' && s[n - 1] == true) {
    sum += 2;
  }
  cout << sum << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
