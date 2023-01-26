#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    set<pair<int, pair<int, int>>> m_set;
    vector<vector<int>> deg(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '#' || a[i][j] == 'L') {
          continue;
        }
        if (j < m - 1 && a[i][j + 1] == '.') {
          deg[i][j]++;
        }
        if (j > 0 && a[i][j - 1] == '.') {
          deg[i][j]++;
          ;
        }
        if (i < n - 1 && a[i + 1][j] == '.') {
          deg[i][j]++;
        }
        if (i > 0 && a[i - 1][j] == '.') {
          deg[i][j]++;
        }
        m_set.insert({deg[i][j], {i, j}});
      }
    }
    while (true) {
      auto it = m_set.begin();
      if (it == m_set.end()) {
        break;
      }
      int i = (*it).second.first;
      int j = (*it).second.second;
      int degg = (*it).first;
      if (degg > 1) {
        break;
      }
      m_set.erase(it);
      a[i][j] = '+';
      if (j < m - 1 && a[i][j + 1] == '.') {
        m_set.erase({deg[i][j + 1], {i, j + 1}});
        deg[i][j + 1]--;
        m_set.insert({deg[i][j + 1], {i, j + 1}});
      }
      if (j > 0 && a[i][j - 1] == '.') {
        m_set.erase({deg[i][j - 1], {i, j - 1}});
        deg[i][j - 1]--;
        m_set.insert({deg[i][j - 1], {i, j - 1}});
      }
      if (i < n - 1 && a[i + 1][j] == '.') {
        m_set.erase({deg[i + 1][j], {i + 1, j}});
        deg[i + 1][j]--;
        m_set.insert({deg[i + 1][j], {i + 1, j}});
      }
      if (i > 0 && a[i - 1][j] == '.') {
        m_set.erase({deg[i - 1][j], {i - 1, j}});
        deg[i - 1][j]--;
        m_set.insert({deg[i - 1][j], {i - 1, j}});
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
}
