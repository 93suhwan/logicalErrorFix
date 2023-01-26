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
      pq.push(make_pair(x, i + 1));
    }
    vector<pair<int, int> > res;
    long long count = 0;
    while (pq.size() > 1) {
      pair<int, int> p1 = pq.top();
      pq.pop();
      pair<int, int> p2 = pq.top();
      pq.pop();
      count += p2.first;
      for (int i = 0; i < p2.first; i++) {
        res.push_back(make_pair(p1.second, p2.second));
      }
      p1.first = p1.first - p2.first;
      if (p1.first != 0) {
        pq.push(p1);
      }
    }
    cout << count << "\n";
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << " " << res[i].second << "\n";
    }
  }
  return 0;
}
