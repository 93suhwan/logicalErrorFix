#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX_SIZE = 1e6 + 5;
const long long int MAXN = 3e6 + 5;
const long long int INF = 2e18;
long long int fact[MAXN];
long long int modin[MAXN];
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : (n * factorial(n - 1)) % mod;
}
long long int power(long long int a, long long int p) {
  if (p == 0) {
    return 1;
  } else if (p % 2 == 0) {
    long long int t = power(a, p / 2);
    return (t * t) % mod;
  } else {
    return (a * power(a, p - 1)) % mod;
  }
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void fill() {
  fact[0] = 1;
  for (long long int i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  modin[MAXN - 1] = power(fact[MAXN - 1], mod - 2);
  for (long long int i = MAXN - 2; i >= 0; i--) {
    modin[i] = (modin[i + 1] * (i + 1)) % mod;
  }
}
long long int nCr(long long int n, long long int r) {
  return (((fact[n] * modin[n - r]) % mod) * modin[r]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, q;
  cin >> n >> q;
  fill();
  vector<long long int> num(3 * n + 4);
  vector<long long int> ans(3 * n + 1);
  for (long long int i = 0; i < 3 * n; i++) {
    num[i] = nCr(3 * n + 3, i);
  }
  num[3 * n] = (nCr(3 * n + 3, 3 * n) - 1 + mod) % mod;
  num[3 * n + 1] = (nCr(3 * n + 3, 3 * n + 1) - 3 + mod) % mod;
  num[3 * n + 2] = (nCr(3 * n + 3, 3 * n + 2) - 3 + mod) % mod;
  num[3 * n + 3] = 0;
  long long int i = 0;
  while (true) {
    if (num[i] == 0) {
      break;
    }
    long long int t = num[i];
    num[i] = 0;
    ans[3 * n - i] = t;
    num[i + 1] = ((num[i + 1] - 3 * t) % mod + mod) % mod;
    num[i + 2] = ((num[i + 2] - 3 * t) % mod + mod) % mod;
    i++;
  }
  for (long long int j = 0; j < q; j++) {
    long long int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
  return 0;
}
