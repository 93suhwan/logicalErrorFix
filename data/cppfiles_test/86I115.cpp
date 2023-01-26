#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char a[2][N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[1][i] == '0' && a[2][i] == '1' || a[1][i] == '1' && a[2][i] == '0') {
      sum += 2;
      continue;
    }
    if (a[1][i] == '0') {
      if (a[1][i + 1] == '1' && a[2][i + 1] == '1') {
        sum += 2;
        i++;
      } else if (a[1][i + 1] == '0' && a[2][i + 1] == '0') {
        sum++;
      } else if (a[1][i + 1] == '0' && a[2][i + 1] == '1' ||
                 a[1][i + 1] == '1' && a[2][i + 1] == '0')
        sum++;
    } else if (a[1][i] == '1') {
      if (a[1][i + 1] == '0' && a[2][i + 1] == '0') {
        i++;
        sum += 2;
      }
    }
    if (i == n) {
      if (a[1][i] == '0' && a[2][i] == '0') {
        sum++;
      }
    }
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
