#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const double EPS = 1e-9;
const long long dx[] = {1, -1, 0, 0};
const long long dy[] = {0, 0, 1, -1};
long long cal(long long k) { return (k * (k - 1) * (k - 2)) / 6; }
void solve() {
  long long n;
  cin >> n;
  vector<pii> v(n, {0, 0});
  map<long long, vector<long long>> mpt, mpd;
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (mpt.find(v[i].first) == mpt.end()) {
      mpt[v[i].first] = vector<long long>(1, v[i].second);
    } else {
      mpt[v[i].first].push_back(v[i].second);
    }
    if (mpd.find(v[i].second) == mpd.end()) {
      mpd[v[i].second] = vector<long long>(1, v[i].first);
    } else {
      mpd[v[i].second].push_back(v[i].first);
    }
  }
  if (mpt.size() == n || mpd.size() == n) {
    cout << cal(n) << '\n';
    return;
  }
  long long ans = 0;
  for (auto &K : mpt) {
    long long ksize = K.second.size();
    ans = ksize * (n - ksize) * (n - ksize - 1) / 2;
  }
  cout << ans << '\n';
}
int32_t main() {
  cin.sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int32_t tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
