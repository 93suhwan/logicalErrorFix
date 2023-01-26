#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int bp(int a, int b) {
  a %= 1000000007;
  int res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
int n;
const int N = 1e4 + 1;
int a[N];
bool f(int r) {
  vector<bitset<2048>> dp(2);
  for (int x = 0; x <= r; x++) dp[1][x] = true;
  for (int x = 0; x < n; x++) {
    dp[x % 2] |= (dp[(x + 1) % 2] << a[x]);
    dp[x % 2] |= (dp[(x + 1) % 2] >> a[x]);
    for (int y = r + 1; y < 2048; y++) dp[x % 2][y] = false;
    dp[((x + 1) % 2)].reset();
  }
  return dp[(n + 1) % 2].any();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int x = 0; x < n; x++) cin >> a[x];
    int g = -1;
    for (int x = 10; x >= 0; x--) {
      int fi = g + (1 << x);
      if (!f(fi)) g = fi;
    }
    cout << g + 1 << "\n";
  }
}
