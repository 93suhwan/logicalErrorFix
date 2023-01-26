#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1LL << 62;
struct Mine {
  long long x, y, timer;
  long long x_pos, y_pos;
  long long comp_num;
  Mine() : x(0), y(0), timer(0), x_pos(-1), y_pos(-1), comp_num(-1) {}
  Mine(long long xx, long long yy, long long tm)
      : x(xx), y(yy), timer(tm), x_pos(-1), y_pos(-1), comp_num(-1) {}
};
long long n, k;
vector<Mine> a;
map<long long, set<pair<long long, long long>>> x, y;
vector<long long> timer;
bool my_less(pair<long long, long long> l, pair<long long, long long> r) {
  return l.first < r.first;
}
void dfs(long long i, long long curr_comp) {
  a[i].comp_num = curr_comp;
  timer[curr_comp] = min(timer[curr_comp], a[i].timer);
  auto& vy = x[a[i].x];
  auto it = vy.find(make_pair(a[i].y, i));
  if (it != vy.begin()) {
    auto j = *prev(it);
    if (abs(a[i].y - j.first) <= k && a[j.second].comp_num < 0)
      dfs(j.second, curr_comp);
  }
  if (next(it) != vy.end()) {
    auto j = *next(it);
    if (abs(a[i].y - j.first) <= k && a[j.second].comp_num < 0)
      dfs(j.second, curr_comp);
  }
  auto& vx = y[a[i].y];
  it = vx.find(make_pair(a[i].x, i));
  if (it != vx.begin()) {
    auto j = *prev(it);
    if (abs(a[i].x - j.first) <= k && a[j.second].comp_num < 0)
      dfs(j.second, curr_comp);
  }
  if (next(it) != vx.end()) {
    auto j = *next(it);
    if (abs(a[i].x - j.first) <= k && a[j.second].comp_num < 0)
      dfs(j.second, curr_comp);
  }
}
void solve() {
  long long i;
  cin >> n >> k;
  a.resize(n);
  x.clear();
  y.clear();
  timer.resize(n);
  for (i = 0; i < n; ++i) {
    long long xx, yy, tm;
    cin >> xx >> yy >> tm;
    a[i] = Mine(xx, yy, tm);
    x[xx].insert(make_pair(yy, i));
    y[yy].insert(make_pair(xx, i));
    timer[i] = inf;
  }
  long long curr_component = 0;
  for (i = 0; i < n; ++i)
    if (a[i].comp_num < 0) dfs(i, curr_component++);
  sort(timer.begin(), timer.begin() + curr_component, greater<long long>());
  long long res = 0;
  for (i = 0; i < curr_component; ++i) {
    if (timer[i] <= res) break;
    if (i + 1 < curr_component && timer[i + 1] > res) res++;
  }
  cout << res << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
