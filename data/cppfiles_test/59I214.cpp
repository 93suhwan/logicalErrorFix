#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(6));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        cin >> v[i][j];
      }
    }
    bool ans = false;
    for (int i = 1; i <= 5; i++) {
      for (int j = 1; j <= 5; j++) {
        if (i == j) continue;
        vector<int> first;
        vector<int> second;
        vector<int> both;
        for (int k = 1; k <= n; k++) {
          if (v[k][i] == 1 and v[k][j] == 1) both.push_back(1);
          if (v[k][i] == 1 and v[k][j] == 0) first.push_back(1);
          if (v[k][i] == 0 and v[k][j] == 1) second.push_back(1);
        }
        if (first.size() == second.size() and first.size() == n / 2) ans = true;
        if (first.size() < second.size()) {
          int need = max((n / 2) - (int)first.size(), 0);
          if (need > both.size()) continue;
          int left = both.size() - need;
          if (left + second.size() == n / 2) ans = true;
        } else if (first.size() > second.size()) {
          int need = max((n / 2) - (int)second.size(), 0);
          if (need > both.size()) continue;
          int left = both.size() - need;
          if (left + first.size() == n / 2) ans = true;
        }
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
