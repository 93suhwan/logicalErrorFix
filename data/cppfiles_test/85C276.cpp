#include <bits/stdc++.h>
using namespace std;
bool prime[10000007];
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= 10000007; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= 10000007; i += p) prime[i] = false;
    }
  }
}
const long long int N = 300500;
long long int fact[N];
long long int invFact[N];
long long int fast_pow(long long int a, long long int p, long long int m) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = (a * a) % m;
      p /= 2;
    } else {
      res = (res * a) % m;
      p--;
    }
  }
  return res;
}
void Call_For_nCr() {
  fact[0] = invFact[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    invFact[i] = fast_pow(fact[i], 1000000007 - 2, 1000000007);
  }
}
long long int nCR(long long int n, long long int k, long long int m) {
  if (k > n) {
    return 0;
  }
  return fact[n] * invFact[k] % m * invFact[n - k] % m;
}
long long int sumOfDigit(long long int n, long long int b) {
  long long int unitDigit, sum = 0;
  while (n > 0) {
    unitDigit = n % b;
    sum += unitDigit;
    n = n / b;
  }
  return sum;
}
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
bool compare(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first < b.first) return 1;
  if (b.first < a.first) return 0;
  if (a.second > b.second) return 1;
  return 0;
}
void solve() {
  string s;
  cin >> s;
  long long int ans = 0, one = 0, ok = 0, zero = 0;
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zero = 1;
      ok = 1;
      if (one && zero) ans = 1;
    }
    if (s[i] == '1') {
      if (zero) one = 1;
    }
  }
  if (!ok) {
    cout << 0 << "\n";
    return;
  }
  if (ans)
    cout << 2 << "\n";
  else
    cout << 1 << "\n";
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
signed main() {
  init_code();
  long long int t = 1;
  cin >> t;
  long long int i = 1;
  while (t--) {
    solve();
    i++;
  }
  return 0;
}
