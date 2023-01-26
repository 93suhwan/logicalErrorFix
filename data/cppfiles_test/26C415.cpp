#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum;
  string sans, s;
  t = 1;
  cin >> t;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> s;
    ans = 10LL;
    for (i = 0; i < 10; i += 2) {
      long long max1, min1;
      max1 = min1 = 0;
      for (j = i; j >= 0; j -= 2) {
        if (s[j] == '1') {
          max1++;
          min1++;
        }
        if (s[j] == '?') max1++;
      }
      long long max2, min2;
      max2 = min2 = 0;
      for (j = i - 1; j >= 0; j -= 2) {
        if (s[j] == '1') {
          max2++;
          min2++;
        }
        if (s[j] == '?') max2++;
      }
      long long rem1, rem2;
      rem1 = 4 - i / 2;
      rem2 = rem1 + 1;
      if (max1 > min2 + rem2) {
        ans = min(ans, i + 1);
        break;
      }
      if (max2 > min1 + rem1) {
        ans = min(ans, i + 1);
        break;
      }
    }
    for (i = 1; i < 10; i += 2) {
      long long max1, min1;
      max1 = min1 = 0;
      for (j = i; j >= 0; j -= 2) {
        if (s[j] == '1') {
          max1++;
          min1++;
        }
        if (s[j] == '?') max1++;
      }
      long long max2, min2;
      max2 = min2 = 0;
      for (j = i - 1; j >= 0; j -= 2) {
        if (s[j] == '1') {
          max2++;
          min2++;
        }
        if (s[j] == '?') max2++;
      }
      long long rem1, rem2;
      rem1 = 4 - i / 2;
      rem2 = rem1;
      if (max1 > min2 + rem2) {
        ans = min(ans, i + 1);
        break;
      }
      if (max2 > min1 + rem1) {
        ans = min(ans, i + 1);
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
