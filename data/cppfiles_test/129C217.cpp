#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 5);
  vector<bool> f(n + 5, 0);
  vector<int> app;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] <= n) {
      if (f[v[i]] == 1) {
        app.push_back(v[i]);
      }
      f[v[i]] = 1;
    } else {
      app.push_back(v[i]);
    }
  }
  sort(app.begin(), app.end());
  int ans = 0, ind = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == 1) {
      continue;
    }
    int x = (app[ind] - 1) / 2;
    if (i <= x) {
      ans++;
      ind++;
      continue;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
