#include <bits/stdc++.h>
using namespace std;
void Clearing_out() { return; }
template <typename Head, typename... Tail>
void Clearing_out(Head &H, Tail &...T) {
  H.clear();
  Clearing_out(T...);
}
long long int extendedEuclid(long long int A, long long int B, long long int &x,
                             long long int &y) {
  if (B == 0) {
    x = 1;
    y = 0;
    return A;
  } else {
    long long int x1, y1;
    long long int gcd = extendedEuclid(B, A % B, x1, y1);
    y = x1 - (A / B) * y1;
    x = y1;
    return gcd;
  }
}
long long int mi(long long int A, long long int M) {
  long long int x, y;
  extendedEuclid(A, M, x, y);
  if (x < 0) {
    x += M;
  }
  return x;
}
const long long int nax = 3e5 + 5;
long long int fact[nax];
void F() {
  fact[0] = 1;
  for (long long int i = 1; i < nax; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= 998244353;
  }
}
long long int nCr(long long int n, long long int r, long long int M) {
  if (n < r) return 0;
  return (((fact[n] * mi(fact[r], M)) % M) * mi(fact[n - r] % M, M)) % M;
}
inline long long int add(long long int val1, long long int val2) {
  long long int ans = val1 + val2;
  if (ans >= 998244353) {
    ans -= 998244353;
  }
  return ans;
}
inline long long int sub(long long int val1, long long int val2) {
  long long int ans = val1 - val2;
  if (ans < 0) {
    ans += 998244353;
  }
  return ans;
}
inline long long int mult(long long int val1, long long int val2) {
  long long int ans = (val1 * 1LL * val2) % 998244353;
  return ans;
}
long long int power(long long int base, long long int val) {
  base = base % 998244353;
  long long int res = 1;
  while (val > 0) {
    if ((val & 1)) {
      res = mult(res, base);
    }
    base = mult(base, base);
    val = (val >> 1);
  }
  return res;
}
const long long int N = 505;
long long int dp[N][N];
long long int n, x;
long long int recur(long long int damage, long long int left) {
  if (left == 0) {
    return 1;
  }
  if (damage >= x || left == 1) {
    return 0;
  }
  if (dp[damage][left] != -1) {
    return dp[damage][left];
  }
  dp[damage][left] = 0;
  for (long long int i = 0; i <= left; i++) {
    long long int option = min(x - damage, left - 1);
    dp[damage][left] =
        add(dp[damage][left],
            mult(nCr(left, i, 998244353),
                 mult(power(option, i), recur(damage + left - 1, left - i))));
  }
  return dp[damage][left];
}
void testcase() {
  cin >> n >> x;
  memset(dp, -1, sizeof(dp));
  cout << recur(0, n) << "\n";
  return;
}
int32_t main() {
  long long int test = 1;
  F();
  long long int t = 0;
  while (test--) {
    testcase();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
