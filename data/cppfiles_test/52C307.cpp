#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int fp(long long int b, long long int p) {
  if (p == 0) return 1;
  if (p & 1) return (b * fp(b, p - 1)) % mod;
  return fp((b * b) % mod, p / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    for (int i = 0; i < 30; i++) {
      if (((k) & (1 << i)) != 0) {
        ans = add(ans, fp(n, i));
      }
    }
    cout << ans << '\n';
  }
}
