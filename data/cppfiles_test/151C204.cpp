#include <bits/stdc++.h>
using namespace std;
const long long N = 500100;
void solve() {
  long long q;
  cin >> q;
  vector<pair<long long, long long>> v(q);
  vector<long long> par(N), ans;
  for (long long i = 0; i < q; i++) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long x;
      cin >> x;
      v[i] = {x, -1};
    } else {
      long long x, y;
      cin >> x >> y;
      v[i] = {x, y};
    }
  }
  reverse(v.begin(), v.end());
  for (long long i = 0; i < N; i++) par[i] = i;
  for (long long i = 0; i < q; i++) {
    if (v[i].second == -1) {
      long long x = v[i].first;
      ans.push_back(par[x]);
    } else {
      long long x = v[i].first;
      long long y = v[i].second;
      par[x] = par[y];
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
