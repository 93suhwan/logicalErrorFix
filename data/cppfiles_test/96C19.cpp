#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
inline int readint() {
  int ans = 0;
  bool sign = true;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') sign = false;
  while (isdigit(c)) {
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
    c = getchar();
  }
  return ans * (sign ? 1 : -1);
}
inline void readint(int &x) { x = readint(); }
template <typename... Ts>
inline void readint(int &x, Ts &...y) {
  x = readint();
  readint(y...);
}
int quickPow(int a, int b, int mod = 1e9 + 7) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return res % mod;
}
const int INF = 0x3f3f3f3f;
const long long LLINF = ((long long)INF << 32) | INF;
const int mod = 998244353;
int add(int a, int b) { return a + b > mod ? a + b - mod : a + b; }
int iadd(int &a, int b) { return a = add(a, b); }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int isub(int &a, int b) { return a = sub(a, b); }
int mul(int a, int b) { return ((long long)a * b) % mod; }
int imul(int &a, int b) { return a = mul(a, b); }
int n, x;
int dp[501][501];
int C[501][501];
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
}
int main() {
  ;
  init();
  readint(n, x);
  for (int i = 1; i <= x; ++i) {
    dp[1][i] = i;
    dp[2][i] = i * (i - 1);
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (j < i) {
        dp[i][j] = 0;
      } else {
        for (int k = 0; k < i; ++k) {
          iadd(dp[i][j], mul(mul(dp[i - k][j - i + 1], quickPow(i - 1, k, mod)),
                             C[i][k]));
        }
      }
    }
  }
  cout << sub(quickPow(x, n, mod), dp[n][x]) << '\n';
  return 0;
}
