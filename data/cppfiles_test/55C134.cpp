#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  a = a % m;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long mod_Inverse(long long a, long long m) { return power(a, m - 2, m); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  long long ans = 6;
  ans = (ans * power(4, binpow(2, k) - 2, 1000000007)) % 1000000007;
  cout << ans << '\n';
}
