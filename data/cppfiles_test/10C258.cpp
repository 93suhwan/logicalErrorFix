#include <bits/stdc++.h>
using namespace std;
long long poww(long long n, long long r) {
  long long res = 1;
  while (r) {
    if (r & 1) res = (res * n);
    n = (n * n);
    r = r >> 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  map<long long, long long> mp;
  vector<long long> ans(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  if (k == 1) {
    map<long long, long long> vs;
    for (long long i = 0; i < n; i++) {
      if (vs[a[i]] == 0) {
        ans[i] = 1;
        vs[a[i]]++;
      }
    }
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  long long ctr = 0;
  map<long long, queue<long long>> mpq;
  map<long long, long long> vis;
  vector<pair<long long, long long>> v;
  for (auto it : mp) {
    if (it.second >= k) {
      long long ctr = 1;
      while (ctr <= k) {
        mpq[it.first].push(ctr);
        ctr++;
      }
      vis[it.first]++;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (!mpq[a[i]].empty()) {
      ans[i] = mpq[a[i]].front();
      mpq[a[i]].pop();
    }
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i] == 0 && !vis[a[i]]) {
      v.push_back({a[i], i});
    }
  }
  sort((v).begin(), (v).end());
  long long cur = v.size();
  for (long long i = 0; i + k - 1 < v.size(); i += k) {
    long long ctr = 1;
    long long j = i;
    while (ctr <= k) {
      ans[v[j].second] = ctr;
      ctr++;
      j++;
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
