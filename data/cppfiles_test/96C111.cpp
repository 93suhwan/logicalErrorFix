#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
long long C[3000][3000];
long long a[3000][3000];
long long calc(long long n, long long x) {
  if (a[n][x]) return a[n][x];
  if (n == 1) return 0;
  if (n == 0) return 1;
  if (n - 1 >= x) {
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
      ans *= x;
      ans %= 998244353;
    }
    return ans;
  }
  long long pre = 1, ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += calc(n - i, x - n + 1) * C[n][i] % 998244353 * pre % 998244353;
    ans %= 998244353;
    pre *= (n - 1);
    pre %= 998244353;
  }
  a[n][x] = ans;
  return ans;
}
int main() {
  int n = read(), x = read();
  C[1][1] = C[1][0] = 1;
  for (int i = 2; i < 1000; ++i) {
    C[i][0] = C[i][1] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 998244353;
    }
  }
  cout << calc(n, x);
  return 0;
}
