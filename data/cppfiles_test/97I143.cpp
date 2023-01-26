#include <bits/stdc++.h>
using namespace std;
const long long N = 510;
long long n, m;
char mp[N][N];
long long ans[N][N];
long long dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool solve(long long first, long long second) {
  long long cnt = 0;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < 4; i++) {
    long long nx = first + dx[i];
    long long ny = second + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mp[nx][ny] == '.') {
      cnt++;
      v.push_back({nx, ny});
    }
  }
  if (cnt && cnt % 2) return false;
  if (cnt == 2) {
    ans[v[0].first][v[0].second] = 1;
    ans[v[1].first][v[1].second] = 4;
    ans[first][second] = 5;
  } else if (cnt == 4) {
    for (long long i = 0; i < 4; i++) {
      if (i % 2)
        ans[v[i].first][v[i].second] = 1;
      else
        ans[v[i].first][v[i].second] = 4;
    }
    ans[first][second] = 10;
  } else if (cnt == 0) {
    ans[first][second] = 0;
  }
  return true;
}
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (mp[i][j] == 'X') {
        if (!solve(i, j)) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (mp[i][j] == '.' && !ans[i][j]) ans[i][j] = 1;
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
