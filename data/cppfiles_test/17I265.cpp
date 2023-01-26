#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 10;
const double PI = 3.1415926535898;
const long long mod = 1e9 + 7;
using namespace std;
int r[N][6];
void sovle() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> r[i][j];
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  int res = 1;
  int ok = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int tmp = 0;
      for (int k = 1; k <= 5; k++) {
        if (r[i][k] < r[j][k]) tmp++;
      }
      if (tmp >= 3) {
        cnt++;
      } else
        break;
    }
    if (cnt == n - 1) {
      res = i;
      ok++;
    }
  }
  if (ok) {
    ok == 1 ? cout << res << '\n' : cout << ok << '\n';
  } else
    cout << -1 << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    sovle();
  }
  return 0;
}
