#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5, mod = 998244353, lmt = 17;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > arr(n);
  for (long long x = 0; x < n; x++) {
    long long t;
    cin >> t;
    arr[x] = {t, x};
  }
  sort(arr.begin(), arr.end());
  vector<pair<long long, long long> > ans;
  auto cur = arr.back();
  arr.pop_back();
  while (arr.size()) {
    if (cur.first == 0) {
      cur = arr.back();
      arr.pop_back();
    } else if (arr.back().first == 0)
      arr.pop_back();
    else {
      arr[((long long)(arr.size())) - 1].first--;
      cur.first--;
      ans.push_back({cur.second, arr.back().second});
    }
  }
  if (cur.first) {
    vector<pair<long long, long long> > nans;
    while (cur.first > 1 and ans.size()) {
      auto last = ans.back();
      ans.pop_back();
      nans.push_back({last.first, cur.second});
      nans.push_back({last.second, cur.second});
      cur.first -= 2;
    }
    for (auto &y : nans) ans.push_back(y);
  }
  cout << ans.size() << '\n';
  for (auto &x : ans) {
    cout << x.first + 1 << ' ' << x.second + 1 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    cerr << "Case #" << i << ": \n";
    solve();
  }
  cerr << "\n" << clock() << " ms";
}
