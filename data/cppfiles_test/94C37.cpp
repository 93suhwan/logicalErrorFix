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
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T &&...args) {
  ((cout << args << endl), ...);
}
const long long int mod = 1e9 + 7, N = 1e5 + 1;
vector<pair<long long int, long long int>> moves = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve() {
  long long int n, k;
  cin >> n >> k;
  k++;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  for (long long int i = 0; i < n - 1; i++) {
    long long int noe = pow(10, a[i + 1] - a[i]) - 1;
    if (k > noe) {
      ans += noe * pow(10, a[i]);
      k -= noe;
    } else {
      ans += k * pow(10, a[i]);
      k = 0;
      break;
    }
  }
  ans += k * pow(10, a[n - 1]);
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
