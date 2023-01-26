#include <bits/stdc++.h>
using namespace std;
const int MAXX = 2e5 + 10;
int T, n;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vec;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    vec.clear();
    while (pq.size()) pq.pop();
    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      if (x) pq.push({x, i});
    }
    while (pq.size() >= 2) {
      pair<int, int> it1 = pq.top();
      pq.pop();
      pair<int, int> it2 = pq.top();
      pq.pop();
      vec.push_back({it1.second, it2.second});
      if (it1.first > 1) pq.push({it1.first - 1, it1.second});
      if (it2.first > 1) pq.push({it2.first - 1, it2.second});
    }
    cout << vec.size() << '\n';
    for (auto x : vec) cout << x.first << " " << x.second << '\n';
  }
}
