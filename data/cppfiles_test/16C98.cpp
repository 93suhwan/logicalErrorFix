#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, n;
  cin >> t;
  while (t--) {
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> v;
    cin >> n;
    int siz = 0;
    for (int i = 1; i <= n; i++) {
      int nr;
      cin >> nr;
      if (nr) pq.push({nr, i});
    }
    while (pq.size() > 1) {
      pair<int, int> a, b;
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      v.push_back({a.second, b.second});
      if (a.first - 1 > 0) pq.push({a.first - 1, a.second});
      if (b.first - 1 > 0) pq.push({b.first - 1, b.second});
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << '\n';
    }
  }
}
