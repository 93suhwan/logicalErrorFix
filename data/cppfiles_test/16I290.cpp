#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, n;
  cin >> t;
  while (t--) {
    priority_queue<pair<int, int>> pq;
    vector<pair<pair<int, int>, int>> v;
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
      v.push_back({{b.second, a.second}, b.first});
      siz += b.first;
      if (a.first - b.first) pq.push({a.first - b.first, a.second});
    }
    cout << siz << '\n';
    for (int i = 0; i < v.size(); i++) {
      while (v[i].second) {
        cout << v[i].first.first << " " << v[i].first.second << '\n';
        v[i].second--;
      }
    }
  }
}
