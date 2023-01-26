#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
bool ok[11][20];
string s[11];
long long n, m, d;
void check(long long i, long long j) {
  long long row = i, col = j, flag = 0;
  for (long long p = 1; p <= 23; p++) {
    if (row - p <= 0) break;
    if (col - p <= 0 or col + p > m) break;
    if ((s[row - p][col - p] != s[row - p][col + p]) or
        (s[row - p][col - p] == '.')) {
      break;
    }
    flag++;
  }
  if (flag >= d) {
    for (long long i = 0; i <= flag; i++) {
      ok[row - i][col - i] = ok[row - i][col + i] = 1;
    }
  }
}
void print() {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (ok[i][j] == false and s[i][j] == '*') {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
void solve() {
  cin >> n >> m >> d;
  memset(ok, 0, sizeof(ok));
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (s[i][j] == '*') {
        check(i, j);
      }
    }
  }
  print();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
