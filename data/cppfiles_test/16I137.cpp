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
      mq.push({a, i});
    }
    vector<pair<int, int>> res;
    while (mq.size() > 1) {
      auto a = mq.top();
      mq.pop();
      auto b = mq.top();
      mq.pop();
      int t = b.first;
      while (t--) res.push_back({a.second, b.second});
      if (a.first - b.first > 0) {
        mq.push({a.first - b.first, a.second});
      }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << " " << res[i].second << endl;
    }
  }
  return 0;
}
