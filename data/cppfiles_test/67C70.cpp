#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
inline long long max(long long a, long long b) { return ((a > b) ? a : b); }
inline long long min(long long a, long long b) { return ((a > b) ? b : a); }
long long power(long long x, long long ex);
long long powermod(long long x, long long ex, long long md);
const long long inf = 4e18 + 9;
const long long mod = 1e9 + 7;
const long double PI = acos(-1);
const long double eps = 1e-9;
void solve() {
  long long n;
  long double p;
  cin >> n >> p;
  for (long long i = (0); i <= (n); i++) {
    long long y = i, x = n - i;
    long double x1 = (1.0 * x * (x - 1) * y) / 4.0;
    long double x2 = (1.0 * x * y * (y - 1)) / 2.0;
    long double x3 = (1.0 * y * (y - 1) * (y - 2)) / 6.0;
    long double nn = (1.0 * n * (n - 1) * (n - 2)) / 6.0;
    if (x1 + x2 + x3 >= p * nn) {
      cout << y << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
  long long NTC = 1;
  long long PTC = 0;
  while ((PTC++) < NTC) {
    if (false) cerr << "Testcase # " << PTC << "\n";
    solve();
    if (false) cerr << "*************************\n";
  }
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long a = power(x, y / 2);
  if (y % 2 == 0)
    return a * a;
  else
    return x * a * a;
}
long long powermod(long long x, long long ex, long long md) {
  long long ans = 1ll;
  while (ex > 0) {
    if (ex & 1ll) ans = (ans * x) % md;
    ex >>= 1ll;
    x = (x * x) % md;
  }
  return ans;
}
