#include <bits/stdc++.h>
using namespace std;
void in(int &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while ((c > '9' || c < '0') && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  x *= f;
}
int t, n, m, a[200005];
int s[200005][25], sum[200005][25];
signed main() {
  in(t);
  for (int i = 0; i <= 200000; i++) {
    int k = 0, m = i;
    while (m) {
      if (m % 2) s[i][k] = 1;
      m /= 2;
      k++;
    }
  }
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j <= 20; j++) {
      s[i][j] += s[i - 1][j];
    }
  }
  while (t--) {
    in(n);
    in(m);
    int ans = 0;
    for (int i = 0; i <= 20; i++) {
      if (s[m][i] - s[n - 1][i]) ans = max(ans, s[m][i] - s[n - 1][i]);
    }
    printf("%d\n", m - n + 1 - ans);
  }
}
