#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
}
long long quick_mod(long long A, long long B) {
  long long ret = 1;
  A %= MOD;
  while (B) {
    if (B & 1) ret = ret * A % MOD;
    B >>= 1;
    A = A * A % MOD;
  }
  return ret;
}
inline void chkmin(long long &x, long long y) { x = min(x, y); }
inline void chkmax(long long &x, long long y) { x = max(x, y); }
inline void add(long long &x, long long y) { x = (x + y) % MOD; }
inline long long rev(long long x) { return quick_mod(x, MOD - 2); }
inline int lowbit(int x) { return x & (-x); }
int N;
int A[1010];
inline bool check() {
  for (int i = 0; i < N - 1; ++i)
    if (A[i + 1] < A[i]) return 0;
  return 1;
}
void solve() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", A + i);
  int ans = 0;
  while (!check()) {
    if (ans & 1) {
      for (int i = 1; i + 1 < N; i += 2) {
        if (A[i + 1] < A[i]) {
          swap(A[i + 1], A[i]);
        }
      }
    } else {
      for (int i = 0; i + 1 < N; i += 2) {
        if (A[i + 1] < A[i]) {
          swap(A[i + 1], A[i]);
        }
      }
    }
    ans++;
  }
  printf("%d\n", ans);
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
