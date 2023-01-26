#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2005;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
map<char, int> d = {{'R', 0}, {'L', 1}, {'D', 2}, {'U', 3}};
int n, m, dpth[N][N], mem[N][N];
char mat[N][N];
bool check(int x, int y) { return !(x <= 0 || x > n || y <= 0 || y > m); }
pii to(int x, int y) {
  int nx = x + dx[d[mat[x][y]]];
  int ny = y + dy[d[mat[x][y]]];
  return {nx, ny};
}
pair<int, pii> solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mat[i][j];
      mem[i][j] = -1;
    }
  }
  pair<int, pii> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mem[i][j] != -1) continue;
      bool in_cycle = false;
      int x = i;
      int y = j;
      int d = 0;
      stack<pii> st;
      while (check(x, y) && mem[x][y] == -1) {
        mem[x][y] = -2;
        dpth[x][y] = d++;
        st.push({x, y});
        auto [nx, ny] = to(x, y);
        x = nx, y = ny;
      }
      if (mem[x][y] == -2) {
        in_cycle = true;
        mem[x][y] = d - dpth[x][y];
      }
      if (!check(x, y)) {
        mem[x][y] = 0;
      }
      while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        if (mem[x][y] != -2) {
          in_cycle = false;
          continue;
        }
        auto [nx, ny] = to(x, y);
        mem[x][y] = mem[nx][ny];
        if (!in_cycle) mem[x][y]++;
      }
      ans = max(ans, {mem[i][j], {i, j}});
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    auto [l, pos] = solve();
    auto [x, y] = pos;
    cout << x << ' ' << y << ' ' << l << endl;
  }
  return 0;
}
