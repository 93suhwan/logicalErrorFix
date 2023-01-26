#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
long long cl(long long n, long long d) { return (n + d - 1) / d; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
long long exp(long long x, long long y, long long p) {
  x %= p;
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % (long long)1000000007) % (long long)1000000007;
    x = (x * x) % (long long)1000000007;
    y /= 2;
  }
  return res;
}
long long add(long long a, long long b) {
  return (a % (long long)1000000007 + b % (long long)1000000007 +
          (long long)1000000007) %
         (long long)1000000007;
}
long long sub(long long a, long long b) {
  return (a % (long long)1000000007 - b % (long long)1000000007 +
          (long long)1000000007) %
         (long long)1000000007;
}
long long mul(long long a, long long b) {
  return ((a % (long long)1000000007) * (b % (long long)1000000007) +
          (long long)1000000007) %
         (long long)1000000007;
}
long long inv(long long x) { return expo(x, (long long)1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n, sum = 0;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    sort(v.begin(), v.end());
    long long m;
    cin >> m;
    while (m--) {
      long long sum2 = sum;
      long long x, y, ans = 0, ans2;
      cin >> x >> y;
      auto it1 = lower_bound(v.begin(), v.end(), x);
      long long t1 = (it1 - v.begin());
      if (t1 == n) {
        ans += abs(x - v[n - 1]);
        sum2 -= v[n - 1];
        if (sum2 < y) {
          ans += (y - sum2);
        }
        cout << ans << "\n";
      } else if (t1 == 0) {
        sum2 -= v[0];
        if (sum2 < y) {
          ans += (y - sum2);
        }
        cout << ans << "\n";
      } else {
        long long sum3 = sum2;
        sum3 -= v[t1];
        if (sum3 < y) {
          ans += (y - sum3);
        }
        sum2 -= v[t1 - 1];
        ans2 = 0;
        ans2 += (x - v[t1 - 1]);
        if (sum2 < y) {
          ans2 += (y - sum2);
        }
        cout << min(ans, ans2) << "\n";
      }
    }
  }
}
