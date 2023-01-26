#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<long long> P, S;
  DSU(long long n) {
    P.resize(n + 1);
    S.resize(n + 1, 1);
    for (long long i = 1; i <= n; i++) P[i] = i;
  }
  long long find(long long x) {
    if (x == P[x]) return x;
    return P[x] = find(P[x]);
  }
  bool merge(long long a, long long b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (S[a] < S[b]) swap(a, b);
    S[a] += S[b];
    P[b] = a;
    return 1;
  }
  long long same(long long a, long long b) { return find(a) == find(b); }
};
void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, vector<pair<long long, long long>>> mpx, mpy;
  vector<long long> val(n);
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y >> val[i];
    mpx[x].emplace_back(y, i);
    mpy[y].emplace_back(x, i);
  }
  DSU d(n);
  for (auto [u, vv] : mpx) {
    auto v = vv;
    sort(v.begin(), v.end());
    for (long long i = 1; i < v.size(); i++) {
      if (abs(v[i].first - v[i - 1].first) <= k) {
        d.merge(v[i].second, v[i - 1].second);
      }
    }
  }
  for (auto [u, vv] : mpy) {
    auto v = vv;
    sort(v.begin(), v.end());
    for (long long i = 1; i < v.size(); i++) {
      if (abs(v[i].first - v[i - 1].first) <= k) {
        d.merge(v[i].second, v[i - 1].second);
      }
    }
  }
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    long long dr = d.find(i);
    if (mp.find(dr) == mp.end()) {
      mp[dr] = val[i];
    } else {
      mp[dr] = min(mp[dr], val[i]);
    }
  }
  vector<long long> dx;
  for (auto [u, v] : mp) dx.push_back(v);
  sort(dx.begin(), dx.end());
  reverse(dx.begin(), dx.end());
  for (long long i = 1; i < dx.size(); i++) {
    if (dx[i] <= i - 1) {
      cout << i - 1 << '\n';
      return;
    }
  }
  cout << dx.size() - 1 << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
