#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1 * 1e2 + 5;
const int logn = 24;
const long long MOD = 1e9 + 7;
void init() {}
vector<string> arr;
int n, m, k;
void draw(int i, int j, vector<string>& arr, vector<vector<bool>>& vis) {
  int l = 0, r = 0;
  int ti = i - 1, tj = j - 1;
  while (ti >= 0 && tj >= 0 && arr[ti][tj] == '*') {
    l++;
    ti--;
    tj--;
  }
  ti = i - 1, tj = j + 1;
  while (ti >= 0 && tj < m && arr[ti][tj] == '*') {
    r++;
    ti--;
    tj++;
  }
  if (l >= k && r >= k) {
    vis[i][j] = 1;
    int total = min(l, r), count = 0;
    ti = i - 1, tj = j - 1;
    while (count < total) {
      count++;
      vis[ti][tj] = 1;
      ti--;
      tj--;
    }
    ti = i - 1, tj = j + 1;
    count = 0;
    while (count < total) {
      count++;
      vis[ti][tj] = 1;
      ti--;
      tj++;
    }
  }
}
void solve() {
  cin >> n >> m >> k;
  arr.clear();
  arr.resize(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*') draw(i, j, arr, vis);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*' && !vis[i][j]) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
  return;
}
int main() {
  init();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc) {
    solve();
    tc--;
  }
}
