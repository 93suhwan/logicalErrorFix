#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long, long long, long long);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h;
  cin >> h;
  long long x = (1LL << h) - 2;
  long long p = power(4, x, mod);
  p = p * 6;
  p = p % mod;
  cout << p << endl;
}
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
