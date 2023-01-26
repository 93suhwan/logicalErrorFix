#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int n, m;
bool check(int md) {
  int mx = 0;
  for (int i = 0; i < m; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (v[i][j] >= md) c++;
    }
    mx = max(mx, c);
  }
  if (mx < 2) return true;
  for (int i = 0; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < m; j++) {
      mx = max(mx, v[j][i]);
    }
    if (mx < md) return true;
  }
  return false;
}
int bs(int lo, int hi) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      vector<int> z(n);
      for (int j = 0; j < n; j++) {
        cin >> z[j];
      }
      v.push_back(z);
    }
    cout << bs(1, (1 << 30)) - 1 << "\n";
  }
  return 0;
}
