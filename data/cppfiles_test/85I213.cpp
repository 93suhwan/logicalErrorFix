#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
const long long mod = 1000000007;
int rnd(int x) { return mrand() % x; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() { return 0; }
