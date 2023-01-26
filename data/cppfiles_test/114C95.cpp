#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e9 + 5);
const long long MAXL = long long(1e18 + 5);
const long long MOD = long long(1e9 + 7);
const long long MOD2 = long long(998244353);
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return;
}
void precision(int x) {
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(x);
  return;
}
long long gcd(long long a, long long b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0) {
    return b;
  }
  if (a == b) {
    return a;
  }
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool is_prime(long long a) {
  if (a == 1) {
    return false;
  }
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
bool is_square(long long a) {
  long long b = long long(sqrt(a));
  return (b * b == a);
}
bool is_cube(long long a) {
  long long b = long long(cbrt(a));
  return (b * b * b == a);
}
int digit_sum(long long a) {
  int sum = 0;
  while (a) {
    sum += int(a % 10);
    a /= 10;
  }
  return sum;
}
long long binpow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if ((b & 1) == 1) {
      ans *= a;
    }
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long binpow_by_mod(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if ((b & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    b >>= 1;
    a *= a;
    a %= mod;
  }
  return ans;
}
long long factorial(int a) {
  int i;
  long long ans = 1;
  for (i = 2; i <= a; i++) {
    ans *= long long(i);
  }
  return ans;
}
long long factorial_by_mod(int a, long long mod) {
  int i;
  long long ans = 1;
  for (i = 2; i <= a; i++) {
    ans *= long long(i);
    ans %= mod;
  }
  return ans;
}
const int N = 200005;
int a[N];
int n;
void solve() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (i = 2; i <= (n / 2) + 1; i++) {
    cout << a[i] << ' ' << a[1] << endl;
  }
  return;
}
void precalc() { return; }
int main() {
  fastio();
  precalc();
  int tests = 1, tc;
  cin >> tests;
  for (tc = 1; tc <= tests; tc++) {
    solve();
  }
  return 0;
}
