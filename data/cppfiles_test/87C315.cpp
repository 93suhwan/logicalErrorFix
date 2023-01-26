#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[m];
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end(),
       [&](pair<long long, long long> p, pair<long long, long long> q) {
         if (p.first == q.first) return p.second > q.second;
         return p.first < q.first;
       });
  vector<long long> u;
  for (long long i = 0; i < m; i++) {
    u.push_back(v[i].second);
  }
  vector<bool> vec(m, false);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < u[i]; j++) {
      if (vec[j]) ans++;
    }
    vec[u[i]] = true;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
