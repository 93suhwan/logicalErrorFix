#include <bits/stdc++.h>
using namespace std;
inline bool valid(int x, int n) { return 0 <= x && x < n; }
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
template <typename T>
inline T pop(queue<T>& q) {
  T front = q.front();
  q.pop();
  return front;
}
template <typename T>
inline T gcd(T a, T b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
template <typename T>
tuple<T, T, T> xgcd(T a, T b) {
  if (b == 0) return {1, 0, a};
  T x, y, g;
  tie(x, y, g) = xgcd(b, a % b);
  return {y, x - (a / b) * y, g};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    queue<int> qy;
    queue<int> qx;
    vector<vector<int> > visit(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'L') {
          visit[i][j] = 1;
          qy.push(i);
          qx.push(j);
        }
      }
    }
    while (qy.size()) {
      int cy = qy.front();
      qy.pop();
      int cx = qx.front();
      qx.pop();
      for (int d = 0; d < 4; d++) {
        int ny = cy + dy[d];
        int nx = cx + dx[d];
        if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
        if (grid[ny][nx] == '#') continue;
        if (visit[ny][nx]) continue;
        visit[ny][nx] = 1;
        int cnt = 0;
        for (int dd = 0; dd < 4; dd++) {
          int nny = ny + dy[dd];
          int nnx = nx + dx[dd];
          if (nny >= n || nnx >= m || nny < 0 || nnx < 0) continue;
          if (grid[nny][nnx] == '#') continue;
          if (grid[nny][nnx] == 'L') continue;
          cnt++;
        }
        if (cnt <= 2) {
          grid[ny][nx] = '+';
          qy.push(ny);
          qx.push(nx);
        }
      }
    }
    for (int i = 0; i < n; i++) cout << grid[i] << "\n";
  }
}
