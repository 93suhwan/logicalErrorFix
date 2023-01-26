#include <bits/stdc++.h>
using namespace std;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e17 + 2;
vector<vector<long long>> arr;
vector<vector<char>> vis;
long long sz = 0;
void dfs(long long i, long long j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  sz++;
  if ((arr[i][j] & (1 << 3)) == 0) dfs(i - 1, j);
  if ((arr[i][j] & (1 << 2)) == 0) dfs(i, j + 1);
  if ((arr[i][j] & (1 << 1)) == 0) dfs(i + 1, j);
  if ((arr[i][j] & (1 << 0)) == 0) dfs(i, j - 1);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  arr.resize(n, vector<long long>(m));
  vis.resize(n, vector<char>(m, 0));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> arr[i][j];
  }
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!vis[i][j]) {
        sz = 0;
        dfs(i, j);
        ans.push_back(sz);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (long long i : ans) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
