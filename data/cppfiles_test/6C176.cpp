#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
set<int> g[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    g[a].insert(b);
    if (g[a].size() == 1) ans++;
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 3) {
      cout << n - ans << endl;
    } else if (type == 2) {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      g[a].erase(b);
      if (g[a].size() == 0) ans--;
    } else {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      g[a].insert(b);
      if (g[a].size() == 1) ans++;
    }
  }
}
