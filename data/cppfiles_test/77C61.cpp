#include <bits/stdc++.h>
using namespace std;
long long int cnt;
string binary(long long int n) {
  string ans;
  while (n != 0) {
    int r = n % 2;
    n = n / 2;
    ans += to_string(r);
  }
  while (ans.length() != 4) {
    ans += '0';
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
void dfs(long long int i, long long int j, vector<vector<long long int> > &v,
         vector<vector<bool> > &visited) {
  long long int n = v.size();
  long long int m = v[0].size();
  if (i < 0 or i > n - 1 or j < 0 or j > m - 1 or visited[i][j]) {
    return;
  }
  cnt++;
  visited[i][j] = true;
  if (i > 0) {
    if (((v[i - 1][j] & 2) == 0) and ((v[i][j] & 8) == 0))
      dfs(i - 1, j, v, visited);
  }
  if (i < n - 1) {
    if (((v[i + 1][j] & 8) == 0) and ((v[i][j] & 2) == 0))
      dfs(i + 1, j, v, visited);
  }
  if (j > 0) {
    if (((v[i][j - 1] & 4) == 0) and ((v[i][j] & 1) == 0))
      dfs(i, j - 1, v, visited);
  }
  if (j < m - 1) {
    if (((v[i][j + 1] & 1) == 0) and ((v[i][j] & 4) == 0))
      dfs(i, j + 1, v, visited);
  }
}
bool comp(long long int a, long long int b) { return a > b; }
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> ans;
  vector<vector<bool> > visited(n, vector<bool>(m, false));
  vector<vector<long long int> > v(n, vector<long long int>(m, 0));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        cnt = 0;
        dfs(i, j, v, visited);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end(), comp);
  for (auto it : ans) {
    cout << it << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
