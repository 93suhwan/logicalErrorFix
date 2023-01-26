#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, x = 0, y = 0;
  cin >> n >> m;
  char ch[n + 2][m + 2];
  for (int i = 0; i <= n + 1; i++) ch[i][0] = '#', ch[i][m + 1] = '#';
  for (int i = 0; i <= m + 1; i++) ch[0][i] = '#', ch[n + 1][i] = '#';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ch[i][j];
      if (ch[i][j] == 'L') x = i, y = j;
    }
  }
  vector<pair<long long, long long> > node;
  for (int i = -1; i <= 1; i += 2) {
    if (ch[x + i][y] == '.') node.push_back({x + i, y});
    if (ch[x][y + i] == '.') node.push_back({x, y + i});
  }
  while (1) {
    vector<pair<long long, long long> > v;
    for (auto it : node) {
      int cnt = 0;
      for (int i = -1; i <= 1; i += 2) {
        if (ch[it.first + i][it.second] == '.') cnt++;
        if (ch[it.first][it.second + i] == '.') cnt++;
      }
      if (cnt <= 1) {
        ch[it.first][it.second] = '+';
        for (int i = -1; i <= 1; i += 2) {
          if (ch[it.first + i][it.second] == '.')
            v.push_back({it.first + i, it.second});
          if (ch[it.first][it.second + i] == '.')
            v.push_back({it.first, it.second + i});
        }
      }
    }
    if ((long long)(v).size() == 0) break;
    node = v;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << ch[i][j];
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
