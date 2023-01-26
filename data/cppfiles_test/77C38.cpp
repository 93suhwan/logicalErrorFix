#include <bits/stdc++.h>
using namespace std;
int d[1001][1001];
bool visited[1001][1001];
int n, m;
int cnt = 0;
void visit(int x, int y) {
  if (visited[x][y]) return;
  visited[x][y] = true;
  cnt++;
  if (!(d[x][y] & 4) && y + 1 <= m) visit(x, y + 1);
  if (!(d[x][y] & 2) && x + 1 <= n) visit(x + 1, y);
  if (!(d[x][y] & 1) && y - 1 >= 1) visit(x, y - 1);
  if (!(d[x][y] & 8) && x - 1 >= 1) visit(x - 1, y);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> d[i][j];
      visited[i][j] = false;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!visited[i][j]) {
        cnt = 0;
        visit(i, j);
        ans.push_back(cnt);
      }
    }
  }
  std::sort(ans.begin(), ans.end());
  for (int i = (ans.size() - 1); i >= 0; --i) cout << ans[i] << ' ';
  cout << '\n';
}
