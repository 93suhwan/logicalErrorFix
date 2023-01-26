#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long giaithua(long long n) {
  long long ans = 1;
  for (long long i = 3; i <= n; i++) {
    ans = (ans * i) % MOD;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  n *= 2;
  cout << (giaithua(n));
  return 0;
}
