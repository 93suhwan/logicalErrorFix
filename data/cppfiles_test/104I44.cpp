#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
array<int, 4> a[200005];
pair<int, int> res[200005];
int n, m;
long long cal(int id) {
  long long A = 0, B = 0;
  for (int i = 1; i <= n; ++i) a[i][0] = -a[i][0], A += a[i][1], B += a[i][2];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    int u = a[i][1];
    int v = a[i][2];
    int r = min(u, m);
    int l = max(0, m - v);
    while (r - l > 2) {
      int x1 = l + (r - l) / 3;
      int x2 = r - (r - l) / 3;
      long long f1 = abs(A - B - 2 * x1 + m);
      long long f2 = abs(A - B - 2 * x2 + m);
      if (f1 < f2)
        r = x2;
      else
        l = x1;
    }
    long long mindif = 1e18;
    pair<int, int> inc = {0, 0};
    for (int first = l; first <= r; ++first) {
      long long dif = abs(A - B - 2 * first + m);
      if (dif < mindif) {
        mindif = dif;
        inc = {first, m - first};
      }
    }
    A -= inc.first;
    B -= inc.second;
    res[a[i][3]] = inc;
  }
  return abs(A - B);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int first, second;
    cin >> first >> second;
    a[i] = {abs(first - second), first, second, i};
  }
  sort(a + 1, a + n + 1);
  long long u = cal(0);
  long long v = cal(1);
  if (u < v) u = cal(0);
  cout << min(u, v) << "\n";
  for (int i = 1; i <= n; ++i)
    cout << res[i].first << " " << res[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
