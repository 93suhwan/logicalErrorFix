#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long* X, long long* Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const long long inf = 2147383647;
const long long mod = 1000000007;
const double pi = 2 * acos(0.0);
const double eps = 1e-11;
int ks;
int n, A[1005];
bool check() {
  for (int i = 1; i <= n; i++) {
    if (i != A[i]) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1;; i++) {
    if (check()) {
      cout << i - 1 << "\n";
      return;
    }
    if (i % 2) {
      for (int j = 1; j <= n - 2; j += 2) {
        if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
      }
    } else {
      for (int j = 2; j <= n - 1; j += 2) {
        if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (ks = 1; ks <= tc; ks++) {
    solve();
  }
  return 0;
}
