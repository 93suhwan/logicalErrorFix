#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int T, n;
long long a[N], z[100], b[100];
int f[N][100], top, t2, id[100];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i - 1] = abs(a[i] - a[i - 1]);
      for (int j = 0; j <= 80; j++) f[i][j] = 0;
    }
    int ans = 1;
    top = 0;
    for (int i = 1; i <= n - 1; i++) {
      t2 = 0;
      memset(id, 0, sizeof(id));
      z[top + 1] = a[i];
      for (int j = 1; j <= top; j++) {
        id[j] = t2 + 1;
        if (gcd(z[j], a[i]) != gcd(z[j + 1], a[i])) b[++t2] = gcd(z[j], a[i]);
      }
      id[top + 1] = t2 + 1;
      b[++t2] = gcd(z[top + 1], a[i]);
      for (int j = 1; j <= top; j++)
        f[i][id[j]] = max(f[i][id[j]], f[i - 1][j] + 1);
      if (!f[i][t2]) f[i][t2] = 1;
      for (int j = 1; j <= t2; j++) z[j] = b[j];
      top = t2;
      for (int j = 1; j <= top; j++)
        if (z[j] > 1) ans = max(ans, f[i][j] + 1);
    }
    printf("%d\n", ans);
  }
}
