#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int inf = 0x3fffffff;
const ll INF = 0x1fffffffffffffff;
const double eps = 1e-12;
template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void solve(int _rot) {
  int n, m;
  cin >> n >> m;
  string g[n];
  for (int i = (int)(0); i < (int)(n); i++) cin >> g[i];
  using P = pair<int, int>;
  queue<P> que;
  for (int i = (int)(0); i < (int)(n); i++)
    for (int j = (int)(0); j < (int)(m); j++)
      if (g[i][j] == 'L') {
        que.push({i, j});
        break;
      }
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    for (int k = (int)(0); k < (int)(4); k++) {
      int tx = x + dx[k], ty = y + dy[k];
      if (tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
      if (g[tx][ty] == '#' or g[tx][ty] == 'L' or g[tx][ty] == '+') continue;
      int cnt = 0;
      for (int l = (int)(0); l < (int)(4); l++) {
        int lx = tx + dx[l], ly = ty + dy[l];
        if (lx < 0 or lx >= n or ly < 0 or ly >= m) continue;
        if (g[lx][ly] == '#') continue;
        if (g[lx][ly] == '.') cnt++;
      }
      if (cnt <= 1) {
        g[tx][ty] = '+';
        que.push({tx, ty});
      }
    }
  }
  for (int i = (int)(0); i < (int)(n); i++) cout << g[i] << '\n';
}
int main() {
  int t;
  scanf("%d", &t);
  for (int rot = (int)(0); rot < (int)(t); rot++) solve(rot + 1);
  return 0;
}
