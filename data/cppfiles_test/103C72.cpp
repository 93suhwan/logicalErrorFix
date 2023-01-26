#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;
int H, W, dis[MAXN][MAXN], vis[MAXN][MAXN], dcnt;
char str[MAXN][MAXN];
void work(int sx, int sy) {
  dcnt++;
  int cx = sx, cy = sy;
  vector<int> vec;
  bool mod = false;
  int rec = 0;
  while (1) {
    vec.push_back(cx * W + cy);
    vis[cx][cy] = dcnt;
    int nx = cx, ny = cy;
    if (str[cx][cy] == 'L') ny--;
    if (str[cx][cy] == 'R') ny++;
    if (str[cx][cy] == 'U') nx--;
    if (str[cx][cy] == 'D') nx++;
    if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
      mod = true;
      rec = 0;
      break;
    }
    if (vis[nx][ny] == dcnt) {
      mod = false;
      rec = nx * W + ny;
      break;
    } else if (vis[nx][ny]) {
      mod = true;
      rec = dis[nx][ny];
      break;
    }
    cx = nx, cy = ny;
  }
  if (mod == false) {
    int len = 0;
    for (int i = (vec.size()) - 1, iend = (0); i >= iend; --i) {
      len++;
      if (vec[i] == rec) break;
    }
    bool ou = false;
    while (!vec.empty()) {
      int x = vec.back() / W, y = vec.back() % W;
      if (ou) len++;
      dis[x][y] = len;
      if (vec.back() == rec) ou = true;
      vec.pop_back();
    }
  } else {
    for (int i = (vec.size()) - 1, iend = (0); i >= iend; --i)
      dis[vec[i] / W][vec[i] % W] = ++rec;
  }
}
void solve() {
  scanf("%d %d", &H, &W);
  for (int i = (0), iend = (H); i < iend; ++i) scanf("%s", str[i]);
  for (int i = (0), iend = (H); i < iend; ++i)
    for (int j = (0), jend = (W); j < jend; ++j) dis[i][j] = 0, vis[i][j] = 0;
  dcnt = 0;
  for (int i = (0), iend = (H); i < iend; ++i)
    for (int j = (0), jend = (W); j < jend; ++j)
      if (vis[i][j] == 0) work(i, j);
  int mx = 0;
  for (int i = (0), iend = (H); i < iend; ++i)
    for (int j = (0), jend = (W); j < jend; ++j) mx = max(mx, dis[i][j]);
  for (int i = (0), iend = (H); i < iend; ++i)
    for (int j = (0), jend = (W); j < jend; ++j)
      if (mx == dis[i][j])
        return printf("%d %d %d\n", i + 1, j + 1, dis[i][j]), void();
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
