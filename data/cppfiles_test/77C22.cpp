#include <bits/stdc++.h>
using namespace std;
stack<int> st;
queue<int> q;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> mpq;
int binarySearch(vector<string> arr, int l, int r, string x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
bool comp(pair<int, int> a, pair<int, int> b) { return (a.first > b.first); }
int visited[1005][1005];
int arr[1005][1005];
vector<int> ans;
int dfs(int x, int y, int n, int m) {
  if (x >= n || x < 0 || y < 0 || y >= m) {
    return 0;
  }
  if (visited[x][y]) {
    return 0;
  }
  visited[x][y] = 1;
  int size = 1;
  if ((arr[x][y] & (4)) == 0 && (arr[x][y + 1] & (1)) == 0) {
    size += dfs(x, y + 1, n, m);
  }
  if ((arr[x][y] & (2)) == 0 && (arr[x + 1][y] & (8)) == 0) {
    size += dfs(x + 1, y, n, m);
  }
  if ((arr[x][y] & (1)) == 0 && (arr[x][y - 1] & (4)) == 0) {
    size += dfs(x, y - 1, n, m);
  }
  if ((arr[x][y] & (8)) == 0 && (arr[x - 1][y] & (2)) == 0) {
    size += dfs(x - 1, y, n, m);
  }
  return size;
}
void solve() {
  memset(arr, 0, sizeof arr);
  memset(visited, 0, sizeof visited);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        ans.push_back(dfs(i, j, n, m));
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
