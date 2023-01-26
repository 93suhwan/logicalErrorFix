#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int i, j, k, x, n;
    cin >> n;
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> p;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x > 0) p.push({x, i + 1});
    }
    while (p.size() > 1) {
      pair<int, int> x, y;
      x = p.top();
      p.pop();
      y = p.top();
      p.pop();
      ans.push_back({x.second, y.second});
      if (x.first > 1) p.push({x.first - 1, x.second});
      if (y.first > 1) p.push({y.first - 1, y.second});
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << "\n";
    }
  }
  return 0;
}
