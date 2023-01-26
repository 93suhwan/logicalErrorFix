#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const double EPSILON = 10e-8;
bool equal(double a, double b) { return fabs(a - b) < EPSILON; }
bool less(double a, double b) { return a < b && !equal(a, b); }
long long fast_power(long long base, long long power, long long MOD) {
  if (power == 0) return 1;
  if (power == 1) return base % MOD;
  long long result = fast_power(base, power / 2, MOD) % MOD;
  if (power % 2 == 0) return ((result % MOD) * (result % MOD)) % MOD;
  long long a = ((result % MOD) * (base % MOD)) % MOD;
  a = ((a % MOD) * (result % MOD)) % MOD;
  return a % MOD;
}
long long fact[1000000];
void factorial() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < 1000000; i++) {
    fact[i] = ((i % 998244353) * (fact[i - 1] % 998244353)) % 998244353;
  }
}
int main() {
  init_code();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long b[n];
    if (n % 2 == 0) {
      for (long long i = 0; i < n - 1; i += 2) {
        b[i] = -(arr[i + 1]);
        b[i + 1] = arr[i];
      }
      for (long long i = 0; i < n; i++) {
        cout << b[i] << " ";
      }
      cout << endl;
    } else {
      for (long long i = 0; i < n - 3; i += 2) {
        b[i] = -(arr[i + 1]);
        b[i + 1] = arr[i];
      }
      b[n - 3] = b[n - 2] = -(arr[n - 1]);
      b[n - 1] = arr[n - 3] + arr[n - 2];
      for (long long i = 0; i < n; i++) {
        cout << b[i] << " ";
      }
      cout << endl;
    }
  }
}
