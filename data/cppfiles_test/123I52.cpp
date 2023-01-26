#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> d;
const long long MAX = 1e6;
vector<long long> v[MAX];
long long dep[MAX], n, k;
long long x, y;
long long DfsPos(long long cur, long long last) {
  if (v[cur].size() == 1) return 1;
  long long mx = 0;
  for (auto i : v[cur])
    if (i != last) mx = max(mx, DfsPos(i, cur));
  dep[cur] = mx;
  return mx + 1;
}
long long w[MAX], r[MAX], b[MAX];
bool Compare(long long x, long long y) { return dep[x] < dep[y]; }
void Dfs(long long cur, long long last, long long Sub = 0) {
  vector<long long> vd;
  if (v[cur].size() == 1) {
    d.push_back(make_pair(Sub, cur));
    return;
  }
  for (auto i : v[cur])
    if (i != last) vd.push_back(i);
  sort(vd.begin(), vd.end(), Compare);
  Dfs(vd.back(), cur, Sub + 1);
  vd.pop_back();
  for (auto i : vd) Dfs(i, cur, 1);
}
long long Col(long long cur = 1, long long last = 1) {
  if (v[cur].size() == 1 && cur != 1) return r[cur];
  for (auto i : v[cur])
    if (i != last) w[cur] += Col(i, cur);
  if (w[cur])
    w[cur] = 1;
  else
    b[cur] = 1;
  return x + w[cur];
}
long long cb = 0, cr = 0, cw = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long val = k;
  for (long long i = 1; i < n; i++)
    cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
  DfsPos(1, 1);
  Dfs(1, 1, 1);
  sort(d.begin(), d.end());
  while (k-- && d.size()) {
    long long x = d.back().second;
    d.pop_back();
    r[x] = 1;
  }
  for (auto i : d) b[i.second] = 1;
  long long e = Col();
  d.clear();
  for (long long i = 1; i <= n; i++) cb += b[i], cr += r[i], cw += w[i];
  if (n == 2) {
    cout << 0;
    return 0;
  }
  if (cb > cr) {
    cout << cw * (cr - cb);
    return 0;
  }
  long long ans = cw * (cr - cb);
  while (cr < val) {
    cr++;
    cb--;
    ans = max(ans, cw * (cr - cb));
  }
  cout << ans;
  return 0;
}
