#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &first, T second) {
  return second < first ? first = second, 1 : 0;
}
template <typename T>
bool chkmax(T &first, T second) {
  return first < second ? first = second, 1 : 0;
}
template <typename T>
void readint(T &first) {
  int f = 1;
  char c;
  first = 0;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
const int MOD = 1000000007;
inline int dmy(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int second) { first = dmy(first + second); }
int qmi(int first, int second) {
  int ans = 1;
  for (; second; second >>= 1, first = 1ll * first * first % MOD)
    if (second & 1) ans = 1ll * ans * first % MOD;
  return ans;
}
const int MAXN = 400005, K = 15;
int n, a[MAXN];
int pre[K + 1][MAXN], kr[K + 1][MAXN];
int pd[K + 1], pc[K + 1], binom[K + 1][K + 1];
int main() {
  int Q;
  readint(n), readint(Q);
  for (int i = 1; i <= n; ++i) readint(a[i]), a[i + n] = a[i];
  for (int i = 1; i <= 2 * n; ++i) {
    int first = 1, second = 1;
    for (int k = 0; k <= K; ++k)
      pre[k][i] = dmy(pre[k][i - 1] + first),
      kr[k][i] = dmy(kr[k][i - 1] + second), first = 1ll * first * a[i] % MOD,
      second = 1ll * second * (i - 1) % MOD;
  }
  for (int i = 0; i <= K; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      binom[i][j] = dmy(binom[i - 1][j - 1] + binom[i - 1][j]);
  }
  while (Q--) {
    int l, r, d;
    readint(l), readint(r), readint(d);
    if (r < l) r += n;
    int m = r - l + 1;
    int c = ((pre[1][r] - pre[1][l - 1] - 1ll * kr[1][m] * d) % MOD + MOD) *
            qmi(m, MOD - 2) % MOD;
    pc[0] = pd[0] = 1;
    for (int k = 1; k <= K; ++k)
      pc[k] = 1ll * pc[k - 1] * c % MOD, pd[k] = 1ll * pd[k - 1] * d % MOD;
    bool fl = 1;
    for (int k = 2; k <= K; ++k) {
      int sum = 0;
      for (int j = 0; j <= k; ++j)
        inc(sum,
            1ll * pd[j] * pc[k - j] % MOD * binom[k][j] % MOD * kr[j][m] % MOD);
      if (sum != dmy(pre[k][r] - pre[k][l - 1] + MOD)) {
        fl = 0;
        break;
      }
    }
    printf(fl ? "Yes\n" : "No\n");
  }
  return 0;
}
