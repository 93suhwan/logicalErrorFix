#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
inline bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}
int drx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dcy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long InverseMod(long long base, long long pow) {
  if (pow == 0) return 1;
  long long ans = InverseMod(base, pow / 2);
  ans = (ans * ans) % 1000000007;
  if (pow & 1) {
    return (ans * base) % 1000000007;
  } else {
    return ans;
  }
}
bool isprime(long long num) {
  if (num < 2) return false;
  for (long long i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}
long long EularPHI(long long num) {
  double ans = num;
  for (long long i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      while (num % i == 0) {
        num /= i;
      }
      ans *= (1.0 - (1.0 / (double)i));
    }
  }
  if (num > 1) ans *= (1.0 - (1.0 / (double)num));
  return (long long)ans;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd<T>(a, b);
}
template <class T>
inline T power(T b, T p) {
  long long ans = 1;
  while (p--) ans *= b;
  return ans;
}
int binomialCoeff(int n, int r) {
  if (r > n) return 0;
  int m = 1000000007;
  int inv[r + 1];
  memset(inv, 0, sizeof(inv));
  inv[0] = 1;
  if (r + 1 >= 2) inv[1] = 1;
  for (int i = 2; i <= r; i++) {
    inv[i] = m - (m / i) * inv[m % i] % m;
  }
  int ans = 1;
  for (int i = 2; i <= r; i++) {
    ans = ((ans % m) * (inv[i] % m)) % m;
  }
  for (int i = n; i >= (n - r + 1); i--) {
    ans = ((ans % m) * (i % m)) % m;
  }
  return ans;
}
long long extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool find_any_solution(long long a, long long b, long long c, long long &x0,
                       long long &y0, long long &g) {
  g = extgcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long divide(long long a, long long b) {
  return (a % 1000000007) * powm(b, 1000000007 - 2) % 1000000007;
}
long long mul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long add(long long a, long long b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
bool vectorSortedOrNot(vector<int> v, int n) {
  if (n == 1 || n == 0) return 1;
  if (v[n - 1] < v[n - 2]) return 0;
  return vectorSortedOrNot(v, n - 1);
}
int sumDigits(int num) { return num == 0 ? 0 : num % 10 + sumDigits(num / 10); }
void Divisors(long long n) {
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
    }
  }
}
long long solve(long long mid, long long k) {
  long long sum = 0;
  long long z = 1;
  while (mid / z > 0) {
    sum += mid / z;
    z *= k;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, k;
    cin >> n >> k;
    if (n - 1) {
      long long ans(0);
      long long updatedon(1);
      while (updatedon <= k) {
        updatedon *= 2;
        ans++;
      }
      n -= updatedon;
      if (n > 0) {
        ans += n / k;
        if (n % k) ans++;
      }
      cout << ans;
      cout << '\n';
    } else {
      cout << 0 << "\n";
    }
  }
  return 0;
}
