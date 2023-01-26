#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
unsigned long long GCD(unsigned long long x, unsigned long long y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}
unsigned long long LCM(unsigned long long a, unsigned long long b) {
  return (a * b / (GCD(a, b)));
}
bool PRIME(int p) {
  if (p <= 1) return false;
  if (p <= 3) return true;
  if (p % 2 == 0 || p % 3 == 0) return false;
  for (int i = 5; p >= i * i; i = i + 6) {
    if (p % i == 0 || p % (i + 2) == 0) return false;
  }
  return true;
}
long long NXT(long long a) {
  if (a <= 1) return 2;
  long long p = a;
  bool x = false;
  while (!x) {
    p++;
    if (PRIME(p)) x = true;
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, b, c, d, e, t, i, j, k, l, p, q, r,
      sum = 0, ans = 0, x, y, z, m, n, o, u, mx = -1e10, mn = 1e9;
  t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    long long A[113];
    x = y = 0;
    for (i = 0; i < n; i++) {
      cin >> A[i];
      if (A[i] == 1)
        x++;
      else if (A[i] == 0)
        x++;
      sum += A[i];
    }
    if (x == 0)
      cout << 0 << endl;
    else
      cout << pow(2, x - 1) << endl;
  }
  return 0;
}
