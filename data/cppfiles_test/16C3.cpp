#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    int a;
    priority_queue<pair<int, int> > pq;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a > 0) pq.push({a, i + 1});
    }
    vector<pair<int, int> > ans;
    while (pq.size() > 1) {
      pair<int, int> x = pq.top();
      pq.pop();
      pair<int, int> y = pq.top();
      pq.pop();
      ans.push_back({x.second, y.second});
      if (x.first - 1 > 0) pq.push({x.first - 1, x.second});
      if (y.first - 1 > 0) pq.push({y.first - 1, y.second});
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
}
