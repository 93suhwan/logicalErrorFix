#include <bits/stdc++.h>
using namespace std;
const int PI = 3.1415927;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
const int N = 10000 + 5;
const int M = 200000 + 5;
int n, m;
void solve() {
  cin >> n >> m;
  int ans = inf;
  for (int i = 0; i < 31; ++i) {
    ans = min(ans, ((n >> i) << i) ^ ((1 + (m >> i)) << i));
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
