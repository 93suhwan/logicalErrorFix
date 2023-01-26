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
    vector<int> parent(n + 1, -1);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      int p = find(a, parent);
      int q = find(b, parent);
      if (p != q) {
        parent[b] = a;
        cout << a << " " << b << endl;
      }
      q = find(c, parent);
      if (p != q) {
        parent[c] = a;
        cout << a << " " << c << endl;
      }
    }
  }
  return 0;
}
