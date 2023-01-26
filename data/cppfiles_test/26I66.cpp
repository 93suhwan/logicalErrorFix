#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long MOD = 1e9 + 7;
long long solve(long long n) {
  if (n <= 1) return 1;
  long long ff = 1;
  for (int i = 3; i <= 2 * ff; i++) ff = (ff * i) % MOD;
  return ff;
}
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
