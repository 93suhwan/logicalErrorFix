#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("sse4.2")
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, m;
vector<long long> p;
set<long long> ps;
vector<pair<long long, long long>> seg;
bool viv = false;
void read() {
  cin >> n >> m;
  p.resize(n);
  for (auto &val : p) cin >> val;
  ps.clear();
  for (auto i : p) ps.insert(i);
  seg.resize(m);
  for (auto &s : seg) cin >> s.first >> s.second;
}
void clear1() {
  vector<pair<long long, long long>> rseg;
  for (auto s : seg) {
    long long l = s.first;
    long long r = s.second;
    auto z = ps.lower_bound(l);
    if (z != ps.end() && (*z) <= r) {
    } else {
      rseg.push_back(s);
    }
  }
  seg = rseg;
}
void clear2() {
  vector<pair<long long, long long>> rseg;
  sort(seg.begin(), seg.end());
  for (auto s : seg) {
    while (rseg.size() && s.second <= rseg.back().second) rseg.pop_back();
    rseg.push_back(s);
  }
  seg = rseg;
}
void make(vector<map<pair<long long, long long>, long long>> &dp, long long i,
          pair<long long, long long> pr, long long val) {
  if (dp[i].find(pr) == dp[i].end())
    dp[i][pr] = val;
  else
    dp[i][pr] = min(dp[i][pr], val);
}
void solver() {
  n = ps.size();
  m = seg.size();
  vector<map<pair<long long, long long>, long long>> dp(m);
  for (long long i = 0; i < m; i++) {
    if (viv) cout << "seg " << i << endl;
    long long l = seg[i].first;
    long long r = seg[i].second;
    {
      auto z = ps.upper_bound(r);
      if (z != ps.end()) {
        long long nx = *z;
        if (viv) cout << "\tnx = " << nx << endl;
        if (i == 0) {
          pair<long long, long long> pr = {nx, 0};
          make(dp, i, pr, 2 * (nx - r));
          pr = {nx, 1};
          make(dp, i, pr, 1 * (nx - r));
        } else {
          for (auto pp : dp[i - 1]) {
            auto old_pr = pp.first;
            if (old_pr.first == nx) make(dp, i, old_pr, dp[i - 1][old_pr]);
          }
          for (auto pp : dp[i - 1]) {
            auto old_pr = pp.first;
            if (old_pr.first != nx) {
              pair<long long, long long> pr = {nx, 0};
              make(dp, i, pr, pp.second + 2 * (nx - r));
              pr = {nx, 1};
              make(dp, i, pr, pp.second + 1 * (nx - r));
            }
          }
        }
      } else {
      }
    }
    {
      auto z = ps.lower_bound(l);
      if (z != ps.begin()) {
        z--;
        long long prv = *z;
        if (viv) cout << "\tprv = " << prv << endl;
        if (i == 0) {
          pair<long long, long long> pr = {prv, 0};
          make(dp, i, pr, 1 * (l - prv));
          pr = {prv, 1};
          make(dp, i, pr, 2 * (l - prv));
        } else {
          if (prv < seg[i - 1].first) {
            pair<long long, long long> pr = {prv, 0};
            make(dp, i, pr, dp[i - 1][pr] + 1 * (l - seg[i - 1].first));
            pr = {prv, 1};
            make(dp, i, pr, dp[i - 1][pr] + 2 * (l - seg[i - 1].first));
          } else {
            for (auto pp : dp[i - 1]) {
              auto old_pr = pp.first;
              if (old_pr.first == prv) {
                pair<long long, long long> pr = {prv, 0};
                make(dp, i, pr, dp[i - 1][pr] + 1 * (l - prv));
                pr = {prv, 1};
                make(dp, i, pr, dp[i - 1][pr] + 2 * (l - prv));
              }
            }
            for (auto pp : dp[i - 1]) {
              auto old_pr = pp.first;
              if (old_pr.first != prv) {
                pair<long long, long long> pr = {prv, 0};
                make(dp, i, pr, dp[i - 1][pr] + 1 * (l - prv));
                pr = {prv, 1};
                make(dp, i, pr, dp[i - 1][pr] + 2 * (l - prv));
              }
            }
          }
        }
      } else {
      }
    }
  }
  if (viv) {
    for (long long i = 0; i < m; i++) {
      cout << "ans for seg " << i << endl;
      for (auto pp : dp[i]) {
        cout << "\t{" << pp.first.first << ' ' << pp.first.second
             << "} = " << pp.second << endl;
      }
    }
  }
  long long ans = 0;
  if (m) {
    ans = inf;
    for (auto p : dp.back()) ans = min(ans, p.second);
  }
  cout << ans << '\n';
}
void solve() {
  read();
  clear1();
  clear2();
  if (viv) {
    cout << "seg = " << endl;
    for (auto s : seg) cout << s.first << ' ' << s.second << endl;
    cout << endl;
  }
  solver();
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
