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
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      if (k != 0) v.push_back({k, i + 1});
    }
    sort(v.begin(), v.end(), comp);
    priority_queue<pair<long long, long long>> pq2;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        pq1;
    for (long long i = 0; i < (v.size()) / 2; i++) {
      pq1.push({v[i].first, v[i].second});
    }
    for (long long i = (v.size()) / 2; i < v.size(); i++) {
      pq2.push({v[i].first, v[i].second});
    }
    vector<pair<long long, long long>> ans;
    while (1) {
      if ((pq1.size() <= 1 && pq2.size() == 0) ||
          (pq1.size() == 0 && pq2.size() <= 1))
        break;
      if (pq1.top().first == 0) pq1.pop();
      if (pq2.top().first == 0) pq2.pop();
      if (pq2.top().second == pq1.top().second) break;
      if (pq1.empty()) {
        if (!pq2.empty()) {
          for (long long i = 0; i < (pq2.size()) / 2; i++) {
            long long v = pq2.top().first;
            long long v1 = pq2.top().second;
            pq1.push({v, v1});
            pq2.pop();
          }
        }
      }
      if (pq2.empty()) {
        if (!pq1.empty()) {
          for (long long i = 0; i < (pq1.size()) / 2; i++) {
            long long v = pq1.top().first;
            long long v1 = pq1.top().second;
            pq2.push({v, v1});
            pq1.pop();
          }
        }
      }
      long long u = pq1.top().first;
      long long u1 = pq1.top().second;
      long long v = pq2.top().first;
      long long v1 = pq2.top().second;
      ans.push_back({pq1.top().second, pq2.top().second});
      pq1.pop();
      pq2.pop();
      if (u - 1 > 0) pq1.push({u - 1, u1});
      if (v - 1 > 0) pq2.push({v - 1, v1});
    }
    cout << ans.size() << "\n";
    for (long long i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
