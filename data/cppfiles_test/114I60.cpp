#include <bits/stdc++.h>
using namespace std;
long long cil(long long x, long long y) {
  if (x % y == 0) {
    return x / y;
  };
  return x / y + 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> sizes;
  vector<vector<long long>> a(n);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sizes.push_back(x);
    for (long long j = 0; j < sizes.back(); j++) {
      cin >> x;
      a[i].push_back(x);
    }
  }
  long long m;
  cin >> m;
  set<vector<long long>> s;
  for (long long i = 0; i < m; i++) {
    vector<long long> t;
    for (long long j = 0; j < n; j++) {
      long long x;
      cin >> x;
      x--;
      t.push_back(x);
    }
    s.insert(t);
  }
  vector<long long> t;
  for (long long i = 0; i < n; i++) t.push_back(sizes[i] - 1);
  auto sum = [&](vector<long long> p) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      ans += a[i][p[i]];
    }
    return ans;
  };
  priority_queue<pair<long long, vector<long long>>> pq;
  pq.push({sum(t), t});
  while (!pq.empty()) {
    auto root = pq.top();
    pq.pop();
    long long value = root.first;
    vector<long long> v = root.second;
    if (s.find(v) == s.end()) {
      for (auto x : v) cout << x + 1 << " ";
      cout << '\n';
      return;
    }
    for (long long i = 0; i < n; i++) {
      vector<long long> t;
      for (long long j = 0; j < n; j++) {
        t.push_back(v[j]);
      }
      if (t[i] > 0) {
        t[i]--;
        if ((long long)(pq).size() <= 2 * m) pq.push({sum(t), t});
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  for (long long tc = 1; tc <= tt; tc++) {
    solve();
  }
  return 0;
}
