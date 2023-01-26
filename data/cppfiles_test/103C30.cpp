#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
const int MXINF = 0x3f3f3f3f;
const int MNINF = 0x7f7f7f7f;
const ull MOD = 1000000007;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mp;
  mp.resize(n);
  for (int i = 0; i < n; i++) mp[i].resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> mp[i][j];
  }
  vector<vector<int>> type;
  type.resize(n);
  for (int i = 0; i < n; i++) type[i].resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) type[i][j] = -1;
  }
  vector<vector<int>> d;
  d.resize(n);
  for (int i = 0; i < n; i++) d[i].resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) d[i][j] == 4e6 + 5;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (type[i][j] == -1) {
        vector<pii> path;
        int x = i, y = j;
        bool ob = false;
        while (type[x][y] == -1) {
          type[x][y] = 0;
          path.push_back(make_pair(x, y));
          if (mp[x][y] == 'U')
            x -= 1;
          else if (mp[x][y] == 'D')
            x += 1;
          else if (mp[x][y] == 'L')
            y -= 1;
          else
            y += 1;
          if (x < 0 || x >= n || y < 0 || y >= m) {
            ob = true;
            break;
          }
        }
        int np = path.size();
        if (ob) {
          for (int i = 0; i < np; i++) {
            d[path[i].first][path[i].second] = np - i;
            type[path[i].first][path[i].second] = 1;
          }
        } else {
          if (type[x][y] == 0) {
            int val = np;
            int pos;
            for (int i = 0; i < np; i++) {
              if (path[i].first == x && path[i].second == y) {
                pos = i;
                break;
              }
              d[path[i].first][path[i].second] = val;
              type[path[i].first][path[i].second] = 1;
              val--;
            }
            for (int i = pos; i < np; i++) {
              d[path[i].first][path[i].second] = val;
              type[path[i].first][path[i].second] = 1;
            }
          } else if (type[x][y] == 1) {
            for (int i = 0; i < np; i++) {
              d[path[i].first][path[i].second] = np - i + d[x][y];
              type[path[i].first][path[i].second] = 1;
            }
          }
        }
      }
    }
  }
  int ansr = 0, ansc = 0;
  int ansd = d[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d[i][j] > ansd) {
        ansr = i;
        ansc = j;
        ansd = d[i][j];
      }
    }
  }
  cout << ansr + 1 << " " << ansc + 1 << " " << ansd << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
