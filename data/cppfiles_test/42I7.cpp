#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int N, M;
pair<int, int> A[202020];
pair<int, int> B[202020];
long long D[202020];
struct FWT {
  long long T[404040] = {
      0,
  };
  void upd(int x, int v) {
    for (int i = x; i <= 2 * N; i += i & -i) T[i] = (T[i] + v) % MOD;
  }
  long long get(int x) {
    long long ret = 0;
    for (int i = x; i; i -= i & -i) ret = (ret + T[i]) % MOD;
    return ret;
  }
  long long query(int l, int r) { return (get(r) + MOD - get(l - 1)) % MOD; }
} fwt;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &A[i].second, &A[i].first);
  }
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    int t;
    scanf("%d", &t);
    B[i] = A[t];
  }
  sort(A + 1, A + N + 1);
  sort(B + 1, B + M + 1);
  for (int i = 1; i <= N; i++) {
    D[i] = ((A[i].first - A[i].second) +
            fwt.query(A[i].second + 1, A[i].first - 1)) %
           MOD;
    fwt.upd(A[i].first, D[i]);
  }
  long long ans = B[M].first;
  int t = lower_bound(A + 1, A + N + 1, B[M]) - A;
  for (int i = 1; i < t; i++) ans = (ans + D[i]) % MOD;
  int l = B[M].second + 1;
  while (t) {
    if (B[t].second < l) {
      t--;
      continue;
    }
    ans = (ans + B[t].first - l + 1) % MOD;
    ans = (ans + fwt.query(l, B[t].first - 1)) % MOD;
    t--;
    l = B[t].second + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
