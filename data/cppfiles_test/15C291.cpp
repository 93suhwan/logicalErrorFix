#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 998244353;
const long long inf = 1e18 + 1;
const long long INF = 1e9;
void solve() {
  long long n, m, d;
  cin >> n >> m >> d;
  char ch[n][m];
  long long a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> ch[i][j];
      if (ch[i][j] == '*')
        a[i][j] = -1;
      else
        a[i][j] = 0;
    }
  }
  for (long long i = n - 1; i > 0; i--) {
    for (long long j = 0; j < m; j++) {
      if (ch[i][j] == '*') {
        long long cnt1 = 0, cnt2 = 0;
        long long ii = i, jj = j;
        while (ii >= 0 && jj >= 0 && ch[ii][jj] == '*') {
          cnt1++;
          ii--;
          jj--;
        }
        ii = i, jj = j;
        while (ii >= 0 && jj < m && ch[ii][jj] == '*') {
          cnt2++;
          ii--;
          jj++;
        }
        cnt1 = min(cnt1, cnt2);
        cnt2 = min(cnt1, cnt2);
        if (cnt1 - 1 < d) {
          continue;
        }
        ii = i, jj = j;
        while (ii >= 0 && jj >= 0 && cnt1) {
          cnt1--;
          a[ii][jj] = 0;
          ii--;
          jj--;
        }
        ii = i, jj = j;
        while (ii >= 0 && jj < m && cnt2) {
          cnt2--;
          a[ii][jj] = 0;
          ii--;
          jj++;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == -1) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
