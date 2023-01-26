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
struct node {
  int mxl, mnl, mxr, mnr, idx;
  inline void init(int a, int b, int c, int d, int e) {
    mxl = a, mnl = b, mxr = c, mnr = d, idx = e;
  }
} p[500050];
inline bool operator<(const struct node &x, const struct node &y) {
  return x.mnl == y.mnl ? x.mxl < y.mxl : x.mnl > y.mnl;
}
char ans[500050];
void solve() {
  int N, M;
  scanf("%d%d", &N, &M);
  int A[N + 2][M + 2], prmx[N + 2][M + 2], prmn[N + 2][M + 2],
      sfmx[N + 2][M + 2], sfmn[N + 2][M + 2];
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) scanf("%d", &A[i][j]);
  for (int i = 1; i <= N; ++i)
    prmx[i][0] = sfmx[i][M + 1] = 0, prmn[i][0] = sfmn[i][M + 1] = INF;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      prmx[i][j] = max(prmx[i][j - 1], A[i][j]);
      prmn[i][j] = min(prmn[i][j - 1], A[i][j]);
    }
  for (int i = N; i >= 1; --i)
    for (int j = M; j >= 1; --j) {
      sfmx[i][j] = max(sfmx[i][j + 1], A[i][j]);
      sfmn[i][j] = min(sfmn[i][j + 1], A[i][j]);
    }
  int prvmx[N + 2], sufmn[N + 2];
  for (int k = 1; k <= M - 1; ++k) {
    for (int i = 1; i <= N; ++i)
      p[i].init(prmx[i][k], prmn[i][k], sfmx[i][k + 1], sfmn[i][k + 1], i);
    prvmx[0] = 0, sufmn[N + 1] = INF;
    sort(p + 1, p + N + 1);
    for (int i = 1; i <= N; ++i) prvmx[i] = max(prvmx[i - 1], p[i].mxr);
    for (int i = N; i >= 1; --i) sufmn[i] = min(sufmn[i + 1], p[i].mnr);
    int as = -1, nmx = 0;
    for (int i = N; i >= 2; --i) {
      nmx = max(nmx, p[i].mxl);
      if (p[i - 1].mnl > nmx && prvmx[i - 1] < sufmn[i]) {
        as = i - 1;
        break;
      }
    }
    if (as != -1) {
      printf("YES\n");
      for (int i = 1; i <= as; ++i) ans[p[i].idx] = 'R';
      for (int i = as + 1; i <= N; ++i) ans[p[i].idx] = 'B';
      for (int i = 1; i <= N; ++i) printf("%c", ans[i]);
      printf(" %d\n", k);
      return;
    }
  }
  printf("NO\n");
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
