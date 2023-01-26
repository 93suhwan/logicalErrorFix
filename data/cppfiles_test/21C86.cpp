#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
namespace ywy {
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
int n, k, m, p;
int dp[110][110][110], bv[110][110][110], c[110][110];
long long f(int leaf, int deep, int pts) {
  if (bv[leaf][deep][pts]) return dp[leaf][deep][pts];
  if (pts > leaf - 1) return 0;
  if (k < deep && pts) return 0;
  if (k >= deep && k - deep <= 30 && pts > (1 << (k - deep))) return 0;
  bv[leaf][deep][pts] = 1;
  long long ans = 0;
  if (deep == k) {
    if (!pts && leaf == 1) return dp[leaf][deep][pts] = 1;
    if (pts != 1) return dp[leaf][deep][pts] = 0;
    for (int i = 1; i < leaf; i++)
      ans = (ans + f(i, deep + 1, 0) * f(leaf - i, deep + 1, 0) % p *
                       c[leaf - 2][i - 1]) %
            p;
  } else {
    if (!pts && leaf == 1) return dp[leaf][deep][pts] = 1;
    for (int i = 1; i < leaf; i++) {
      for (int j = max(0, pts - leaf + i + 1); j <= pts && j <= i - 1; j++) {
        ans = (ans + f(i, deep + 1, j) * f(leaf - i, deep + 1, pts - j) % p *
                         c[leaf - 2][i - 1]) %
              p;
      }
    }
  }
  return dp[leaf][deep][pts] = ans;
}
void ywymain() {
  n = get();
  m = get();
  k = get();
  p = get();
  swap(m, k);
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  cout << f(n + 1, 1, m) << endl;
}
}  // namespace ywy
int main() { ywy::ywymain(); }
