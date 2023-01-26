#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c;
  bool bo;
  long long res;
  while (((c = getchar()) < 48 || c > 57) && c ^ 45)
    ;
  if (c ^ 45)
    bo = 0, res = c ^ 48;
  else
    bo = 1, res = 0;
  while ((c = getchar()) >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c ^ 48);
  return bo ? ~res + 1 : res;
}
const int N = 1e3 + 50;
int n, k, pw[N], col[N][N];
int main() {
  n = read();
  k = read();
  int res = 1, cnt = 0;
  pw[0] = 1;
  while (res < n) {
    res *= k;
    pw[++cnt] = res;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= cnt; j++) col[i][j] = (i - 1) / pw[j] + 1;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      for (int l = cnt - 1; l >= 0; l--)
        if (col[i][l] != col[j][l]) {
          printf("%d ", l + 1);
          break;
        }
    }
  return 0;
}
