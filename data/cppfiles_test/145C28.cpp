#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1LL << 62;
struct Mine {
  long long x, y, timer;
  long long x_pos, y_pos;
  long long comp_num;
  Mine() : x(0), y(0), timer(0), x_pos(-1), y_pos(-1), comp_num(-1) {}
};
long long n, k;
vector<Mine> a;
vector<long long> x, y, timer;
bool near(long long l, long long r) {
  return a[l].x == a[r].x && abs(a[l].y - a[r].y) <= k ||
         a[l].y == a[r].y && abs(a[l].x - a[r].x) <= k;
}
bool x_less(long long l, long long r) {
  return (a[l].x < a[r].x || (a[l].x == a[r].x && a[l].y < a[r].y));
}
bool y_less(long long l, long long r) {
  return (a[l].y < a[r].y || (a[l].y == a[r].y && a[l].x < a[r].x));
}
void dfs(long long i, long long curr_comp) {
  a[i].comp_num = curr_comp;
  timer[curr_comp] = min(timer[curr_comp], a[i].timer);
  long long pos = a[i].x_pos;
  if (pos > 0 && near(i, x[pos - 1]) && a[x[pos - 1]].comp_num < 0)
    dfs(x[pos - 1], curr_comp);
  if (pos + 1 < n && near(i, x[pos + 1]) && a[x[pos + 1]].comp_num < 0)
    dfs(x[pos + 1], curr_comp);
  pos = a[i].y_pos;
  if (pos > 0 && near(i, y[pos - 1]) && a[y[pos - 1]].comp_num < 0)
    dfs(y[pos - 1], curr_comp);
  if (pos + 1 < n && near(i, y[pos + 1]) && a[y[pos + 1]].comp_num < 0)
    dfs(y[pos + 1], curr_comp);
}
void solve() {
  long long i;
  cin >> n >> k;
  a.resize(n);
  x.resize(n);
  y.resize(n);
  timer.resize(n);
  for (i = 0; i < n; ++i) {
    a[i] = Mine();
    cin >> a[i].x >> a[i].y >> a[i].timer;
    x[i] = i;
    y[i] = i;
    timer[i] = inf;
  }
  sort(x.begin(), x.end(), x_less);
  sort(y.begin(), y.end(), y_less);
  for (i = 0; i < n; ++i) {
    a[x[i]].x_pos = i;
    a[y[i]].y_pos = i;
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
