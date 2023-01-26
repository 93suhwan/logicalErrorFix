#include <bits/stdc++.h>
using namespace std;
long long a[2005], b[2005], c[2005][2005];
long long f[2005][2005];
long long n, m;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++) b[i] = i - a[i];
    for (long long i = n; i >= 1; i--)
      for (long long j = 0; j <= n; j++)
        if (b[i] == j)
          c[i][j] = c[i + 1][j] + 1;
        else
          c[i][j] = c[i + 1][j];
    for (long long i = 1; i <= n; i++) f[i][0] = c[1][0];
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= i; j++)
        f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] - c[i][j - 1] + c[i + 1][j]);
    long long i = 0;
    for (; i <= n; i++)
      if (f[n][i] >= m) {
        cout << i << endl;
        break;
      }
    if (i > n) cout << -1 << endl;
  }
  return 0;
}
