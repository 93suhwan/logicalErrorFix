#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MX = (int)1e10 + 7;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;
long long M = MOD;
long long BinMul(long long a, long long b) {
  long long res = 0;
  while (a > 0) {
    if (a % 2) res = (res + b);
    a >>= 1;
    b <<= 1;
  }
  return res;
}
long long BinPow(long long a, long long k) {
  long long ans = 1;
  while (k > 0) {
    if (k & 1) ans = BinMul(ans, a);
    a = BinMul(a, a);
    k >>= 1;
  }
  return ans;
}
long long CNK_MOD(long long n, long long k) {
  if (n > k and k == 0) return 1;
  long long res1 = 1, res2 = 1;
  for (int i = 1; i <= k; i++) {
    res1 = BinMul(res1, n + 1 - i);
    res2 = BinMul(res2, i);
  }
  res2 = BinPow(res2, M - 2);
  return BinMul(res1, res2);
}
long long gcd(long long a, long long b) {
  if (a == 0) return (b);
  return (gcd(b % a, a));
}
bool suspect(long long b, long long t, long long u, long long n) {
  long long prod = 1;
  while (u) {
    if (u & 1) prod = ((prod * b) % n);
    b = ((b * b) % n);
    u /= 2;
  }
  if (prod == 1) return true;
  for (int i = 1; i <= t; i++) {
    if (prod == n - 1) return true;
    prod = (prod * prod) % n;
  }
  return false;
}
bool isprime(long long n) {
  long long k = n - 1;
  long long t = 0;
  while (!(k % 2)) {
    t++;
    k /= 2;
  }
  if (n > 2 && n % 2 == 0) return 0;
  if (n > 3 && n % 3 == 0) return 0;
  if (n > 5 && n % 5 == 0) return 0;
  if (n > 7 && n % 7 == 0) return 0;
  if (suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n))
    return true;
  return false;
}
struct union_find {
  vector<long long> iParent;
  union_find(long long n) {
    iParent = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
      iParent[i] = i;
    }
  }
  long long find(long long x) {
    if (iParent[x] == x)
      return x;
    else {
      iParent[x] = find(iParent[x]);
      return iParent[x];
    }
  }
  void join(long long x, long long y) { iParent[find(x)] = find(y); }
};
void solve(long long testcase) {
  int n;
  cin >> n;
  struct vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[n - 1] == 0) {
    for (int i = 0; i <= n; i++) cout << i + 1 << ' ';
    cout << '\n';
    return;
  }
  if (a[0] == 1) {
    cout << n + 1 << ' ';
    for (int i = 0; i < n; i++) cout << i + 1 << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0 and a[i + 1] == 1) {
      for (int j = 1; j <= i + 1; j++) {
        cout << j << ' ';
      }
      cout << n + 1 << ' ';
    }
    for (int j = i + 2; j <= n + 1; j++) {
      cout << j << ' ';
    }
    cout << '\n';
    return;
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i = 1LL;
  long long tc;
  cin >> tc;
  for (i = 1; i <= tc; i++) solve(i);
  return 0;
}
