#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int l, m1, r, gen = 0;
    memset(vis, 0, n + 5);
    for (int i = 0; i < m; ++i) {
      cin >> l >> m1 >> r;
      vis[m1] = 1;
    }
    for (int i = 1; i <= m; ++i) {
      if (!vis[i]) {
        gen = i;
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i != gen) cout << i << " " << gen << endl;
    }
  }
}
