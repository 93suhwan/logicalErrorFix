#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const int MOD = 1e9 + 7;
using namespace std;
int countSetBits(int n) {
  if (n == 0)
    return 0;
  else
    return (n & 1) + countSetBits(n >> 1);
}
long long factorial(long long n) {
  if (n == 0) return 1;
  return (n * factorial(n - 1));
}
bool is_palindrom_number(long long n) {
  long long num, digit, rev = 0;
  num = n;
  while (num != 0) {
    digit = num % 10;
    rev = (rev * 10) + digit;
    num /= 10;
  }
  return (num == n ? true : false);
}
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPalindrome(string str) {
  int l = 0;
  int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
int removeZeros(int num) {
  int ret = 0;
  int ten = 1;
  while (num) {
    int dig = num % 10;
    num /= 10;
    if (dig) {
      ret += dig * ten;
      ten *= 10;
    }
  }
  return ret;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int rah = 0;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long f = 1;
  long long man = 0;
  if (man) {
    int best = 1;
    int n = 2;
    while (n != 1) {
      if (n % 2 == 0) {
        best += 1;
        n = n / 2;
      } else {
        best += 1;
        n = n - 1;
      }
    }
  }
  long long nitin = 0;
  while (f <= k && f < n) {
    f *= 2;
    nitin++;
  }
  if (man) {
    int best = 1;
    int n = 2;
    while (n != 1) {
      if (n % 2 == 0) {
        best += 1;
        n = n / 2;
      } else {
        best += 1;
        n = n - 1;
      }
    }
  }
  if (f < n) nitin += (n - f + k - 1) / k;
  cout << nitin << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
