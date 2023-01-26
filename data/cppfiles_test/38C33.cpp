#include <bits/stdc++.h>
using namespace std;
long long n, m, N, Left, Right;
long long seg[2000001], vs[2000001];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  char grid[n + 1][m + 1];
  vs[0] = 0;
  set<pair<long long, long long>> d;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (i > 1 && j > 1) {
        if (grid[i - 1][j] == 'X' && grid[i][j - 1] == 'X') {
          vs[j]++;
        }
      }
    }
  }
  for (long long i = 1; i <= m; i++) vs[i] += vs[i - 1];
  long long q;
  cin >> q;
  while (q--) {
    cin >> Left >> Right;
    if (vs[Right] - vs[Left])
      cout << "NO";
    else
      cout << "YES";
    cout << '\n';
  }
  return 0;
}
