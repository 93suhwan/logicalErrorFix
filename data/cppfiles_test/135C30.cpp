#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
const int N = 2e6 + 5;
const long long int mod = 1e9 + 7;
void solve() {
  int n, k, i, ans = 0, mx = -1;
  cin >> n >> k;
  vector<int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  int m = n - 2 * k;
  map<int, int> mp;
  for (i = 0; i < m; i++) ans += a[i];
  for (i = m; i < n; i++) mp[a[i]]++;
  for (auto i : mp) amax(mx, i.second);
  if (mx > k) ans += mx - k;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
