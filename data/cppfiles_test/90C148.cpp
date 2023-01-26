#include <bits/stdc++.h>
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
using namespace std;
using ld = long double;
using vi = vector<int>;
using mi = map<int, int>;
using pi = pair<int, int>;
const int M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
long long int bin(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int res = bin(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long int exponentMod(long long int A, long long int B, long long int C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long long int y;
  if (B % 2 == 0) {
    y = exponentMod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * exponentMod(A, B - 1, C) % C) % C;
  }
  return (long long int)((y + C) % C);
}
long long int isprime(long long int x) {
  long long int i, res = 1;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      res = i;
      break;
    }
  }
  return res;
}
void solve() {
  int x, y;
  cin >> x >> y;
  int t = y % x;
  if (x > y)
    printf("%lld\n", x + y);
  else
    printf("%lld\n", y - t / 2);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
