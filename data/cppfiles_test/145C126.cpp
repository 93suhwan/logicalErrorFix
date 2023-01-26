#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct UF {
  long long N;
  std::vector<long long> e;
  vector<long long> minTime;
  void init(long long n, vector<long long>& time) {
    e.assign(n, -1);
    minTime.assign(n, inf);
    for (long long i = 1; i < (long long)time.size(); i++) {
      minTime[i] = time[i];
    }
  }
  bool sameSet(long long a, long long b) { return find(a) == find(b); }
  long long size(long long x) { return -e[find(x)]; }
  long long find(long long x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  long long getMinTime(long long x) {
    long long parent = find(x);
    return minTime[x];
  }
  bool join(long long a, long long b) {
    a = find(a), b = find(b);
    long long minTimeA = minTime[a], minTimeB = minTime[b];
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    minTime[a] = min(minTimeA, minTimeB);
    return true;
  }
};
void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, vector<pair<long long, long long>>> x_coord, y_coord;
  vector<long long> timers(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long x, y, time;
    cin >> x >> y >> time;
    timers[i] = time;
    x_coord[x].push_back(make_pair(y, i));
    y_coord[y].push_back(make_pair(x, i));
  }
  UF dsu;
  dsu.init(n + 1, timers);
  for (auto it : x_coord) {
    auto v = it.second;
    sort(v.begin(), v.end());
    for (long long i = 1; i < (long long)v.size(); i++) {
      if (v[i].first - v[i - 1].first <= k)
        dsu.join(v[i].second, v[i - 1].second);
    }
  }
  for (auto it : y_coord) {
    auto v = it.second;
    sort(v.begin(), v.end());
    for (long long i = 1; i < (long long)v.size(); i++) {
      if (v[i].first - v[i - 1].first <= k)
        dsu.join(v[i].second, v[i - 1].second);
    }
  }
  std::vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    if (dsu.find(i) == i) v.push_back(dsu.getMinTime(i));
  }
  sort(v.begin(), v.end());
  v.pop_back();
  n = (long long)v.size();
  long long left = 0, right = n - 1;
  long long ans = 0;
  while (left < n && v[left] == 0) left++;
  while (left <= right) {
    ans++;
    while (left < n && v[left] == ans) left++;
    if (right >= left) right--;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
