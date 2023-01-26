#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, x = 0, y = 0;
  cin >> n >> m;
  vector<pair<long long, long long>> pr, ans(n);
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    pr.push_back({a, b});
  }
  for (long long i = 0; i < n; i++) {
    if (pr[i].first >= m) {
      ans[i].first = m;
      ans[i].second = 0;
    } else {
      ans[i].first = pr[i].first;
      ans[i].second = m - ans[i].first;
    }
    pr[i].first -= ans[i].first;
    pr[i].second -= ans[i].second;
    x += pr[i].first;
    y += pr[i].second;
  }
  if (x > y) {
    for (long long i = 0; i < n; i++) {
      if (x - y > 1 and pr[i].first > 0 and ans[i].second > 0) {
        long long eat = min({(x - y) / 2, pr[i].first, ans[i].second});
        x -= eat;
        y += eat;
        ans[i].first += eat;
        ans[i].second -= eat;
      }
    }
  } else {
    for (long long i = 0; i < n; i++) {
      if (y - x > 1 and ans[i].first > 0 and pr[i].second > 0) {
        long long eat = min({(y - x) / 2, pr[i].second, ans[i].first});
        x += eat;
        y -= eat;
        ans[i].first -= eat;
        ans[i].second += eat;
      }
    }
  }
  cout << abs(x - y) << "\n";
  for (auto u : ans) {
    cout << u.first << " " << u.second << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) solve();
  return 0;
}
