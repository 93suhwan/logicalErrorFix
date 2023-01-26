#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> x(n);
    vector<long long> y[n + 1];
    for (long long i = 0; i < n; i++) {
      cin >> x[i];
      y[x[i]].push_back(i);
    }
    vector<pair<long long, vector<long long>>> z;
    for (long long i = 1; i <= n; i++) {
      if (y[i].size()) {
        z.push_back({y[i].size(), y[i]});
      }
    }
    sort(z.begin(), z.end());
    reverse(z.begin(), z.end());
    vector<long long> color;
    for (long long i = 0; i < z.size(); i++) {
      for (long long j = 0; j < k && j < z[i].first; j++) {
        color.push_back(z[i].second[j]);
      }
    }
    long long m = (color.size() / k) * k;
    vector<long long> ans(n, 0);
    for (long long i = 0; i < m; i++) {
      ans[color[i]] = i % k + 1;
    }
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
