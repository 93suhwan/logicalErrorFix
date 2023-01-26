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
        if (first.size() == 0 and second.size() == 0 and both.size() == 0)
          continue;
        if (first.size() == second.size()) ans = true;
        if (first.size() < second.size()) {
          int need = (n / 2) - first.size();
          if (both.size() >= need) ans = true;
        } else if (first.size() > second.size()) {
          int need = (n / 2) - second.size();
          if (both.size() >= need) ans = true;
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
