#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int n, i, a;
    priority_queue<pair<int, int>> q;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a) q.push({a, i + 1});
    }
    vector<pair<int, int>> ans;
    while (q.size() > 1) {
      pair<int, int> x, y;
      x = q.top();
      q.pop();
      y = q.top();
      q.pop();
      ans.push_back({x.second, y.second});
      if (x.first > 1) q.push({x.first - 1, x.second});
      if (y.first > 1) q.push({y.first - 1, y.second});
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.first << " " << x.second << '\n';
  }
  return 0;
}
