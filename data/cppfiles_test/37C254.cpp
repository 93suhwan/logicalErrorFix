#include <bits/stdc++.h>
using namespace std;
int find(int node, vector<int>& par) {
  if (par[node] == -1) return node;
  return par[node] = find(par[node], par);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      vis[b] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        root = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (root != i) {
        cout << root << " " << i << endl;
      }
    }
  }
  return 0;
}
