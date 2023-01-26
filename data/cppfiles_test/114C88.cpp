#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
map<vector<int>, int> mp;
int a[15][N];
int c[N];
int n, m;
vector<int> g[N], res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; j++) {
      cin >> a[i][j];
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      g[i].push_back(a);
    }
    mp[g[i]] = 1;
  }
  int ans = 0;
  vector<int> gg;
  for (int i = 1; i <= n; i++) {
    gg.push_back(c[i]);
  }
  if (!mp[gg]) {
    for (int i = 1; i <= n; i++) ans += a[i][c[i]];
    res = gg;
  }
  for (int i = 1; i <= m; i++) {
    gg.clear();
    for (int j = 0; j < n; j++) {
      gg = g[i];
      if (g[i][j] > 1) {
        gg[j]--;
        int tmp = 0;
        if (!mp[gg]) {
          for (int j = 0; j < n; j++) tmp += a[j + 1][gg[j]];
          if (tmp > ans) ans = tmp, res = gg;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) cout << res[i] << " ";
}
