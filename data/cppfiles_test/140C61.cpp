#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 5e5 + 7;
void hash0111() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int prevPowerOfTwo(long long int n) {
  if (n && (!n & (n - 1))) return n;
  return 1 << ((long long int)ceil(log2(n) - 1));
}
long long int nextPowerOfTwo(long long int n) {
  if (n && (!n & (n - 1))) return n;
  return 1 << ((long long int)ceil(log2(n)));
}
void solve() {
  long long int n;
  cin >> n;
  long long int res = 0;
  res += (long long int)sqrt(n);
  long long int x = (long long int)cbrt(n);
  res += x;
  res -= (long long int)sqrt(x);
  cout << res << '\n';
}
int main() {
  hash0111();
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
