#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long parent[N], size_r[N], time_dsu[N], size_all = 0;
struct DSU {
  long long make_set(long long value, long long t) {
    if (value < N) {
      parent[value] = value;
      time_dsu[value] = t;
      size_r[value] = 1;
      size_all++;
      return value;
    } else
      return -1;
  }
  long long find_set(long long value) {
    if (parent[value] == value) return value;
    return parent[value] = find_set(parent[value]);
  }
  long long merge_sets(long long a, long long b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return a;
    if (size_r[a] < size_r[b]) swap(a, b);
    parent[b] = a;
    size_r[a] += size_r[b];
    time_dsu[a] = min(time_dsu[a], time_dsu[b]);
    return a;
  }
};
long long n, k;
vector<long long> comp;
bool check(long long m) {
  long long cnt = 0;
  for (auto el : comp) cnt += (el > m);
  return (cnt <= m);
}
long long bin_s() {
  long long l = 0, r = 1e10;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }
  return r;
}
void solve() {
  cin >> n >> k;
  vector<pair<long long, long long>> cord(n + 1);
  vector<long long> time(n + 1);
  map<long long, vector<pair<long long, long long>>> xa, ya;
  DSU cmps;
  for (long long i = 1; i <= n; i++) {
    cin >> cord[i].first >> cord[i].second >> time[i];
    time[i]++;
    xa[cord[i].first].push_back({cord[i].second, i});
    ya[cord[i].second].push_back({cord[i].first, i});
    cmps.make_set(i, time[i]);
  }
  for (long long i = 1; i <= n; i++) {
    long long cur = cmps.find_set(i);
    long long x = cord[i].first, y = cord[i].second;
    long long x_begin =
        lower_bound(xa[x].begin(), xa[x].end(), make_pair(y - k, 0ll)) -
        xa[x].begin();
    long long x_end =
        upper_bound(xa[x].begin(), xa[x].end(), make_pair(y + k, 0ll)) -
        xa[x].begin() - 1;
    for (long long j = x_begin; j <= x_end; j++) {
      long long v = xa[x][j].second;
      long long vs = cmps.find_set(v);
      cur = cmps.merge_sets(cur, vs);
    }
    long long y_begin =
        lower_bound(ya[y].begin(), ya[y].end(), make_pair(x - k, 0ll)) -
        ya[y].begin();
    long long y_end =
        upper_bound(ya[y].begin(), ya[y].end(), make_pair(x + k, 0ll)) -
        ya[y].begin() - 1;
    for (long long j = y_begin; j <= y_end; j++) {
      long long v = ya[y][j].second;
      long long vs = cmps.find_set(v);
      cur = cmps.merge_sets(cur, vs);
    }
  }
  map<long long, long long> comp_mp;
  for (long long i = 1; i <= n; i++) {
    long long c = cmps.find_set(i);
    if (comp_mp[c] == 0) comp_mp[c] = 1e9;
    comp_mp[c] = min(comp_mp[c], time[i]);
  }
  for (auto el : comp_mp) comp.push_back(el.second);
  sort(comp.begin(), comp.end());
  long long ans = bin_s();
  cout << ans - 1 << '\n';
  comp.clear();
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
