#include <bits/stdc++.h>
using namespace std;
void Tez() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  Tez();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i <= n - 1; i++) cin >> a[i];
    priority_queue<pair<long long, long long>> pq;
    for (long long i = 0; i <= n - 1; i++) {
      if (a[i] != 0) {
        pq.push({a[i], i + 1});
      }
    }
    long long cnt = 0;
    vector<vector<long long>> res;
    while (pq.size() > 1) {
      auto p1 = pq.top();
      pq.pop();
      auto p2 = pq.top();
      pq.pop();
      cnt++;
      res.push_back({p1.second, p2.second});
      p1.first -= 1;
      p2.first -= 1;
      if (p1.first > 0) pq.push(p1);
      if (p2.first > 0) pq.push(p2);
    }
    cout << cnt << '\n';
    for (auto vec : res) {
      cout << vec[0] << " " << vec[1] << '\n';
    }
  }
  return 0;
}
