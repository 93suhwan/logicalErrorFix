#include <bits/stdc++.h>
using namespace std;
int mod = 1000000000 + 7, t, n, q;
long long solve(int n, int k) {
  return k - (k & -k) ? (solve(n, k - (k & -k)) + solve(n, k & -k)) % mod
         : k == 1     ? 1
                      : n * solve(n, k >> 1) % mod;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cout << solve(n, q) << endl;
  }
  return 0;
}
