#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1;
long long fact[N];
void preprocess() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
void solve() {
  long long n;
  cin >> n;
  long long res = 1;
  for (long long i = 3; i <= 2 * n; i++) {
    res = (res * i) % 1000000007;
  }
  cout << res << "\n";
}
int32_t main() {
  preprocess();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
