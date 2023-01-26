#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int dp[10000];
long long int fact(long long int n) {
  if (n == 0) {
    return 1;
  }
  if (dp[n] != 0) {
    return dp[n];
  }
  dp[n] = n * fact(n - 1);
  return dp[n];
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n) {
    if (n & 1) result = result * x % 1000000007;
    n = n / 2;
    x = x * x % 1000000007;
  }
  return result;
}
map<int, int> m;
void primeFactors(long long int n) {
  while (n % 2 == 0) {
    m[2]++;
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      m[i]++;
      n = n / i;
    }
  }
  if (n > 2) m[n]++;
}
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) cout << p;
}
int stringTointeger(string str) {
  int temp = 0;
  for (int i = 0; i < str.length(); i++) {
    temp = temp * 10 + (str[i] - '0');
  }
  return temp;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    long long int count0 = 0;
    long long int count1 = 0;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 0) {
        count0++;
      } else if (v[i] == 1) {
        count1++;
      }
    }
    ans += (power(2, count0) % 1000000007 * count1 % 1000000007) % 1000000007;
    cout << ans << endl;
  }
  return 0;
}
