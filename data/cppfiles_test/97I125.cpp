#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
struct node {
  int x, y;
};
int n, m, deg[N][N], sum[N][N], val[N][N];
int dis[N * N], fa[N * N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string s[N];
int in(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
int find(int x) {
  if (fa[x] == x) return x;
  int anc = find(fa[x]);
  dis[x] ^= dis[fa[x]];
  return fa[x] = anc;
}
void con(int x, int y) {
  sum[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (!in(nx, ny)) return;
    sum[x][y] += val[nx][ny];
  }
  return;
}
int merge(int x, int y, int v) {
  find(x), find(y);
  v ^= dis[x] ^ dis[y];
  x = find(x), y = find(y);
  if (x == y) {
    if (v == 0) return 1;
    return 0;
  }
  dis[x] = v, fa[x] = y;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) fa[i] = i, dis[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (!in(x, y)) continue;
        if (s[i][j] != s[x][y]) {
          deg[i][j]++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X' && deg[i][j] % 2 == 1) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != 'X') continue;
      vector<int> x, y;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (!in(nx, ny) || s[nx][ny] == 'X') continue;
        x.push_back(nx), y.push_back(ny);
      }
      for (int i = 0; i < int((x).size()); i += 2) {
        cout << x[i] << " " << y[i] << " " << x[i + 1] << " " << y[i + 1]
             << endl;
        assert(merge(((x[i]) * m + y[i]), ((x[i + 1]) * m + y[i + 1]), 1));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') continue;
      find(((i)*m + j));
      sum[i][j] = val[i][j] = 1 + dis[((i)*m + j)] * 3;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') con(i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
