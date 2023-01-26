#include <bits/stdc++.h>
using namespace std;
void Senior() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int main() {
  Senior();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      if (a > 0) pq.push({a, i});
    }
    while (pq.size() > 1) {
      auto x = pq.top();
      pq.pop();
      auto y = pq.top();
      pq.pop();
      ans.emplace_back(x.second, y.second);
      --x.first, --y.first;
      if (x.first > 0) pq.push(x);
      if (y.first > 0) pq.push(y);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}
