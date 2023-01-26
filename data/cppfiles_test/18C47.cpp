#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    priority_queue<pair<int, int> > pq;
    vector<int> dis(n, inf);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 0) {
        dis[i] = 0;
        pq.push({-dis[i], i});
      }
    }
    while ((int)pq.size() > 0) {
      int cost = pq.top().first;
      int idx = pq.top().second;
      pq.pop();
      int new_idx = (idx - d + n) % n;
      if (dis[new_idx] > dis[idx] + 1) {
        dis[new_idx] = dis[idx] + 1;
        pq.push({-dis[new_idx], new_idx});
      }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, dis[i]);
    if (mx == inf) mx = -1;
    cout << mx << '\n';
  }
  return 0;
}
