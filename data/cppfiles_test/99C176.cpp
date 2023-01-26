#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
long long Mod = 1e9 + 7;
bool isPrime(long long n);
long long power(long long x, long long y);
long long powermod(long long x, long long y, long long Mod);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long nCr(long long n, long long r);
long long minv(long long a) { return power(a, M - 2); }
long long mod(long long n) { return (n % M + M) % M; }
long long modM(long long n, long long m) { return ((n % M * m % M) + M) % M; }
long long modA(long long n, long long m) { return ((n % M + m % M) + M) % M; }
long long modS(long long n, long long m) { return ((n % M - m % M) + M) % M; }
long long modD(long long n, long long m) {
  return ((n % M * minv(m) % M) + M) % M;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << endl;
    return;
  }
  if (abs(x) % 2 == 0) {
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << x + 0 << endl;
      } else {
        cout << x + 1 << endl;
      }
    } else {
      n--;
      if (n % 4 == 0) {
        cout << x - (n + 1) << endl;
      } else {
        cout << x + 1 + (n + 1) << endl;
      }
    }
  } else {
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << x << endl;
      } else {
        cout << x - 1 << endl;
      }
    } else {
      long long ans;
      n--;
      if (n % 4 == 0) {
        ans = x;
        n++;
        cout << ans + n << endl;
      } else {
        ans = x - 1;
        n++;
        cout << ans - n << endl;
      }
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcase = 1;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
}
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return ((power(x, y / 2)) * (power(x, y / 2)));
  else
    return ((((x) * ((power(x, y / 2)))) * (power(x, y / 2))));
}
long long powermod(long long x, long long y, long long Mod) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return ((power(x, y / 2) % Mod) * (power(x, y / 2) % Mod)) % Mod;
  else
    return ((((x % Mod) * ((power(x, y / 2) % Mod))) % Mod *
             (power(x, y / 2) % Mod)) %
            Mod) %
           Mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long nCr(long long n, long long r) {
  long long p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else {
    p = 1;
  }
  return p;
}
