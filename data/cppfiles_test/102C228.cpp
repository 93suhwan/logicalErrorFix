#include <bits/stdc++.h>
const int N = 1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
struct mnx {
  long long int xr, xl, yr, yl;
};
mnx v[1000006];
long long int a, b;
bool ok(long long int i) {
  return (v[i].xr - v[i].xl < a) && (v[i].yr - v[i].yl < b);
}
void solve() {
  cin >> a >> b;
  string s;
  cin >> s;
  long long int sz = s.size();
  long long int x = 0, y = 0;
  for (long long int i = 1; i <= sz; i++) {
    if (s[i - 1] == 'U')
      x--;
    else if (s[i - 1] == 'D')
      x++;
    else if (s[i - 1] == 'R')
      y++;
    else
      y--;
    v[i].xl = v[i].xr = x;
    v[i].yl = v[i].yr = y;
    v[i].xl = min(v[i].xl, v[i - 1].xl);
    v[i].yl = min(v[i].yl, v[i - 1].yl);
    v[i].xr = max(v[i].xr, v[i - 1].xr);
    v[i].yr = max(v[i].yr, v[i - 1].yr);
  }
  x = y = 1;
  for (long long int i = 1; i <= sz; i++) {
    if (v[i].xr - v[i].xl < a && v[i].yr - v[i].yl < b)
      x = 1 + (-v[i].xl), y = 1 + (-v[i].yl);
  }
  x = min(x, a);
  y = min(y, b);
  cout << x << ' ' << y << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
