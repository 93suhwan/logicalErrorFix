#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
int n, m, a[N][N], b[N][N];
string s;
int ans[N][N], f[N][N];
int col[N], que[N], head, tail;
long long x[N], y[N];
long long sqr(long long x) { return x * x; }
void work() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) f[i][j] = inf;
  for (int i = 0; i <= m; i++) col[i] = -1;
  for (int i = 0; i <= n; i++) {
    tail = 0, head = 1;
    for (int j = 0; j <= m; j++) {
      if (b[i][j] == 1) col[j] = i;
      if (col[j] != -1) {
        y[j] = sqr(i - col[j]) + sqr(j);
        x[j] = 2 * j;
        while (tail >= head && y[j] <= y[que[tail]]) tail--;
        while (tail > head &&
               (y[j] - y[que[tail]]) * (x[que[tail]] - x[que[tail - 1]]) <
                   (y[que[tail]] - y[que[tail - 1]]) * (x[j] - x[que[tail]]))
          tail--;
        que[++tail] = j;
      }
      while (tail > head && y[que[head + 1]] - x[que[head + 1]] * j <
                                y[que[head]] - x[que[head]] * j)
        head++;
      if (head <= tail) f[i][j] = y[que[head]] - x[que[head]] * j + j * j;
    }
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    cin >> s;
    for (int j = 0; j <= m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = inf;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) b[i][j] = a[i][j];
  work();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = min(ans[i][j], f[i][j]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) b[n - i][j] = a[i][j];
  work();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = min(ans[i][j], f[n - i][j]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) b[i][m - j] = a[i][j];
  work();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = min(ans[i][j], f[i][m - j]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) b[n - i][m - j] = a[i][j];
  work();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = min(ans[i][j], f[n - i][m - j]);
  long long res = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) res += ans[i][j];
  cout << res << "\n";
  return 0;
}
