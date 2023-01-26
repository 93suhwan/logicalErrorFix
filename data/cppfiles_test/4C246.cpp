#include <bits/stdc++.h>
using namespace std;
inline long long factorCeil(long long a, long long b);
inline long long logPower(long long x, long long y);
inline long long binaryToDecimal(string num);
inline void Sieve(long long n);
string solve() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 5) {
      cout << 2 << " " << 4 << "\n";
    } else {
      cout << 2 << " " << n / 2 << "\n";
    }
  }
  return 0;
}
inline void Sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
inline long long binaryToDecimal(string num) {
  long long dec_value = 0;
  long long base = 1;
  long long len = num.length();
  for (long long i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
inline long long factorCeil(long long a, long long b) {
  return (a + b - 1) / b;
}
inline long long logPower(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
