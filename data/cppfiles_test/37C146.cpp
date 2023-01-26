#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, root;
    cin >> n >> m;
    vector<bool> block(n + 1, false);
    while (m--) {
      int u, v, z;
      cin >> u >> v >> z;
      block[v] = true;
    }
    for (int i = 1; i <= n; ++i)
      if (!block[i]) {
        root = i;
        break;
      }
    for (int i = 1; i <= n; ++i)
      if (i != root) cout << root << ' ' << i << endl;
  }
  return 0;
}
