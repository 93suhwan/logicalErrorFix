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
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
void solve() {
  long long int n, m, i, ans = 0;
  cin >> n >> m;
  m++;
  long long int bit1, bit2;
  for (i = 31; i >= 0; i--) {
    bit1 = (n >> i) & 1;
    bit2 = (m >> i) & 1;
    if (bit1 == bit2) continue;
    if (bit1 && bit2 == 0) break;
    ans += (1 << i);
  }
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
