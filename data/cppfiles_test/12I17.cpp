#include <bits/stdc++.h>
using namespace std;
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};
int dist[2002][2002];
bool vis[2002][2002];
vector<int> pt[2002][2002];
int n, m;
int conv(int i, int j) { return i * m + j; }
bool is_valid(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return false;
  return true;
}
int disn(int a, int b, int c, int d) {
  return (a - c) * (a - c) + (b - d) * (b - d);
}
int dis(int a, int b, int c, int d) {
  int ans = INT_MAX;
  for (auto x : pt[c][d]) {
    ans = min(ans, disn(a, b, x / m, x % m));
  }
  return ans;
}
int solve() {
  cin >> n >> m;
  n++;
  m++;
  set<pair<int, int> > st;
  char x;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      cin >> x;
      if (x == '1') {
        st.insert({0, conv(i, j)});
        dist[i][j] = 0;
        pt[i][j].push_back(i * m + j);
      }
    }
  }
  int ans = 0;
  while (!st.empty()) {
    auto xf = st.begin();
    ans += xf->first;
    int x = xf->second / m;
    int y = xf->second % m;
    st.erase(xf);
    for (int i = 0; i < 4; i++) {
      int nx = x + xx[i];
      int ny = y + yy[i];
      if (!is_valid(nx, ny) || dist[nx][ny] <= dist[x][y]) continue;
      int xd = dis(nx, ny, x, y);
      if (xd < dist[nx][ny]) {
        st.erase({dist[nx][ny], conv(nx, ny)});
        dist[nx][ny] = xd;
        st.insert({dist[nx][ny], conv(nx, ny)});
        pt[nx][ny].clear();
        for (auto xo : pt[x][y]) {
          if (disn(nx, ny, xo / m, xo % m) == xd) pt[nx][ny].push_back(xo);
        }
      } else if (xd == dist[nx][ny]) {
        for (auto xo : pt[nx][ny]) {
          vis[xo / m][xo % m] = true;
        }
        for (auto xo : pt[x][y]) {
          if (vis[xo / m][xo % m] == false &&
              disn(nx, ny, xo / m, xo % m) == xd)
            pt[nx][ny].push_back(xo);
        }
        for (auto xo : pt[nx][ny]) {
          vis[xo / m][xo % m] = false;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
int main() {
  fill(dist[0], dist[0] + 2002 * 2002, INT_MAX);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  { solve(); }
}
