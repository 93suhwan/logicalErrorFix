#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
string s[2000010];
const int way[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int edgecnt[2000010];
queue<pair<int, int>> q;
void bfs() {
  pair<int, int> tmp = q.front();
  q.pop();
  int i = tmp.first, j = tmp.second;
  for (int k = 0; k < 4; k++) {
    int ii = i + way[k][0], jj = j + way[k][1];
    if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
      int tt = ii * m + jj;
      if (s[ii][jj] == '.' && edgecnt[tt] >= 1) {
        edgecnt[tt]--;
        if (edgecnt[tt] <= 1) {
          edgecnt[tt] = 0;
          q.push(make_pair(ii, jj));
        }
      }
    }
  }
  if (s[i][j] != 'L') s[i][j] = '+';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> t;
  while (t--) {
    while (!q.empty()) q.pop();
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) edgecnt[i] = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == '.' || s[i][j] == 'L')
          for (int k = 0; k < 4; k++) {
            int ii = i + way[k][0], jj = j + way[k][1];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m &&
                (s[ii][jj] == '.' || s[ii][jj] == 'L'))
              edgecnt[i * m + j]++;
          }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == 'L') {
          q.push(make_pair(i, j));
          edgecnt[i * m + j] = 0;
        }
    while (!q.empty()) bfs();
    for (int i = 0; i < n; i++) cout << s[i] << '\n';
  }
  return 0;
}
