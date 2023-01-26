#include <bits/stdc++.h>
using namespace std;
int a[15], n;
bool dfs(int u, int v, bool f) {
  if (u == n) return v == 0 && f;
  return dfs(u + 1, v + a[u], 1) || dfs(u + 1, v, f) || dfs(u + 1, v - a[u], 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (dfs(0, 0, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
