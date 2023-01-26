#include <bits/stdc++.h>
using namespace std;
long long int t, n, k, p[200007], r[200007], q[200007], mins[200007];
map<long long int, vector<long long int>> x, y;
map<pair<long long int, long long int>, long long int> ri;
vector<pair<long long int, long long int>> v;
long long int get(long long int x) {
  return p[x] = (p[x] == x ? x : get(p[x]));
}
void uni(long long int x, long long int y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  if (r[x] == r[y]) r[x]++;
  if (r[x] > r[y]) swap(x, y);
  p[x] = y;
  mins[y] = min(mins[y], mins[x]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    x.clear(), y.clear(), v.clear(), ri.clear();
    iota(p, p + n + 1, 0);
    for (long long int i = 0; i < n; ++i) r[i] = 0;
    for (long long int i = 0; i < n; ++i) {
      long long int a, b;
      cin >> a >> b >> q[i];
      mins[i] = q[i];
      x[a].push_back(b);
      y[b].push_back(a);
      v.push_back({a, b});
      ri[{a, b}] = i;
    }
    for (auto i : x) sort(x[i.first].begin(), x[i.first].end());
    for (auto i : y) sort(y[i.first].begin(), y[i.first].end());
    for (long long int i = 0; i < n; ++i) {
      long long int right = upper_bound(y[v[i].second].begin(),
                                        y[v[i].second].end(), v[i].first) -
                            y[v[i].second].begin(),
                    down = upper_bound(x[v[i].first].begin(),
                                       x[v[i].first].end(), v[i].second) -
                           x[v[i].first].begin();
      if (right != (long long int)y[v[i].second].size() &&
          y[v[i].second][right] - v[i].first <= k) {
        long long int a = ri[{y[v[i].second][right], v[i].second}];
        uni(a, i);
      }
      if (down != (long long int)x[v[i].first].size() &&
          x[v[i].first][down] - v[i].second <= k) {
        long long int a = ri[{v[i].first, x[v[i].first][down]}];
        uni(a, i);
      }
    }
    long long int ans;
    vector<long long int> res(n, -1), re;
    for (long long int i = 0; i < n; ++i)
      if (res[get(i)] == -1) res[get(i)] = mins[get(i)];
    for (long long int i = 0; i < n; ++i)
      if (res[i] != -1) re.push_back(res[i]);
    sort(re.begin(), re.end());
    ans = (long long int)re.size() - 1;
    for (long long int i = 0; i < (long long int)re.size(); ++i)
      ans = min(ans, max(re[i], (long long int)re.size() - i - 2));
    cout << ans << '\n';
  }
  return 0;
}
