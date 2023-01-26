#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return ans;
}
int main() {
  long long n;
  cin >> n;
  long long ans = 6;
  long long cnt = (1ll << n) - 2;
  long long t = power(4ll, cnt);
  ans = ans * t % mod;
  cout << ans << endl;
  return 0;
}
