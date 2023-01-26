#include <bits/stdc++.h>
using namespace std;
const long double PI = atan(1) * 4.0;
const int N = 1001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int timesVisited[n][m];
    memset(timesVisited, 0, sizeof(timesVisited));
    int a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int ans[n][m];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < k; i++) {
      int start;
      cin >> start;
      vector<pair<int, int> > v;
      int ind1 = 0, ind2 = start - 1;
      int fin = -1;
      while (ind1 != n) {
        if (timesVisited[ind1][ind2] >= 10) {
          cout << ans[ind1][ind2] << " ";
          fin = ans[ind1][ind2];
          break;
        } else {
          timesVisited[ind1][ind2]++;
          if (timesVisited[ind1][ind2] == 10) {
            v.push_back({ind1, ind2});
          }
          if (a[ind1][ind2] == 1) {
            a[ind1][ind2] = 2;
            ind2++;
          } else if (a[ind1][ind2] == 2) {
            ind1++;
          } else {
            a[ind1][ind2] = 2;
            ind2--;
          }
        }
      }
      if (fin == -1) {
        fin = ind2 + 1;
        cout << fin << " ";
      }
      for (int j = 0; j < v.size(); j++) {
        ans[v[j].first][v[j].second] = fin;
      }
    }
  }
  return 0;
}
