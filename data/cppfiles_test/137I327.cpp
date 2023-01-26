#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long power1(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (power1((a * a), b / 2));
  else
    return (power1((a * a), b / 2) * a);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (power((a * a) % mod, b / 2)) % mod;
  else
    return (power((a * a) % mod, b / 2) * a) % mod;
}
long long fact(long long n) {
  if (n == 0) return 1;
  if (n == 1) return 1;
  return (fact(n - 1) * n) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<bool> prime(1e7, true);
void sieve(long long n) {
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
}
void swap(long long &a, long long &b) {
  long long t = b;
  b = a;
  a = t;
}
string binaryf(long long n) {
  while (n % 2 == 0) n /= 2;
  string b;
  while (n) {
    if (n % 2)
      b += '1';
    else
      b += '0';
    n /= 2;
  }
  return b;
}
string binary(long long n) {
  string b;
  while (n) {
    if (n % 2)
      b += '1';
    else
      b += '0';
    n /= 2;
  }
  reverse(b.begin(), b.end());
  return b;
}
bool check(string &bx, string &by) {
  if (bx.size() > by.size()) return false;
  bool ans1;
  for (long long i = 0; i < by.size() - bx.size() + 1; i++) {
    if (bx[0] == by[i]) {
      ans1 = true;
      for (long long j = 0; j < bx.size(); j++) {
        if (bx[j] != by[i + j]) {
          ans1 = false;
          break;
        }
      }
      if (ans1) break;
    }
  }
  if (ans1) return ans1;
  bool ans2;
  for (long long i = by.size() - 1; i >= bx.size() - 1; i--) {
    if (bx[0] == by[i]) {
      ans2 = true;
      for (long long j = 0; j < bx.size(); j++) {
        if (bx[j] != by[i - j]) {
          ans2 = false;
          break;
        }
      }
      if (ans2) break;
    }
  }
  return ans2;
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (x % 2) {
    string bx = binaryf(x);
    string by = binaryf(y);
    if (check(bx, by))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  } else {
    if (x == y) {
      cout << "YES"
           << "\n";
      return 0;
    }
    string bx = binary(x) + '1';
    string by = binary(y);
    if (check(bx, by)) {
      cout << "YES"
           << "\n";
      return 0;
    }
    cout << "NO"
         << "\n";
  }
  return 0;
}
