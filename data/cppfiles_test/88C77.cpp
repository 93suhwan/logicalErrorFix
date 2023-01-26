#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n * m;) {
      int j = i;
      while (i < n * m && a[i].first == a[j].first) {
        i++;
      }
      int pred = 0;
      for (int k = j; k < i;) {
        int ost = i - j - pred;
        int len = min(ost, m - k % m);
        for (int l = k; l < k + len; l++) {
          int x = l / m;
          int y = l % m;
          d[x][y] = a[k + len - 1 - (l - k)].second;
        }
        k += len;
        pred += len;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          if (d[i][j] < d[i][k]) ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
