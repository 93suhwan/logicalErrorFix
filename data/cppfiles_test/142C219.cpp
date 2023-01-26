#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 5e5 + 10;
template <typename... T>
void debug(T&... args) {
  cout << "\n==================\n";
  ((cout << args << ", "), ...);
  cout << "\n==================\n";
}
template <typename T>
void debug(vector<T>& a) {
  cout << "\n==============\n";
  for (auto& e : a) cout << e << ' ';
  cout << "\n==============\n";
}
template <typename... T>
void put(T&... args) {
  ((cout << args << " "), ...);
}
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long> > p(m, vector<long long>(n));
  for (auto& e : p)
    for (auto& f : e) cin >> f;
  vector<pair<long long, long long> > ans(n, {-1, -1});
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      if (p[i][j] > ans[j].first) {
        ans[j].first = p[i][j];
        ans[j].second = i;
      }
    }
  }
  map<long long, long long> mp;
  for (auto& e : ans) mp[e.second]++;
  long long sol = 1e18;
  for (long long i = 0; i < n; i++) sol = min(sol, ans[i].first);
  if (mp.size() < n) {
    cout << sol << '\n';
    return;
  }
  sol = -1;
  for (long long i = 0; i < m; i++) {
    pair<long long, long long> p1;
    pair<long long, long long> p2;
    vector<pair<long long, long long> > gifts(n);
    for (long long j = 0; j < n; j++) {
      gifts[j].first = p[i][j];
      gifts[j].second = j;
    }
    sort(gifts.begin(), gifts.end());
    p1 = gifts[n - 1];
    p2 = gifts[n - 2];
    long long temp = 1e18;
    for (long long j = 0; j < n; j++) {
      if (p1.second == j)
        temp = min(temp, p1.first);
      else if (p2.second == j)
        temp = min(temp, p2.first);
      else
        temp = min(temp, ans[j].first);
    }
    sol = max(sol, temp);
  }
  cout << sol << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
