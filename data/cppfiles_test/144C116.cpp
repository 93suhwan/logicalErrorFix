#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
int main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
      pq.push({0, i + 1});
    }
    for (int i = 0; i < k; ++i) {
      set<int> all;
      for (int j = 0; j < n; ++j) {
        all.insert(j + 1);
      }
      priority_queue<pair<int, int>> next;
      for (int j = 0; j < n % m; ++j) {
        cout << (n + m - 1) / m;
        for (int l = 0; l < (n + m - 1) / m; ++l) {
          cout << " " << pq.top().second;
          all.erase(pq.top().second);
          next.push({pq.top().first - 1, pq.top().second});
          pq.pop();
        }
        cout << '\n';
      }
      for (int j = 0; j < m - (n % m); ++j) {
        cout << (n / m);
        for (int l = 0; l < n / m; ++l) {
          cout << " " << *all.begin();
          all.erase(all.begin());
        }
        cout << '\n';
      }
      while (!next.empty()) {
        pq.push(next.top());
        next.pop();
      }
    }
  }
  return 0;
}
