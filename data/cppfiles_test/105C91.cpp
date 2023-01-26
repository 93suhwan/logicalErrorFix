#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 998244353, INF = 1e9 + 7;
const long long BIG = 1e18;
const int block = 316;
const int base = 1000000000;
const int base_digits = 9;
const int tox[] = {0, 0, 1, -1}, toy[] = {1, -1, 0, 0};
int n, a[N], b[N], m[N], bp[N], d[N], x[N], y[N];
vector<pair<int, pair<int, int> > > vec[N];
bool was[N];
void clear() {
  for (int i = 1; i <= n; i++) {
    vec[d[i]].clear();
    was[d[i]] = 0;
  }
}
void solve(int test) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> m[i];
    bp[i] = b[i] - m[i];
    d[i] = bp[i] + a[i];
    int r = a[i] - max(0, m[i] - b[i]);
    int l = a[i] - min(m[i], a[i]);
    vec[d[i]].push_back({r, {l, i}});
  }
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    int i = d[j];
    if (was[i]) continue;
    was[i] = 1;
    sort(vec[i].begin(), vec[i].end());
    int mx = -INF;
    for (int p = 0; p < vec[i].size(); p++) {
      int r = vec[i][p].first;
      int l = vec[i][p].second.first;
      if (l <= mx) {
        int id = vec[i][p].second.second;
        x[id] = a[id] - mx;
        y[id] = m[id] - x[id];
        continue;
      }
      ans++;
      mx = max(mx, r);
      int id = vec[i][p].second.second;
      x[id] = a[id] - mx;
      y[id] = m[id] - x[id];
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    cout << x[i] << ' ' << y[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  int t = 1;
  while (q--) {
    solve(t);
    clear();
    t++;
  }
}
