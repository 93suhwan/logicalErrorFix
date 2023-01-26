#include <bits/stdc++.h>
using namespace std;
int read() {
  int tot = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * fh;
}
void getstr(char *a) {
  char c = getchar();
  int len = 0;
  while (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9')))
    c = getchar();
  while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9')) {
    a[++len] = c;
    c = getchar();
  }
}
const int maxn = 6005;
long long n, x[maxn], y[maxn], cntI, cntII, res, ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read();
    y[i] = read();
  }
  for (int i = 1; i <= n; i++) {
    cntI = cntII = 0;
    for (int j = 1; j <= n; j++)
      if (j != i) {
        int tx = abs(x[i] - x[j]), ty = abs(y[i] - y[j]);
        if (tx % 4 == 0 && ty % 4 == 2) cntI++;
        if (tx % 4 == 2 && ty % 4 == 0) cntII++;
      }
    res += cntI * cntII;
  }
  ans = 1LL * n * (n - 1) * (n - 2) / 2 / 3 - res;
  cout << ans << endl;
  return 0;
}
