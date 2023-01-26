#include <bits/stdc++.h>
using namespace std;
long long m2 = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t, n, x, m, ab, ba, ot, k, l, r;
  vector<vector<int>> a;
  vector<vector<pair<int, int>>> mi, ma;
  vector<pair<pair<pair<int, int>, pair<int, int>>, int>> p;
  vector<int> mab, mib;
  vector<int> mac, mic;
  bool F;
  cin >> t;
  while (t > 0) {
    --t;
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    mi.assign(n, vector<pair<int, int>>(m));
    ma.assign(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (j == 0)
          mi[i][j] = make_pair(a[i][j], a[i][j]);
        else {
          mi[i][j].first = min(a[i][j], mi[i][j - 1].first);
          mi[i][j].second = max(a[i][j], mi[i][j - 1].second);
        }
      }
    for (int i = 0; i < n; i++)
      for (int j = m - 1; j >= 0; j--) {
        if (j == m - 1)
          ma[i][j] = make_pair(a[i][j], a[i][j]);
        else {
          ma[i][j].first = min(a[i][j], ma[i][j + 1].first);
          ma[i][j].second = max(a[i][j], ma[i][j + 1].second);
        }
      }
    F = true;
    for (int k = 1; k < m && F; ++k) {
      p.clear();
      for (int i = 0; i < n; ++i)
        p.emplace_back(make_pair(mi[i][k - 1], ma[i][k]), i);
      sort(p.begin(), p.end());
      mib.clear();
      mab.clear();
      mic.clear();
      mac.clear();
      for (int i = 0; i < n; i++) {
        if (i == 0)
          mib.push_back(p[i].first.first.second);
        else
          mib.push_back(max(p[i].first.first.second, mib.back()));
        if (i == 0)
          mic.push_back(p[i].first.second.first);
        else
          mic.push_back(min(p[i].first.second.first, mic.back()));
      }
      for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1)
          mab.push_back(p[i].first.second.second);
        else
          mab.push_back(max(p[i].first.second.second, mab.back()));
        if (i == n - 1)
          mac.push_back(p[i].first.first.first);
        else
          mac.push_back(min(p[i].first.first.first, mac.back()));
      }
      for (int i = 1; i <= n - 1; ++i)
        if (mib[i - 1] < mac[n - i - 1] && mic[i - 1] > mab[n - i - 1]) {
          F = false;
          cout << "YES\n";
          string s(n, 'R');
          for (int j = 0; j < i; ++j) s[p[j].second] = 'B';
          cout << s << ' ' << k << '\n';
          break;
        }
    }
    if (F) cout << "NO\n";
  }
  return 0;
}
