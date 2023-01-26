#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
unsigned long long factorial(long long n) {
  const unsigned long long M = 1000000007;
  unsigned long long f = 1;
  for (long long i = 3; i <= n; i++) f = (f * i) % M;
  return f;
}
void Solve() {
  long long n;
  cin >> n;
  long long ans = factorial(2 * n);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long TC = 1;
  cin >> TC;
  while (TC--) {
    Solve();
  }
  cerr << "\n"
       << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms"
       << "\n";
}
