#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> v0;
  vector<vector<long long>> a(n);
  for (long long i = 0; i < n; i++) {
    long long c;
    cin >> c;
    v0.push_back(c - 1);
    while (c--) {
      long long x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  auto Val = [&](vector<long long> v) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      ans += a[i][v[i]];
    }
    return ans;
  };
  map<vector<long long>, long long> mp;
  long long m;
  cin >> m;
  vector<vector<long long>> b(m, vector<long long>(n));
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> b[i][j];
      --b[i][j];
    }
    mp[b[i]] = 1;
  }
  if (mp.find(v0) == mp.end()) {
    for (long long x : v0) {
      cout << x + 1 << " ";
    }
    cout << '\n';
    return 0;
  }
  vector<vector<long long>> out;
  for (long long i = 0; i < m; i++) {
    auto v = b[i];
    for (long long j = 0; j < n; j++) {
      auto w = v;
      if (w[j] == 0) continue;
      --w[j];
      if (mp.find(w) != mp.end()) {
        continue;
      }
      mp[w] = 1;
      out.push_back(w);
    }
  }
  long long mx = 0;
  vector<long long> ans;
  for (auto& v : out) {
    if (Val(v) > mx) {
      mx = Val(v);
      ans = v;
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << '\n';
  return 0;
}
