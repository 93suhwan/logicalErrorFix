#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const long long int mod = 1e9 + 7;
long long int powmod(long long int x, long long int y) {
  long long int t;
  for (t = 1; y; y >>= 1, x = x * x % mod)
    if (y & 1) t = t * x % mod;
  return t;
}
long long int gcd(long long int x, long long int y) {
  return y ? gcd(y, x % y) : x;
}
long long int lcm(long long int x, long long int y) {
  return x * (y / gcd(x, y));
}
long long int modd(long long int a) { return (a % mod + mod) % mod; }
double findMod(double a, double b) {
  double mods;
  if (a < 0)
    mods = -a;
  else
    mods = a;
  if (b < 0) b = -b;
  while (mods >= b) mods = mods - b;
  if (a < 0) return -mods;
  return mods;
}
vector<long long int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (long long int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long int add(long long int a, long long int b) {
  return modd(modd(a) + modd(b));
}
long long int mul(long long int a, long long int b) {
  return modd(modd(a) * modd(b));
}
int smask(int i, int pos) { return (i | (1 << pos)); }
int clmask(int i, int pos) { return (i & (~(1 << pos))); }
bool chmask(int i, int pos) { return (i & (1 << pos)) != 0; }
double cordist(pair<double, double> a, pair<double, double> b) {
  return sqrt(((a.first - b.first) * (a.first - b.first)) +
              ((a.second - b.second) * (a.second - b.second)));
}
long long binpow(long long a, long long b) {
  if (b <= 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return mul(mul(res, res), a);
  else
    return mul(res, res);
}
long long int divs(long long int a, long long int b) {
  return a * binpow(b, mod - 2);
}
long long int n, m, q, r, i, j;
vector<long long int> arr;
vector<long long int> C;
vector<long long int> fact;
void init(int n) {
  fact.clear();
  fact.resize(n, 0);
  fact[0] = 1;
  for (i = 1; i < n; i++) {
    fact[i] = mul(i, fact[i - 1]);
  }
}
void binomialCoeff(int n, int k) {
  C.clear();
  C.resize(k + 1, 0);
  C[0] = 1;
  for (i = 0; i < k + 1; i++) {
    long long int top = fact[n];
    long long int below = fact[i];
    long long int below2 = fact[n - i];
    C[i] = divs(top, mul(below, below2));
  }
}
void solve() {
  cin >> n >> m;
  if (m == 0) {
    cout << 1 << "\n";
    return;
  }
  binomialCoeff(n, n);
  long long int res = 0;
  bool flag = false;
  for (i = 0; i <= n; i += 2) {
    res += mul(m, C[i]);
    if (i == n) flag = true;
  }
  if (!flag) res += mul(m, C[n]);
  cout << res << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k = 1;
  init(200005);
  cin >> k;
  while (k--) {
    solve();
  }
  return 0;
}
