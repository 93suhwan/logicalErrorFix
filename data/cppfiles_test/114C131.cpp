#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
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
    int mn = 1e6;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mn = min(mn, A[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt == n / 2) break;
      if (A[i] == mn) continue;
      printf("%d %d\n", A[i], mn);
      cnt++;
    }
  }
  return 0;
}
