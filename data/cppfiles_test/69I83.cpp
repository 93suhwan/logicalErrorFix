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
      x = (x * y) % 1000000007;
    }
    y = (y * y) % 1000000007;
    b /= 2;
  }
  return x % 1000000007;
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
  vector<string> v(101);
  for (i = 0; i <= 100; i++) v[i] = to_string(power(2, i));
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long ans = INT_MAX;
    for (i = 0; i <= 100; i++) {
      long long a = str.size(), b = v[i].size();
      j = 0, k = 0;
      long long match = 0;
      while (j < a && k < b) {
        if (str[j] == v[i][k])
          j++, k++, match++;
        else {
          j++;
        }
      }
      ans = min(ans, a - match + b - match);
    }
    cout << ans << endl;
  }
  return 0;
}
