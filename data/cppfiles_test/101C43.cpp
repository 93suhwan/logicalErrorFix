#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
struct BIT {
  long long N;
  vector<long long> bit;
  void init(long long n) {
    N = n;
    bit.assign(n + 1, 0);
  }
  void update(long long idx, long long val) {
    while (idx <= N) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  long long pref(long long idx) {
    long long ans = 0;
    while (idx > 0) {
      ans += bit[idx];
      idx -= idx & -idx;
    }
    return ans;
  }
  long long rsum(long long l, long long r) { return pref(r) - pref(l - 1); }
  long long search(long long val) {
    long long curSum = 0, pos = 0;
    for (long long i = log2(N) + 1; i >= 0; i--) {
      if (pos + (1 << i) < N && curSum + bit[pos + (1 << i)] < val) {
        curSum += bit[pos + (1 << i)];
        pos += (1 << i);
      }
    }
    return pos + 1;
  }
  void updateMax(long long idx, long long val) {
    while (idx <= N) {
      bit[idx] = max(bit[idx], val);
      idx += idx & -idx;
    }
  }
  long long prefMax(long long idx) {
    long long ans = -2e9;
    while (idx > 0) {
      ans = max(ans, bit[idx]);
      idx -= idx & -idx;
    }
    return ans;
  }
};
long long nC2(long long n) { return n * (n - 1) / 2; }
long long n, m, k;
long long x[N], y[N];
map<long long, vector<long long> > xs, ys;
pair<long long, long long> loc[N];
BIT bit;
long long get(map<long long, vector<long long> > &x,
              map<long long, vector<long long> > &y) {
  vector<pair<long long, long long> > v;
  for (auto &it : x) {
    for (auto &j : it.second) v.push_back({j, it.first});
  }
  sort(v.begin(), v.end());
  y[-1];
  y[1e6 + 4];
  long long idx = -1;
  long long ans = 0;
  for (auto &it : y) {
    map<long long, long long> m;
    while (idx + 1 < v.size() && v[idx + 1].first < it.first) {
      long long y = v[idx + 1].first;
      m[v[idx + 1].second] += 1;
      bit.update(v[idx + 1].second, 1);
      idx++;
    }
    for (auto &it : m)
      ans += it.second * (bit.rsum(1, 1e6 + 3) - bit.rsum(it.first, it.first));
    for (auto &it : m) bit.update(it.first, -it.second);
  }
  return ans / 2;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  bit.init(1e6 + 5);
  while (t--) {
    cin >> n >> m >> k;
    xs.clear();
    ys.clear();
    for (long long i = 1; i <= n; i++) {
      cin >> x[i];
      x[i]++;
      xs[x[i]];
    }
    for (long long i = 1; i <= m; i++) {
      cin >> y[i];
      y[i]++;
      ys[y[i]];
    }
    for (long long i = 1; i <= k; i++) {
      cin >> loc[i].first >> loc[i].second;
      loc[i].first++;
      loc[i].second++;
      long long curx = loc[i].first;
      long long cury = loc[i].second;
      if (xs.count(curx) && ys.count(cury))
        continue;
      else if (xs.count(curx))
        xs[curx].push_back(cury);
      else
        ys[cury].push_back(curx);
    }
    long long ans = 0;
    ans += get(xs, ys);
    ans += get(ys, xs);
    cout << ans << "\n";
  }
  return 0;
}
