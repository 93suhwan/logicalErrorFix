#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 998244353;
const long long maxn = 1.2e6 + 107;
const double pi = acos(-1.0);
const double eps = 0.0000000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline void pr2(T x, unsigned long long k = 64) {
  unsigned long long i;
  for (i = 0; i < k; i++) fprintf(stderr, "%d", (int)((x >> i) & 1));
  putchar(' ');
}
template <typename T>
inline void add_(T &A, int B, long long MOD = M) {
  A += B;
  (A >= MOD) && (A -= MOD);
}
template <typename T>
inline void mul_(T &A, long long B, long long MOD = M) {
  A = (A * B) % MOD;
}
template <typename T>
inline void mod_(T &A, long long MOD = M) {
  A %= MOD;
  A += MOD;
  A %= MOD;
}
template <typename T>
inline void max_(T &A, T B) {
  (A < B) && (A = B);
}
template <typename T>
inline void min_(T &A, T B) {
  (A > B) && (A = B);
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
inline long long powMM(long long a, long long b, long long mod = M) {
  long long ret = 1;
  for (; b; b >>= 1ll, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
int startTime;
void startTimer() { startTime = clock(); }
void printTimer() {
  fprintf(stderr, "/--- Time: %ld milliseconds ---/\n", clock() - startTime);
}
int value[27];
bool solve(int x, int ans, int not_0, int flag, int mask, int cnt) {
  int i;
  if (x == 0) {
    printf("%d\n", ans);
    return 1;
  }
  for (i = 0; i <= 9; i++) {
    int nxtmask = mask, nxtcnt = cnt, nxtflag = flag;
    if ((not_0 || i) && !((mask >> i) & 1)) nxtmask |= 1 << i, nxtcnt--;
    if (nxtcnt < 0) continue;
    if (!flag && i < value[x]) continue;
    if (i > value[x]) nxtflag |= 1;
    int done = solve(x - 1, ans * 10 + i, not_0 || i, nxtflag, nxtmask, nxtcnt);
    if (done) return 1;
  }
  return 0;
}
void solve(int x, int cnt) {
  int length = 0;
  while (x) value[++length] = x % 10, x /= 10;
  value[++length] = 0;
  solve(length, 0, 0, 0, 0, cnt);
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  solve(n, k);
}
int main() {
  int T, _;
  T = 1;
  scanf("%d", &T);
  for (_ = 1; _ <= T; _++) solve();
}
