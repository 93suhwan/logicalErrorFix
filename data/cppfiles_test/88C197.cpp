#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[90050];
bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) return x.second > y.second;
  return x.first < y.first;
}
bool vis[90050];
int pos[90050];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i * m + j].first;
        a[i * m + j].second = i * m + j;
      }
    }
    sort(a + 1, a + m * n + 1, cmp);
    for (int i = 1; i < n; i++) {
      int idx1 = m, idx2 = -1;
      for (int j = m - 1; j >= 1; j--) {
        if (a[(i - 1) * m + j].first == a[i * m].first) {
          idx1 = j;
        } else
          break;
      }
      for (int j = i * m + 1; j <= n * m; j++) {
        if (a[i * m].first == a[j].first) {
          idx2 = j;
        } else
          break;
      }
      if (idx2 == -1) continue;
      int tmp = m - idx1 + 1;
      idx1 = (i - 1) * m + idx1;
      pair<int, int> aa;
      while (tmp--) {
        aa = a[idx2];
        for (int j = idx2; j > idx1; j--) {
          a[j] = a[j - 1];
        }
        a[idx1] = aa;
      }
    }
    for (int i = 1; i <= n * m; i++) {
      pos[a[i].second] = i;
    }
    long long ans = 0;
    for (int i = 1, sz = n * m; i <= sz; i++) {
      int id = (pos[i] + m - 1) / m;
      for (int j = (id - 1) * m + 1; j < pos[i]; j++) {
        if (vis[j]) ans++;
      }
      vis[pos[i]] = 1;
    }
    cout << ans << endl;
  }
  return 0;
}
