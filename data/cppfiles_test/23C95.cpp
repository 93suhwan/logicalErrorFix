#include <bits/stdc++.h>
using namespace std;
inline void out(int *a, int l, int r) {
  for (int i = l; i <= r; ++i) printf("%d ", *(a + i));
  puts("");
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 4005;
const long long inf = 1e15;
int a[N], n, k, pos[N][N], tot;
unordered_map<int, int> mp;
bool g[N][N];
long long f[N][N];
long long solve(int L, int R, int m) {
  if (m < 0) return -inf;
  if (L > R) {
    if (m == 0) return 0;
    return -inf;
  }
  if (L == R) {
    if (m == 0) return 0;
    if (m == 1) return a[L] * (k - 1ll);
    return -inf;
  }
  if (!mp.count(L * n + R)) mp[L * n + R] = ++tot;
  int x = mp[L * n + R];
  if (g[x][m]) return f[x][m];
  g[x][m] = 1;
  int mid = pos[L][R];
  if (mid == L)
    return f[x][m] = max(solve(L + 1, R, m), solve(L + 1, R, m - 1) +
                                                 a[L] * (k - 1ll) -
                                                 2ll * a[L] * (m - 1));
  if (mid == R)
    return f[x][m] = max(solve(L, R - 1, m), solve(L, R - 1, m - 1) +
                                                 a[R] * (k - 1ll) -
                                                 2ll * a[R] * (m - 1));
  if (mid - L < R - mid)
    for (int i = 0; i <= min(m, mid - L + 1); ++i)
      f[x][m] = max(f[x][m], solve(L, mid, i) + solve(mid + 1, R, m - i) -
                                 2ll * i * (m - i) * a[mid]);
  else
    for (int i = 0; i <= min(m, R - mid + 1); ++i)
      f[x][m] = max(f[x][m], solve(L, mid, m - i) + solve(mid + 1, R, i) -
                                 2ll * i * (m - i) * a[mid]);
  return f[x][m];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) a[i] = read(), pos[i][i] = i;
  for (int len = 2; len <= n; ++len)
    for (int i = 1; i <= n - len + 1; ++i) {
      int j = i + len - 1;
      if (a[pos[i + 1][j]] < a[i])
        pos[i][j] = pos[i + 1][j];
      else
        pos[i][j] = i;
    }
  cout << solve(1, n, k);
  return 0;
}
