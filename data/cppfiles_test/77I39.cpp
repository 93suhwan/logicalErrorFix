#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 5;
int n, m, res;
string g[maxN][maxN];
int visit[maxN][maxN];
vector<int> ans;
void floodfill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || visit[i][j]) return;
  visit[i][j] = 1;
  ++res;
  int north = g[i][j][0] - '0';
  int east = g[i][j][1] - '0';
  int south = g[i][j][2] - '0';
  int west = g[i][j][3] - '0';
  if (!north) floodfill(i - 1, j);
  if (!east) floodfill(i, j + 1);
  if (!south) floodfill(i + 1, j);
  if (!west) floodfill(i, j - 1);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      int k;
      cin >> k;
      string s;
      s += '0' + char(k & 8);
      s += '0' + char(k & 4);
      s += '0' + char(k & 2);
      s += '0' + char(k & 1);
      cout << s << ' ';
      g[i][j] = s;
    }
    cout << '\n';
  }
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      res = 0;
      floodfill(i, j);
      if (res) ans.push_back(res);
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for (auto& x : ans) cout << x << ' ';
}
