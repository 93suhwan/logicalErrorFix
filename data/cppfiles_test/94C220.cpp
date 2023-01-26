#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long mod = 1000000000 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int max(long long int x, long long int y) {
  return x ^ ((x ^ y) & -(x < y));
}
long long int min(long long int x, long long int y) {
  return y ^ ((x ^ y) & -(x < y));
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    ans = ans % mod;
    a = a % mod;
    if (b & 1) ans = ans * a;
    b = b >> 1;
    a = a * a;
  }
  return ans;
}
void fastscan(long long int &number) {
  bool negative = false;
  register long long int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a = 0, b = 0, a1 = 0, b1 = 0;
    long long int k = 0;
    while (n != 0) {
      if (k % 2 == 0) {
        a += (n % 10) * pow(10, a1);
        a1++;
      } else {
        b += (n % 10) * pow(10, b1);
        b1++;
      }
      n = n / 10;
      k++;
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
  }
  return 0;
}
