#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long fact(long long n) {
  long long ans = 1ll;
  for (long long i = 2; i <= n; i++) {
    ans = ((ans % mod) * (i % mod)) % mod;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = (2 * n) - 1; i >= n; i--) {
      ans = (ans * (i % mod)) % mod;
    }
    cout << (ans * (fact(n) % mod)) % mod << endl;
  }
  return 0;
}
