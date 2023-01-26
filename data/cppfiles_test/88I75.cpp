#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> v[i].first;
      v[i].second = -i;
    }
    sort((v).begin(), (v).end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int l = 0; l < m; l++) {
        for (int j = 0; j < l; j++) {
          if (v[i * m + l].second < v[i * m + j].second) ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
