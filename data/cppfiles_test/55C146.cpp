#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long ways(int layers) {
  if (layers == 1)
    return 1;
  else {
    long long childWays = (4 * ways(layers - 1)) % MOD;
    return (childWays * childWays) % MOD;
  }
}
signed main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << (6 * ways(k)) % MOD << '\n';
}
