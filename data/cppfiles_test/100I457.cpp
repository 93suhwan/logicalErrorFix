#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod1 = 998244353;
const long long mod = 1e9 + 7;
const long long MOD = 1e18 + 1e16;
long long mod_mul(long long a, long long b) {
  a = a % mod1;
  b = b % mod1;
  return (((a * b) % mod1) + mod1) % mod1;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod1;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod1;
    a = a * a % mod1;
    b >>= 1;
  }
  return res;
}
long long findMinNumber(long long n) {
  long long count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> fact(300005, 1);
long long C(long long n, long long r) {
  long long ans = 1;
  ans = fact[n];
  ans = mod_mul(ans, pwr(fact[r], mod1 - 2));
  ans = mod_mul(ans, pwr(fact[n - r], mod1 - 2));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i;
  cin >> t;
  for (i = 2; i < 300005; i++) {
    fact[i] = mod_mul(fact[i - 1], i);
  }
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    for (i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] > 1) {
        res = 1;
        break;
      }
    }
    if (res) {
      cout << 0 << '\n';
    } else {
      long long ans = fact[n];
      long long cnt = 0;
      for (i = 0; i < n; i++)
        if (a[n - 1] - a[i] <= 1)
          break;
        else
          cnt++;
      if (a[0] == a[n - 1])
        cout << ans % mod1 << '\n';
      else {
        long long ans1 = 0;
        for (i = 0; i < cnt + 1; i++) {
          ans1 += ((fact[n - 1 - i] * C(cnt, i)) % mod1 * fact[i]) % mod1;
          ans1 %= mod1;
        }
        cout << ((ans - ans1) % mod1 + mod1) % mod1 << '\n';
      }
    }
  }
  return 0;
}
