#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, n, m;
    cin >> n >> k;
    long long a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    unordered_map<long long, vector<long long>> mp;
    for (i = 0; i < n; i++) {
      mp[a[i]].push_back(i);
    }
    multimap<long long, vector<long long>, greater<long long>> p;
    for (auto x : mp) {
      p.insert({(x.second).size(), x.second});
    }
    long long ans = 0;
    long long d[n];
    memset(d, 0, sizeof(d));
    vector<long long> y;
    for (auto x : p) {
      m = x.first;
      vector<long long> v = x.second;
      if (m >= k) {
        for (i = 0; i < k; i++) {
          d[v[i]] = i + 1;
        }
      } else {
        for (i = 0; i < v.size() && y.size() < k; i++) {
          y.push_back(v[i]);
        }
        if (y.size() == k) {
          for (j = 0; j < y.size(); j++) {
            d[y[j]] = j + 1;
          }
          y.clear();
        }
        for (; i < v.size(); i++) y.push_back(v[i]);
      }
    }
    for (i = 0; i < n; i++) cout << d[i] << " ";
    cout << "\n";
  }
}
