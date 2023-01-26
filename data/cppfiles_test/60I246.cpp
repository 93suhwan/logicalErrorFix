#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
int vis[1000001];
int gvis[1001][1001];
void dfs(int node) {
  vis[node] = 1;
  for (int i : arr[node]) {
    if (vis[i] == 0) {
      dfs(i);
    }
  }
}
bool isvalid(int x, int y, int n, int m) {
  if (x >= n || x < 0 || y >= m || y < 0) return false;
  if (gvis[x][y]) {
    return false;
  }
  return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void gdfs(int x, int y) {
  gvis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    if (isvalid(x + dx[i], y + dy[i], 0, 0)) {
      gdfs(x + dx[i], y + dy[i]);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  int mi = INT_MAX;
  for (int i = 0; i < n; i++) {
    mi = min(a[i] & m, mi);
  }
  cout << mi << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
