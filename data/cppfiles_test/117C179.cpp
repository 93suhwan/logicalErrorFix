#include <bits/stdc++.h>
using namespace std;
long long dx[4] = {0, 0, 1, -1};
long long dy[4] = {1, -1, 0, 0};
long long n, m;
const long long N = 1e6 + 5;
string grid[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    pair<long long, long long> st;
    for (long long i = 0; i < n; i++) {
      cin >> grid[i];
      for (long long j = 0; j < grid[i].length(); j++) {
        if (grid[i][j] == 'L') {
          st.first = i;
          st.second = j;
        }
      }
    }
    deque<pair<long long, long long>> q;
    for (long long i = 0; i < 4; i++) {
      long long nx = st.first + dx[i];
      long long ny = st.second + dy[i];
      if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
      if (grid[nx][ny] == 'L') continue;
      if (grid[nx][ny] == '+') continue;
      if (grid[nx][ny] == '#') continue;
      q.push_back({nx, ny});
    }
    while (q.size()) {
      pair<long long, long long> cur = q.front();
      q.pop_front();
      long long cnt = 0;
      for (long long j = 0; j < 4; j++) {
        long long nx = cur.first + dx[j];
        long long ny = cur.second + dy[j];
        if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
        if (grid[nx][ny] == 'L') continue;
        if (grid[nx][ny] == '+') continue;
        if (grid[nx][ny] == '#') continue;
        if (grid[nx][ny] == '.') cnt++;
      }
      if (cnt >= 2) continue;
      grid[cur.first][cur.second] = '+';
      for (long long j = 0; j < 4; j++) {
        long long nx = cur.first + dx[j];
        long long ny = cur.second + dy[j];
        if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
        if (grid[nx][ny] == 'L') continue;
        if (grid[nx][ny] == '+') continue;
        if (grid[nx][ny] == '#') continue;
        if (grid[nx][ny] == '.') q.push_back({nx, ny});
      }
    }
    for (long long i = 0; i < n; i++) cout << grid[i] << "\n";
  }
  return 0;
}
