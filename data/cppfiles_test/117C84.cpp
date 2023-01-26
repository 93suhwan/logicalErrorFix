#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t, n, m, x, y;
vector<int> s[N], v[N];
queue<pair<int, int>> Q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 1 && a <= n && b >= 1 && b <= m) {
      if (s[a][b] != 1) continue;
      if (!v[a][b]) cnt++;
    }
  }
  return cnt <= 1;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      s[i].clear(), v[i].clear(), s[i].resize(m + 1), v[i].resize(m + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == 'L')
          x = i, y = j;
        else if (c == '#')
          s[i][j] = 2;
        else
          s[i][j] = 1;
      }
    Q.push({x, y});
    v[x][y] = 1;
    while (Q.size()) {
      auto k = Q.front();
      Q.pop();
      int a = k.first, b = k.second;
      for (int i = 0; i < 4; i++) {
        int A = a + dx[i], B = b + dy[i];
        if (A >= 1 && A <= n && B >= 1 && B <= m) {
          if (v[A][B] || s[A][B] == 2) continue;
          if (check(A, B)) {
            v[A][B] = 1;
            Q.push({A, B});
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == x && j == y)
          cout << 'L';
        else {
          if (v[i][j])
            cout << '+';
          else if (s[i][j] == 2)
            cout << '#';
          else
            cout << '.';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
