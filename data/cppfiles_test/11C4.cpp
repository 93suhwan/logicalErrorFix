#include <bits/stdc++.h>
using namespace std;
long long LIS(vector<long long>& v) {
  long long n = v.size();
  if (!n) return 0;
  vector<long long> dp;
  dp = {v[0]};
  for (long long i = 1; i < n; ++i) {
    auto it = lower_bound(dp.begin(), dp.end(), v[i]);
    if (it == dp.end())
      dp.push_back(v[i]);
    else
      *it = v[i];
  }
  return dp.size();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    if (i >= x) {
      a.push_back({i - x, x});
    }
  }
  sort(a.begin(), a.end());
  vector<long long> b;
  for (auto& [i, j] : a) {
    b.push_back(j);
  }
  cout << LIS(b);
  return 0;
}
