#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void cmin(T &a, T b) {
  ((a > b) && (a = b));
}
template <class T>
inline void cmax(T &a, T b) {
  ((a < b) && (a = b));
}
char IO;
template <class T = int>
T rd() {
  T s = 0;
  int f = 0;
  while (!isdigit(IO = getchar())) f |= IO == '-';
  do s = (s << 1) + (s << 3) + (IO ^ '0');
  while (isdigit(IO = getchar()));
  return f ? -s : s;
}
bool Mbe;
const int N = 4010, INF = 1e9 + 10;
int n, m;
long long A[N], dp[N][N];
int Go(int l, int r) {
  if (l > r) return 0;
  int u = l;
  for (int i = l, iend = r; i <= iend; ++i)
    if (A[i] < A[u]) u = i;
  for (int i = 1, iend = r - l + 1; i <= iend; ++i) dp[u][i] = -1e18;
  int ls = Go(l, u - 1);
  int rs = Go(u + 1, r);
  for (int i = 0, iend = u - l; i <= iend; ++i)
    for (int j = 0, jend = r - u; j <= jend; ++j) {
      cmax(dp[u][i + j], dp[ls][i] + dp[rs][j] - 2ll * A[u] * i * j);
      cmax(dp[u][i + j + 1],
           dp[ls][i] + dp[rs][j] - A[u] * (2 * (i * j + i + j) + 1 - m));
    }
  return u;
}
bool Med;
int main() {
  n = rd(), m = rd();
  for (int i = 1, iend = n; i <= iend; ++i) A[i] = rd();
  int u = Go(1, n);
  printf("%lld\n", dp[u][m]);
}
