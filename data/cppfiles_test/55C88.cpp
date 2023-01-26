#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long bait = power(a, b / 2) % MOD;
  if (b & 1)
    return bait * bait * a;
  else
    return bait * bait;
}
void solve() {
  long long a;
  cin >> a;
  cout << (power(4, pow(2, a) - 2) * 6) % MOD << endl;
}
signed main() {
  long long queries = 1;
  while (queries--) {
    solve();
  }
  return 0;
}
