#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const double EPS = 1e-9;
const long long dx[] = {1, -1, 0, 0};
const long long dy[] = {0, 0, 1, -1};
void solve() {
  long long n;
  cin >> n;
  vector<pii> v(n, {0, 0});
  vector<long long> cntx(n + 1, 0), cnty(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    cntx[v[i].first]++;
    cnty[v[i].second]++;
  }
  long long notof = 0;
  for (long long i = 0; i < n; i++) {
    notof += (cntx[v[i].first] - 1) * (cnty[v[i].second] - 1);
  }
  long long ans = n * (n - 1) * (n - 2) / 6;
  cout << ans - notof << '\n';
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
