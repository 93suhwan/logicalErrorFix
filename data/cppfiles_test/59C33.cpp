#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(5));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int f = 0, s = 0, b = 0;
      for (int k = 0; k < n; k++) {
        if (v[k][i] && !v[k][j])
          f++;
        else if (!v[k][i] && v[k][j])
          s++;
        else if (v[k][i] && v[k][j])
          b++;
      }
      if (f + s + b == n && min(f, s) + b >= max(f, s)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
