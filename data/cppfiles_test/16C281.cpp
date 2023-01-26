#include <bits/stdc++.h>
using namespace std;
const long long mex = 100000 + 5;
const long long mod = (1e9) + 7;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    priority_queue<pair<long long, long long>> pq;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      if (k > 0) pq.push({k, i + 1});
    }
    vector<pair<long long, long long>> ans;
    while (pq.size() >= 2) {
      long long u = pq.top().first;
      long long u1 = pq.top().second;
      pq.pop();
      long long v = pq.top().first;
      long long v1 = pq.top().second;
      pq.pop();
      ans.push_back({u1, v1});
      if (u > 1) {
        pq.push({u - 1, u1});
      }
      if (v > 1) {
        pq.push({v - 1, v1});
      }
    }
    cout << ans.size() << "\n";
    for (long long i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
