#include <bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<bool>> ans, int r, int c, int n) {
  for (int i = 0; i <= c; i++) {
    if (ans[r][i] == true) return false;
  }
  for (int i = 0; i <= r; i++) {
    if (ans[i][c] == true) return false;
  }
  for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
    if (ans[i][j] == true) return false;
  }
  for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
    if (ans[i][j] == true) return false;
  }
  return true;
}
void permute(int qsf, int n, vector<vector<bool>> ans, int ro) {
  if (qsf == n) {
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[0].size(); j++) {
        if (ans[i][j] == true)
          cout << "Q";
        else
          cout << ".";
      }
      cout << endl;
    }
    cout << endl;
  }
  for (int i = ro + 1; i < n * n; i++) {
    int r = i / n;
    int c = i % n;
    if (ans[r][c] == false && isvalid(ans, r, c, n)) {
      ans[r][c] = true;
      permute(qsf + 1, n, ans, i);
      ans[r][c] = false;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> v1(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v1[x].insert(y);
    v1[y].insert(x);
  }
  long long int f = 0;
  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (v1[i].lower_bound(i) == v1[i].end()) {
      f++;
      vis[i] = 1;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int c, u, v;
    cin >> c;
    if (c == 3) {
      cout << f << endl;
    } else {
      cin >> u >> v;
      if (vis[u]) f--;
      if (vis[v]) f--;
      if (c == 1) {
        v1[u].insert(v);
        v1[v].insert(u);
      }
      if (c == 2) {
        v1[u].erase(v);
        v1[v].erase(u);
      }
      if (v1[u].lower_bound(u) != v1[u].end()) vis[u] = 0;
      if (v1[v].lower_bound(v) != v1[v].end()) vis[v] = 0;
      if (vis[u]) f++;
      if (vis[v]) f++;
    }
  }
}
