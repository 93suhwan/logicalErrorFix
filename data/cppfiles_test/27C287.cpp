#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ispalindrome(string ss) {
  long long int n = ss.size();
  for (long long int i = 0; i < (n + 1) / 2; i++) {
    if (ss[i] != ss[n - i - 1]) return 0;
  }
  return 1;
}
long long int mod = 1e9 + 7;
long long int ksm(long long int a, long long int b) {
  long long int S = 1;
  while (b) {
    if (b & 1) S = S * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return S;
}
long long int digit(long long int n) {
  long long int res = 0;
  while (n) {
    res++;
    n = n / 10;
  }
  return res;
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i < n + 1; i++) ans = ((ans * i) % mod);
  return ans % mod;
}
long long int isprime(long long int n) {
  if (n == 2 || n == 3) return 1;
  for (long long int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp) % mod;
  else
    return (x * (temp * temp) % mod) % mod;
}
void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  if (m > n) {
    cout << "NO" << endl;
    return;
  }
  int p = (n - m) & 1;
  int q = 0, k = 0;
  for (int i = p; i < n; i++) {
    if (k == 1) {
      k = 0;
      continue;
    }
    if (q < m && a[i] == b[q]) {
      q++;
    } else {
      k++;
    }
  }
  if (q == m) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
