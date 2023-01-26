#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 0) pq.push(make_pair(x, i + 1));
    }
    vector<pair<int, int> > res;
    while (pq.size() > 1) {
      pair<int, int> p1 = pq.top();
      pq.pop();
      pair<int, int> p2 = pq.top();
      pq.pop();
      res.push_back(make_pair(p1.second, p2.second));
      p1.first--;
      p2.first--;
      if (p1.first != 0) pq.push(p1);
      if (p2.first != 0) pq.push(p2);
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << " " << res[i].second << "\n";
    }
  }
  return 0;
}
