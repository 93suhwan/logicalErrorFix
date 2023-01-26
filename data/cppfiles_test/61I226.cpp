#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  ;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    map<int, vector<int>> m1;
    map<int, int> m2;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      m1[x].push_back(y);
      m2[y]++;
    }
    int res = 0;
    res = (n * (n - 1) * (n - 2)) / 6;
    int ans = 0;
    for (auto i : m1) {
      for (int j = 0; j < i.second.size(); j++)
        ans += (i.second.size() - 1) * (m2[i.second[j]] - 1);
    }
    cout << res - ans << endl;
  }
  return 0;
}
