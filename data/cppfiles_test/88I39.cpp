#include <bits/stdc++.h>
using namespace std;
pair<int, int> b[100001];
pair<int, int> a[100001];
int u[301][301];
vector<int> g[301];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        u[i][j] = 0;
        k++;
        cin >> a[k].first;
        a[k].second = k;
      }
    }
    sort(a + 1, a + k + 1);
    for (int i = 1; i <= k; i++) {
      int j = i;
      while (j <= k && a[j].first == a[i].first) {
        j++;
      }
      j--;
      int kol = j - i + 1;
      for (int id = 1; id <= m; id++) {
        g[id].clear();
      }
      for (int id = i; id <= j; id++) {
        int x = (id + m - 1) / m;
        int y = id % m;
        if (y == 0) y += m;
        g[y].push_back(x);
      }
      int qwe = i;
      for (int id = m; id >= 1; id--) {
        for (auto to : g[id]) {
          b[a[qwe].second] = make_pair(to, id);
          qwe++;
        }
      }
      i = j;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      int x = b[i].first;
      int y = b[i].second;
      for (int j = 1; j <= y; j++) {
        if (u[x][j]) ans++;
      }
      u[x][y] = 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
