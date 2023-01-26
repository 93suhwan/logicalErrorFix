#include <bits/stdc++.h>
using namespace std;
long long const N = 2e5 + 3, oo = 1e9;
int v[N], n;
bool ok(int can) {
  vector<int> gain(n);
  for (int i = n - 1; i > 1; --i) {
    if (v[i] + gain[i] < can) return false;
    int gg = min(v[i], gain[i] + v[i] - can);
    gain[i - 1] += gg / 3;
    gain[i - 2] += gg / 3 * 2;
  }
  return (gain[0] + v[0] >= can && gain[1] + v[1] >= can);
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> v[i];
  int l = 1, r = oo, mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
