#include <bits/stdc++.h>
using namespace std;
long long modulus(long long a, long long b) {
  long long mod = a % b;
  if (mod < 0) mod += b;
  return mod;
}
void solve() {
  long long n;
  cin >> n;
  cout << -(n - 1) << " " << n << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
