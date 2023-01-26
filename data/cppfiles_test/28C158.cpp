#include <bits/stdc++.h>
using namespace std;
void DFS(int x, vector<vector<int>> &edges, vector<bool> &visited) {
  visited[x] = 1;
  for (int i : edges[x]) {
    if (visited[i]) continue;
    DFS(i, edges, visited);
  }
}
int solve(vector<int> v, int k) {
  int n = v.size();
  vector<int> idx(n + 1), tmp(n);
  int lst = 1;
  for (int i = k;; i = (i + 1) % n) {
    if (i == k && tmp[i]) break;
    tmp[i] = lst++;
  }
  for (int i = 0; i < n; i++) {
    idx[tmp[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    v[i] = idx[v[i]];
  }
  vector<vector<int>> edges(n);
  for (int i = 0; i < n; i++) {
    edges[i].push_back(v[i]);
  }
  int cnt = 0;
  vector<bool> visited(n);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) cnt++, DFS(i, edges, visited);
  }
  return n - cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), cnt(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      cnt[((i - v[i] + 1) % n + n) % n]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (cnt[i] >= n / 3) {
        int x = solve(v, i);
        if (x <= m) ans.push_back(i);
      }
    }
    cout << ans.size() << " ";
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}
