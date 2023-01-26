#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
vector<int> mn1[N], mn2[N], mx1[N], mx2[N];
vector<int> a[N];
std::pair<int, int> ord[N];
int n, m;
int ok(int x) {
  int ans = 0;
  int z = 0;
  for (long long j = long long(0); j < long long(m); ++j) {
    if (z == 0 && mx1[x][j] >= mn2[x][j]) ans = j, ++z;
    if (z == 1 && mx2[x][j] >= mn1[x][j]) return 0;
  }
  return ans;
}
bool ans[N];
void solve() {
  cin >> n >> m;
  for (long long i = long long(0); i < long long(n); ++i) {
    a[i].resize(m);
    mn1[i].resize(m);
    mx1[i].resize(m);
    mn2[i].resize(m);
    mx2[i].resize(m);
    for (long long j = long long(0); j < long long(m); ++j) cin >> a[i][j];
    ord[i] = {a[i][0], i};
  }
  sort(ord, ord + n);
  for (long long j = long long(0); j < long long(m); ++j)
    mn1[1][j] = mx1[1][j] = a[ord[0].second][j];
  for (long long i = long long(1); i < long long(n - 1); ++i) {
    for (long long j = long long(0); j < long long(m); ++j)
      mn1[i + 1][j] = min(mn1[i][j], a[ord[i].second][j]),
              mx1[i + 1][j] = max(mx1[i][j], a[ord[i].second][j]);
  }
  for (long long j = long long(0); j < long long(m); ++j)
    mn2[n - 1][j] = mx2[n - 1][j] = a[ord[n - 1].second][j];
  for (long long i = long long(n - 1) - 1; i >= long long(1); --i) {
    for (long long j = long long(0); j < long long(m); ++j)
      mn2[i][j] = min(mn2[i + 1][j], a[ord[i].second][j]),
      mx2[i][j] = max(mx2[i + 1][j], a[ord[i].second][j]);
  }
  for (long long i = long long(1); i < long long(n); ++i) {
    if (ok(i)) {
      cout << "YES\n";
      for (long long j = long long(0); j < long long(i); ++j)
        ans[ord[j].second] = 1;
      for (long long j = long long(i); j < long long(n); ++j)
        ans[ord[j].second] = 0;
      for (long long i = long long(0); i < long long(n); ++i)
        cout << ("R\0B" + 2 * ans[i]);
      cout << ' ' << ok(i) << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
