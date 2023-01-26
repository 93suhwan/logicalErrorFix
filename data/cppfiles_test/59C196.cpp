#include <bits/stdc++.h>
using namespace std;
const int dir[5] = {0, -1, 0, 1, 0};
const int N = 2e3 + 7;
const int M = 1e4 + 7;
const int oo = 1e9;
const int MOD = 1000000007;
using namespace std;
int t, n, d[4], a[N][6];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= 5; ++j) cin >> a[i][j];
    bool res = false;
    for (int l = 1; l <= 4; ++l)
      for (int r = l + 1; r <= 5; ++r) {
        d[1] = d[2] = d[3] = 0;
        for (int i = 1; i <= n; ++i)
          if (a[i][l] & a[i][r])
            ++d[3];
          else if (a[i][l])
            ++d[1];
          else if (a[i][r])
            ++d[2];
        res |= (d[1] <= (n / 2) && d[2] <= (n / 2) && d[1] + d[2] + d[3] == n);
      }
    cout << (res ? "YES\n" : "NO\n");
  }
}
