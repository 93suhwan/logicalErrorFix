#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 8e3 + 5;
const int inf = 1e9 + 5;
const long long mod = 998244353;
const double eps = 1e-13;
const double pi = acos(-1.0);
const int S = 100;
inline long long read() {
  long long x = 0, t = 1;
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') t = -1;
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * t;
}
int xx[] = {0, 0, -1, 1};
int yy[] = {1, -1, 0, 0};
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i][j] == 'L') q.push(make_pair(i, j));
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      if (a[x][y] == 'L') {
        for (int i = 0; i < 4; i++) {
          int dx = x + xx[i];
          int dy = y + yy[i];
          if (dx && dy && dx <= n && dy <= m && a[dx][dy] == '.')
            q.push(make_pair(dx, dy));
        }
      } else {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
          int dx = x + xx[i];
          int dy = y + yy[i];
          if (dx && dy && dx <= n && dy <= m && a[dx][dy] == '.') cnt++;
        }
        if (cnt <= 1) {
          a[x][y] = '+';
          for (int i = 0; i < 4; i++) {
            int dx = x + xx[i];
            int dy = y + yy[i];
            if (dx && dy && dx <= n && dy <= m && a[dx][dy] == '.')
              q.push(make_pair(dx, dy));
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << a[i][j];
      cout << "\n";
    }
  }
  return 0;
}
