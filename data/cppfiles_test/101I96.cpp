#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void solve(int test_case) {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> x(n), y(m);
  for (auto &i : x) cin >> i;
  for (auto &i : y) cin >> i;
  sort((x).begin(), (x).end());
  sort((y).begin(), (y).end());
  vector<pair<long long, long long>> ver, hor;
  for (long long i = 0; i < k; ++i) {
    long long a, b;
    cin >> a >> b;
    ver.push_back({a, b});
    hor.push_back({b, a});
  }
  sort((ver).begin(), (ver).end());
  sort((hor).begin(), (hor).end());
  long long ans = 0;
  for (long long i = 0; i < n - 1; ++i) {
    auto ind =
        upper_bound((ver).begin(), (ver).end(), make_pair(x[i] + 1LL, -1LL)) -
        ver.begin();
    unordered_map<long long, vector<long long>> dist;
    while (ind < ((int)(ver).size()) && ver[ind].first < x[i + 1]) {
      dist[ver[ind].second].push_back(0);
      ++ind;
    }
    long long sz = 1;
    long long tt = 0;
    for (auto p : dist) {
      sz *= ((int)(p.second).size());
      ++tt;
    }
    ans += (tt * (tt - 1) / 2) * sz;
  }
  for (long long i = 0; i < m - 1; ++i) {
    auto ind =
        upper_bound((hor).begin(), (hor).end(), make_pair(y[i] + 1LL, -1LL)) -
        hor.begin();
    unordered_map<long long, vector<long long>> dist;
    while (ind < ((int)(hor).size()) && hor[ind].first < y[i + 1]) {
      dist[hor[ind].second].push_back(0);
      ++ind;
    }
    long long sz = 1;
    long long tt = 0;
    for (auto p : dist) {
      sz *= ((int)(p.second).size());
      ++tt;
    }
    ans += (tt * (tt - 1) / 2) * sz;
  }
  cout << ans << '\n';
}
signed main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) solve(tc);
}
