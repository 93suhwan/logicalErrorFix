#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
template <class H>
void DBG(vector<H> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cerr << v[i];
    if (i != (int)v.size() - 1) cerr << ", ";
  }
  cerr << ']' << endl;
}
const long double pi = 3.14159265358979323846;
const long long int mod = 1000000007;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long int randNum(long long int a, long long int b) {
  return a + rand() % (b - a + 1);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int modPow(long long int b, long long int p, long long int m) {
  b %= m;
  long long int result = 1;
  while (p > 0) {
    if (p & 1) result = (result * b) % m;
    b = ((long long int)b * b) % m;
    p >>= 1;
  }
  return result;
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int modInverse(long long int b, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long int modDivide(long long int a, long long int b, long long int m) {
  a = a % m;
  long long int inv = modInverse(b, m);
  if (inv == -1)
    return -1;
  else
    return (inv * a) % m;
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < (unsigned long long)r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (unsigned long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void testcase() {
  int n;
  cin >> n;
  vector<vector<int> > v(2, vector<int>(n, 0));
  for (int i = 0; i < n; i++) cin >> v[0][i];
  for (int i = 0; i < n; i++) cin >> v[1][i];
  vector<vector<int> > presuf = v;
  for (int i = n - 2; i >= 0; i--) {
    presuf[0][i] += presuf[0][i + 1];
  }
  for (int i = 1; i < n; i++) {
    presuf[1][i] += presuf[1][i - 1];
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int tempans = 0;
    if (i + 1 < n) tempans = max(tempans, presuf[0][i + 1]);
    if (i - 1 >= 0) tempans = max(tempans, presuf[1][i - 1]);
    ans = min(tempans, ans);
  }
  cout << ans << endl;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  cin >> tt;
  tt++;
  while (--tt) {
    testcase();
  }
  return 0;
}
