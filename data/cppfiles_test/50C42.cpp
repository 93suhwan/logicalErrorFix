#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int P = 998244353;
int N, A[MAXN], sum[MAXN], tot, f[MAXN];
int stk[MAXN], tp;
inline void add(int& a, const int& b) { a = a + b >= P ? a + b - P : a + b; }
inline void sub(int& a, const int& b) { a = a - b < 0 ? a - b + P : a - b; }
inline int psum(const int& a, const int& b) {
  return a + b >= P ? a + b - P : a + b;
}
inline int pdif(const int& a, const int& b) {
  return a - b < 0 ? a - b + P : a - b;
}
int main() {
  scanf("%d", &N);
  for (int i = (1), iend = (N + 1); i < iend; ++i) scanf("%d", &A[i]);
  f[0] = N & 1 ? P - 1 : 1;
  sum[0] = f[0];
  for (int i = (1), iend = (N + 1); i < iend; ++i) {
    while (tp && A[stk[tp - 1]] > A[i]) {
      int L = tp >= 2 ? stk[tp - 2] : 0, R = stk[tp - 1] - 1;
      sub(tot, 1ll * pdif(sum[R], L ? sum[L - 1] : 0) * A[stk[tp - 1]] % P);
      tp--;
    }
    int L = tp ? stk[tp - 1] : 0, R = i - 1;
    add(tot, 1ll * pdif(sum[R], L ? sum[L - 1] : 0) * A[i] % P), stk[tp++] = i;
    f[i] = (tot ? P - tot : tot), sum[i] = sum[i - 1], add(sum[i], f[i]);
  }
  printf("%d\n", f[N]);
  return 0;
}
