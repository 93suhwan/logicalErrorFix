#include <bits/stdc++.h>
long long int n, m, x, a, b, c, d, cnt, fg;
using namespace std;
long long int gcd(long long int A, long long int B) {
  if (B == 0)
    return A;
  else
    return gcd(B, A % B);
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int b, long long int MOD) {
  long long int ans = 1;
  while (b != 0) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b = b / 2;
  }
  return ans;
}
long long int countDigit(long long n) {
  long long int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}
int removeZero(long long int n) {
  long long int q = 0, r;
  while (n > 0) {
    r = n % 10;
    n = n / 10;
    if (r != 0) {
      q = q * 10 + r;
    }
  }
  n = q;
  q = 0;
  while (n > 0) {
    r = n % 10;
    n = n / 10;
    q = q * 10 + r;
  }
  return q;
}
int main() {
  long long int TC;
  cin >> TC;
  while (TC--) {
    long long int n, k, r = 0, d = 0;
    cin >> n >> k;
    int v[n];
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v, v + n);
    for (long long int i = 0; i < k; i++) {
      r += v[n - 2 * k + i] / v[n - k + i];
    }
    for (long long int i = 0; i < n - 2 * k; i++) {
      r += v[i];
    }
    cout << r << endl;
  }
}
