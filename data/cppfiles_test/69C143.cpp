#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long factorial(long long n) {
  if (n == 0) return 1;
  return (n % 1000000007 * factorial(n - 1) % 1000000007) % 1000000007;
}
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) {
      x = x * y;
    }
    y = y * y;
    b /= 2;
  }
  return x;
}
long long modular_inverse(long long n) { return power(n, 1000000007 - 2); }
long long ncr(long long n, long long k) {
  long long b =
      (factorial(k) % 1000000007 * factorial(n - k) % 1000000007) % 1000000007;
  return (factorial(n) % 1000000007 * modular_inverse(b) % 1000000007);
}
long long is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, k, x;
  vector<string> v(61);
  for (i = 0; i <= 60; i++) {
    k = power(2, i);
    v[i] = to_string(k);
  }
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = INT_MAX;
    for (i = 0; i <= 60; i++) {
      long long a = v[i].size();
      long long b = s.size();
      long long a1, b1;
      for (j = a; j > 0; j--) {
        a1 = 0, b1 = 0;
        while (a1 < a && b1 < b) {
          if (v[i][a1] == s[b1])
            a1++, b1++;
          else
            b1++;
        }
        if (a1 == a) break;
      }
      ans = min(ans, a + b - 2 * a1);
    }
    cout << ans << endl;
  }
  return 0;
}
