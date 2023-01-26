#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long add(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a + b) % 1000000007) + 1000000007) % 1000000007;
}
long long sub(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a - b) % 1000000007) + 1000000007) % 1000000007;
}
long long mul(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a * b) % 1000000007) + 1000000007) % 1000000007;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % 1000000007;
    }
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  bool solved = false;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      solved = true;
      if (i >= n / 2) {
        write(1, i + 1, 1, i);
      } else {
        write(i + 1, n, i + 2, n);
      }
      return;
    }
  }
  write(1, n - 1, 2, n);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long iter;
  cin >> iter;
  while (iter) {
    solve();
    iter--;
  }
}
