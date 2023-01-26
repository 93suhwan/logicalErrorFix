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
  for (auto yy : xa) {
    for (long long i = 1; i <= yy.second.size() - 1; i++) {
      if (abs(yy.second[i].first - yy.second[i - 1].first) <= k)
        cmps.merge_sets(yy.second[i].second, yy.second[i - 1].second);
    }
  }
  for (auto xx : ya) {
    for (long long i = 1; i <= xx.second.size() - 1; i++) {
      if (abs(xx.second[i].first - xx.second[i - 1].first) <= k)
        cmps.merge_sets(xx.second[i].second, xx.second[i - 1].second);
    }
  }
  map<long long, long long> comp_mp;
  for (long long i = 1; i <= n; i++) {
    long long c = cmps.find_set(i);
    comp_mp[c] = time_dsu[c];
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
