#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
double pi = 3.141592653589793238;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long binpow(long long A, long long b, long long m) {
  A %= m;
  long long Result = 1;
  while (b > 0) {
    if (b & 1) Result = Result * A % m;
    A = A * A % m;
    b >>= 1;
  }
  return Result;
}
long long gcd(long long A, long long b) {
  if (b == 0) return A;
  return gcd(b, A % b);
}
int32_t main() {
  fast_io();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << "a" << endl;
      continue;
    }
    if (n & 1) {
      string tempi = "bc";
      n = n - 2;
      long long temp = (n - 1) / 2;
      string a = "", b = "";
      for (long long i = 0; i < temp; i++) a += 'a';
      for (long long i = 0; i < temp + 1; i++) b += 'a';
      string ans = a + tempi + b;
      cout << ans << endl;
    } else {
      string tempi = "b";
      n = n - 1;
      long long temp = (n - 1) / 2;
      string a = "", b = "";
      for (long long i = 0; i < temp; i++) a += 'a';
      for (long long i = 0; i < temp + 1; i++) b += 'a';
      string ans = a + tempi + b;
      cout << ans << endl;
    }
  }
  return 0;
}
