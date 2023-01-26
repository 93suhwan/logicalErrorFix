#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long int fermat_inv(long long int y) { return power(y, MOD - 2); }
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long int min(long long int a, long long int b) { return (a > b) ? b : a; }
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
bool prime[1000001];
vector<int> primes;
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = 0;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p < 1000001; p++)
    if (prime[p]) primes.push_back(p);
}
long long int fact[1000010];
long long int finv[1000010];
void factorial(int n) {
  fact[0] = 1;
  finv[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = fact[i - 1] * i, fact[i] %= MOD, finv[i] = fermat_inv(fact[i]);
}
long long int ncr(long long int n, long long int r) {
  if (n < r)
    return 0;
  else {
    long long int x = finv[r] * finv[n - r] % MOD;
    return fact[n] * x % MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int te = 1;
  cin >> te;
  while (te--) {
    string s;
    cin >> s;
    int n = s.size();
    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        if (s[i] == 'a')
          x++;
        else
          y++;
      }
    }
    if (x > y) {
      int a = 0, b = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'b') break;
        a++;
      }
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') break;
        b++;
      }
      if (a <= b) {
        for (int i = 0; i < n; i++) {
          if (s[i] == 'b') break;
          s[i] = 'b';
        }
      } else {
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'a') break;
          s[i] == 'a';
        }
      }
    } else if (y > x) {
      int a = 0, b = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'a') break;
        a++;
      }
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b') break;
        b++;
      }
      if (a <= b) {
        for (int i = 0; i < n; i++) {
          if (s[i] == 'a') break;
          s[i] = 'a';
        }
      } else {
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == 'b') break;
          s[i] == 'b';
        }
      }
    }
    cout << s << '\n';
  }
}
