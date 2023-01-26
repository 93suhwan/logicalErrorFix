#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long inv(long long i, long long m) {
  if (i == 1) return 1;
  return (m - ((m / i) * inv(m % i, m)) % m) % m;
}
long long mod(long long x, long long m) { return ((x % m + m) % m); }
long long mod_add(long long a, long long b, long long m) {
  return mod((mod(a, m) + mod(b, m)), m);
}
long long mod_sub(long long a, long long b, long long m) {
  return mod((mod(a, m) - mod(b, m)), m);
}
long long mod_mul(long long a, long long b, long long m) {
  return mod((mod(a, m) * mod(b, m)), m);
}
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = mod_mul(res, a, m);
    }
    a = mod_mul(a, a, m);
    b = b >> 1;
  }
  return res;
}
void swap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
long long pwr(long long a, long long b, long long mod) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
bool pow_of_2(long long n) {
  if (n != 0 && (n & n - 1) == 0) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long sum = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      if (i + 1 < n && arr[i + 1] == 1)
        sum += 5;
      else
        sum++;
    } else if (arr[i] == 0) {
      if (i + 1 < n && arr[i + 1] == 0) {
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << sum << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
