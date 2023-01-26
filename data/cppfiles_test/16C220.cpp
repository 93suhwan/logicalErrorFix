#include <bits/stdc++.h>
using namespace std;
const long long sz = 2e5 + 1;
int main() {
  long long t, n, a;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a != 0) pq.push(make_pair(a, i + 1));
    }
    while (!pq.empty() && pq.size() != 1) {
      pair<int, int> a = pq.top();
      pq.pop();
      pair<int, int> b = pq.top();
      pq.pop();
      ans.push_back(make_pair(a.second, b.second));
      a.first--;
      b.first--;
      if (a.first != 0) pq.push(a);
      if (b.first != 0) pq.push(b);
    }
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i.first << " " << i.second << "\n";
  }
}
