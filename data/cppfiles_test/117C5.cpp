#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string s[N];
bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m && s[x - 1][y - 1] == '.';
}
void solve() {
  scanf("%d%d", &n, &m);
  pair<int, int> st;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == 'L') {
        st.first = i + 1;
        st.second = j + 1;
      }
  queue<pair<int, int> > q;
  q.push(st);
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (!check(x, y)) continue;
      int cnt = 0;
      for (int j = 0; j < 4; j++) {
        int xx = x + dx[j], yy = y + dy[j];
        if (check(xx, yy)) cnt++;
      }
      if (cnt <= 1) {
        s[x - 1][y - 1] = '+';
        q.push({x, y});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%c", s[i][j]);
    puts("");
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
