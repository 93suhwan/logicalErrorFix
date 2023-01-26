#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> r;
vector<vector<pair<int, int>>> pre, suf;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    r = vector<int>(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
      r[i] = i;
    }
    sort(r.begin(), r.end(), [&](int i, int j) { return a[i][0] > a[j][0]; });
    pre = suf = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
      pre[i][0].first = pre[i][0].second = a[i][0];
      for (int j = 1; j < m; j++) {
        pre[i][j].first = min(pre[i][j - 1].first, a[i][j]);
        pre[i][j].second = max(pre[i][j - 1].second, a[i][j]);
      }
      suf[i][m - 1].first = suf[i][m - 1].second = a[i][m - 1];
      for (int j = m - 2; j >= 0; j--) {
        suf[i][j].first = min(a[i][j], suf[i][j + 1].first);
        suf[i][j].second = max(a[i][j], suf[i][j + 1].second);
      }
    }
    for (int j = 0; j + 1 < m; j++) {
      vector<pair<int, int>> izq(n), der(n);
      izq[r[0]].first = pre[r[0]][j].first;
      der[r[0]].second = suf[r[0]][j + 1].second;
      for (int i = 1; i + 1 < n; i++) {
        izq[r[i]].first = min(izq[r[i - 1]].first, pre[r[i]][j].first);
        der[r[i]].second = max(der[r[i - 1]].second, suf[r[i]][j + 1].second);
      }
      izq[r[n - 1]].second = pre[r[n - 1]][j].second;
      der[r[n - 1]].first = suf[r[n - 1]][j + 1].first;
      for (int i = n - 2; i > 0; i--) {
        izq[r[i]].second = max(izq[r[i + 1]].second, pre[r[i]][j].second);
        der[r[i]].first = min(der[r[i + 1]].first, suf[r[i]][j + 1].first);
      }
      for (int i = 0; i + 1 < n; i++) {
        if (izq[r[i]].first > izq[r[i + 1]].second &&
            der[r[i + 1]].first > der[r[i]].second) {
          cout << "YES" << '\n';
          string s(n, 'R');
          for (int j = i + 1; j < n; j++) s[r[j]] = 'B';
          cout << s << ' ' << j + 1 << '\n';
          goto out;
        }
      }
    }
    cout << "NO" << '\n';
  out:;
  }
  return 0;
}
