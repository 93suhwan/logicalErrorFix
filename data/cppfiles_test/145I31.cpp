#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    long long n, k;
    cin >> n >> k;
    map<pair<long long, long long>, long long> timers;
    set<pair<long long, long long> > bombsx, bombsy;
    for (long long i = 1; i <= n; ++i) {
      long long x, y, t;
      cin >> x >> y >> t;
      bombsx.insert({x, y});
      bombsy.insert({y, x});
      timers[{x, y}] = t;
    }
    vector<long long> min_time;
    while (bombsx.size()) {
      auto itr = bombsx.begin();
      long long min_timer = 1e9;
      queue<pair<long long, long long> > nodes;
      nodes.push({itr->first, itr->second});
      while (nodes.size()) {
        long long x = nodes.front().first, y = nodes.front().second;
        nodes.pop();
        itr = bombsx.lower_bound({x, y - k});
        while (itr != bombsx.end() and itr->first == x and
               abs(itr->second - y) <= k) {
          min_timer = min(min_timer, timers[{itr->first, itr->second}]);
          auto aux = itr;
          itr++;
          nodes.push({aux->first, aux->second});
          bombsx.erase({aux->first, aux->second});
          bombsy.erase({aux->second, aux->first});
        }
        itr = bombsy.lower_bound({y, x - k});
        while (itr != bombsy.end() and itr->first == y and
               abs(itr->second - x) <= k) {
          min_timer = min(min_timer, timers[{itr->second, itr->first}]);
          auto aux = itr;
          itr++;
          nodes.push({aux->second, aux->first});
          bombsx.erase({aux->first, aux->second});
          bombsy.erase({aux->second, aux->first});
        }
      }
      min_time.push_back(min_timer);
    }
    sort(min_time.begin(), min_time.end());
    long long ans = min_time.size() - 1;
    n = min_time.size();
    for (long long i = 0; i < n; ++i) {
      ans = min(ans, max(min_time[i], n - 2ll - i));
    }
    cout << ans << '\n';
  }
  return 0;
}
