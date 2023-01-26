#include <bits/stdc++.h>
using namespace std;
const long long N = 510;
long long n, m;
char mp[N][N];
long long ans[N][N];
long long dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  long long p = 0;
  for (long long i = 1; i <= n; i++) {
    p = 0;
    for (long long j = 1; j <= m; j++) {
      if (mp[i][j] == 'X') {
        p ^= (mp[i - 1][j] == 'X');
        long long cnt = 0;
        for (long long k = 0; k < 4; k++) {
          if (mp[i + dx[k]][j + dy[k]] == '.') cnt++;
        }
        if (cnt & 1) {
          cout << "NO" << endl;
          return 0;
        }
      } else {
        ans[i][j] = ((j + p) & 1) ? 1 : 4;
      }
    }
  }
  cout << "YES" << endl;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (mp[i][j] == 'X') {
        long long s = 0;
        for (long long k = 0; k < 4; k++) {
          if (mp[i + dx[k]][j + dy[k]] == '.') s += ans[i + dx[k]][j + dy[k]];
        }
        cout << s << ' ';
      } else
        cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
