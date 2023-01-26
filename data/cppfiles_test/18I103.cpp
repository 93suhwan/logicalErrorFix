#include <bits/stdc++.h>
using namespace std;
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
void calc(vector<long long> &a, long long index, long long &one) {
  long long n = (long long)((a).size());
  vector<long long> b(n);
  for (long long i = 0; i < (n); i++) {
    b[i] = a[index++];
    if (index == n) index = 0;
  }
  one = 0ll;
  for (long long i = 0; i < (n); i++) {
    a[i] = (a[i] & b[i]);
    if (a[i] == 1) one++;
  }
}
void solve() {
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  long long ans = 0ll;
  long long one = 0ll;
  for (long long i = 0; i < (n); i++) one += a[i];
  long long l = 0;
  long long ct = 400;
  while (ct && one) {
    l = (l + n - d) % n;
    calc(a, l, one);
    l = 0;
    ans += 1;
    if (one == 0) break;
    ct--;
  }
  if (one) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
  long long NTC = 1;
  cin >> NTC;
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
