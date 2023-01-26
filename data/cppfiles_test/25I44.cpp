#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long int N = 1e6 + 15000;
double PI = 3.141592653589793;
vector<long long int> primefactors(long long int num) {
  vector<long long int> res;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      res.push_back(i);
    }
    while (num % i == 0) {
      num /= i;
    }
  }
  if (num > 1) {
    res.push_back(num);
  }
  return res;
}
long long int highestPowerof2(long long int n) {
  long long int p = (long long int)log2(n);
  return (long long int)pow(2, p);
}
bool isPrime(long long int n) {
  if (n == 1) {
    return false;
  }
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long int factorial(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % MOD;
  }
  return res;
}
long long int binPow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * a) % MOD;
    a = (1LL * a * a) % MOD;
    n >>= 1;
  }
  return res;
}
long long int C(long long int n, long long int k) {
  return factorial(n) * 1ll * binPow(factorial(k), MOD - 2) % MOD * 1ll *
         binPow(factorial(n - k), MOD - 2) % MOD;
}
long long int n, m, x, y, k;
string s;
bool fun(string a, string b, long long int i1, long long int i2,
         long long int n, long long int m) {
  if (i1 >= n || i2 >= m || i1 < 0 || i2 < 0) return false;
  if (i2 == m - 1) {
    if (a[i1] == b[i2]) return true;
    return false;
  }
  if (a[i1] != b[i2]) return false;
  if (a[i1] == b[i2]) {
    return fun(a, b, i1 + 1, i2 + 1, n, m) || fun(a, b, i1 - 1, i2 + 1, n, m);
  }
}
void solve() {
  string a, b;
  cin >> a >> b;
  long long int n = a.length(), m = b.length();
  for (long long int i = 0; i < n; i++) {
    if (a[i] == b[0] && a[i + 1] == b[1] && i < n - 1) {
      if (fun(a, b, i, 0, n, m)) {
        cout << "YES\n";
        return;
      }
    }
    if (a[i] == b[0] && m == 1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
