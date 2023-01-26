#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long MAX = 1e5;
const long long mod = 1000000007;
long long pow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, ans = 0;
    cin >> n;
    cout << (n + 1) / 10 << endl;
  }
}
