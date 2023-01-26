#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int M = N * 2;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
int n, m, k;
int A[N];
char str[N];
signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (n & 1) {
      for (int i = 1; i <= n - 3; i += 2) printf("%d %d ", -A[i + 1], A[i]);
      int a = n, b = n - 1, c = n - 2;
      if (A[b] + A[c] != 0)
        printf("%d %d %d", -A[a], -A[a], A[b] + A[c]);
      else if (A[a] + A[c] != 0)
        printf("%d %d %d", -A[b], -A[b], A[a] + A[c]);
      else if (A[a] + A[b] != 0)
        printf("%d %d %d", -A[c], -A[c], A[b] + A[a]);
    } else {
      for (int i = 1; i <= n; i += 2) printf("%d %d ", -A[i + 1], A[i]);
    }
    puts("");
  }
  return 0;
}
