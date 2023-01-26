#include <bits/stdc++.h>
using namespace std;
long long vis[1001][1001];
long long a[1001][1001];
long long n, m;
bool isvalid(long long x, long long y) {
  if (x <= 0 || x > n || y <= 0 || y > m) return false;
  if (vis[x][y] == 1) return false;
  return true;
}
int dfs(long long x, long long y) {
  vis[x][y] = 1;
  int cnt = 1;
  if (!(a[x][y] & (1ll << 3)) && isvalid(x - 1, y)) {
    cnt += dfs(x - 1, y);
  }
  if (!(a[x][y] & (1ll << 2)) && isvalid(x, y + 1)) {
    cnt += dfs(x, y + 1);
  }
  if (!(a[x][y] & (1ll << 1)) && isvalid(x + 1, y)) {
    cnt += dfs(x + 1, y);
  }
  if (!(a[x][y] & (1ll)) && isvalid(x, y - 1)) {
    cnt += dfs(x, y - 1);
  }
  return cnt;
}
int main() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vis[i][j] = 0;
    }
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  long long cnt = 0;
  vector<long long> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        v.push_back(dfs(i, j));
      }
    }
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
