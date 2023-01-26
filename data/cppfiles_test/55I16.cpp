#include <bits/stdc++.h>
using namespace std;
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long g = pow(2, n) - 1;
  long long ans = 6;
  long long M = 1e9 + 7;
  long long a = modpow(4, g - 1, M);
  a *= ans;
  a %= M;
  cout << a << "\n";
}
