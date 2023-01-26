#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      pq.push(make_pair(a, i + 1));
    }
    vector<pair<int, int>> ans;
    while (pq.size() >= 2) {
      auto p1 = pq.top();
      pq.pop();
      auto p2 = pq.top();
      pq.pop();
      if (p2.first == 0) break;
      ans.emplace_back(p1.second, p2.second);
      pq.push(make_pair(p1.first - 1, p1.second));
      pq.push(make_pair(p2.first - 1, p2.second));
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
  }
}
