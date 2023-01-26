#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> mx(n, 0);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      cin >> k;
      for (int j = 0; j < k; j++) {
        int u;
        cin >> u;
        a[i].push_back(u - j);
        mx[i] = max(mx[i], u - j);
      }
      s.insert({mx[i], i});
    }
    int ans = 0, net = 0;
    while (s.size()) {
      int id = (*s.begin()).second;
      s.erase(s.begin());
      ans = max(ans, mx[id] + 1 - net);
      net += a[id].size();
    }
    cout << ans << endl;
  }
  return 0;
}
