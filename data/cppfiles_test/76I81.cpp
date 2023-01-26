#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<bool> valid(n, 0);
  for (int i = 0; i < n; i++)
    if (v[i].size() > 3) valid[i] = 1;
  for (int i = 0; i < n - 4; i++) {
    if (!valid[i]) continue;
    for (int j = i + 1; j < n - 3; j++) {
      if (find(v[i].begin(), v[i].end(), j) == v[i].end() || !valid[j])
        continue;
      for (int k = j + 1; k < n - 2; k++) {
        if (find(v[i].begin(), v[i].end(), k) == v[i].end() ||
            find(v[j].begin(), v[j].end(), k) == v[j].end() || !valid[k])
          continue;
        for (int o = k + 1; o < n - 1; o++) {
          if (find(v[i].begin(), v[i].end(), o) == v[i].end() ||
              find(v[j].begin(), v[j].end(), o) == v[j].end() ||
              find(v[k].begin(), v[k].end(), o) == v[k].end() || !valid[o])
            continue;
          for (int p = o + 1; p < n; p++) {
            if (find(v[i].begin(), v[i].end(), p) == v[i].end() ||
                find(v[j].begin(), v[j].end(), p) == v[j].end() ||
                find(v[k].begin(), v[k].end(), p) == v[k].end() ||
                find(v[o].begin(), v[o].end(), p) == v[o].end() || !valid[p])
              continue;
            cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << o + 1 << " "
                 << p + 1;
            return 0;
          }
        }
      }
    }
  }
  for (int i = 0; i < n - 4; i++) {
    for (int j = i + 1; j < n - 3; j++) {
      if (find(v[i].begin(), v[i].end(), j) != v[i].end()) continue;
      for (int k = j + 1; k < n - 2; k++) {
        if (find(v[i].begin(), v[i].end(), k) != v[i].end() ||
            find(v[j].begin(), v[j].end(), k) != v[j].end())
          continue;
        for (int o = k + 1; o < n - 1; o++) {
          if (find(v[i].begin(), v[i].end(), o) != v[i].end() ||
              find(v[j].begin(), v[j].end(), o) != v[j].end() ||
              find(v[k].begin(), v[k].end(), o) != v[k].end())
            continue;
          for (int p = o + 1; p < n; p++) {
            if (find(v[i].begin(), v[i].end(), p) != v[i].end() ||
                find(v[j].begin(), v[j].end(), p) != v[j].end() ||
                find(v[k].begin(), v[k].end(), p) != v[k].end() ||
                find(v[o].begin(), v[o].end(), p) != v[o].end())
              continue;
            cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << o + 1 << " "
                 << p + 1;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
}
