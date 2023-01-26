#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
void run();
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  run();
  return 0;
}
using Pll = pair<ll, ll>;
struct Event {
  int t;
  ll first;
  int i;
  bool operator<(const Event& r) const {
    return make_pair(first, t) < make_pair(r.first, r.t);
  }
};
ll solve(const vector<ll>& points, const vector<Pll>& segs) {
  vector<ll> dp(int((segs).size()) + 1, 1e18);
  dp[0] = 0;
  int after = 0;
  ;
  for (int j = (0); j < (int((points).size())); j++) {
    auto& p = points[j];
    while (after < int((segs).size()) && segs[after].first < p) after++;
    int before = 0;
    if (j > 0) {
      before = after;
      while (before > 0 && segs[before - 1].first > points[j - 1]) before--;
    }
    int end = int((segs).size());
    if (j + 1 < int((points).size())) {
      end = after;
      while (end + 1 < int((segs).size()) &&
             segs[end + 1].first < points[j + 1])
        end++;
      end++;
    }
    for (int i = (after); i < (end); i++) {
      dp[i + 1] = min(dp[i + 1], dp[after] + segs[i].first - p);
    }
    for (int i = (before); i < (after); i++) {
      dp[after] = min(dp[after], dp[i] + p - segs[i].second);
    }
    vector<ll> pref(after - before + 1, 1e18);
    vector<ll> suf(after - before + 1, 1e18);
    for (int i = (before); i < (after); i++) {
      pref[i - before + 1] = min(pref[i - before], dp[i] + p - segs[i].second);
    }
    for (int i = after - 1; i >= before; i--) {
      suf[i - before] =
          min(suf[i - before + 1], dp[i] + (p - segs[i].second) * 2);
    }
    int pos = after;
    for (int i = (after); i < (end); i++) {
      while (pos > before && p - segs[pos - 1].second < segs[i].first - p)
        pos--;
      dp[i + 1] =
          min(dp[i + 1], min(pref[pos - before] + (segs[i].first - p) * 2,
                             suf[pos - before] + segs[i].first - p));
      ;
    };
  }
  return dp.back();
}
void run() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> points(n);
    vector<Pll> segs(m);
    for (auto& p : (points)) cin >> p;
    for (auto& s : (segs)) cin >> s.first >> s.second;
    vector<Pll> good;
    ll far = 1e18;
    sort((segs).begin(), (segs).end(), [&](Pll a, Pll b) {
      return make_pair(-a.first, a.second) < make_pair(-b.first, b.second);
    });
    for (auto& s : (segs)) {
      if (s.second < far) {
        good.push_back(s);
        far = s.second;
      }
    }
    segs = move(good);
    good.clear();
    m = int((segs).size());
    vector<Event> events;
    for (auto& p : (points)) {
      events.push_back({1, p, -1});
    }
    for (int i = (0); i < (m); i++) {
      auto& s = segs[i];
      events.push_back({0, s.first, i});
      events.push_back({2, s.second, i});
    }
    sort((events).begin(), (events).end());
    Vi cnt(m);
    int seen = 0;
    for (auto& e : (events)) {
      if (e.t == 1) {
        seen++;
      } else if (e.t == 0) {
        cnt[e.i] = seen;
      } else if (seen - cnt[e.i] == 0) {
        good.push_back(segs[e.i]);
      }
    }
    segs = move(good);
    good.clear();
    m = int((segs).size());
    if (segs.empty()) {
      cout << 0 << '\n';
      continue;
    }
    sort((points).begin(), (points).end());
    sort((segs).begin(), (segs).end());
    ll ans = solve(points, segs);
    cout << ans << '\n';
  }
}
