#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    priority_queue<pair<int, int>> mq;
    for (int i = 1; i <= t; i++) {
      int a;
      cin >> a;
      if (a != 0) mq.push({a, i});
    }
    vector<pair<int, int>> res;
    while (mq.size() > 1) {
      auto a = mq.top();
      mq.pop();
      auto b = mq.top();
      mq.pop();
      int t = b.first;
      if (a.second == b.second) continue;
      if (a.first > 0 && b.first > 0) {
        res.push_back({a.second, b.second});
        if (a.first > 1) {
          mq.push({a.first - 1, a.second});
        }
        if (b.first > 1) mq.push({b.first - 1, b.second});
      }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << " " << res[i].second << endl;
    }
  }
  return 0;
}
