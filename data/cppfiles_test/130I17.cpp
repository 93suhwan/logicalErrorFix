#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 1e9 + 7;
int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res % M;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
int n;
bool st[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) st[i] = 0;
  int lt, t, x, y;
  printf("? 1 2 3\n");
  fflush(stdout);
  scanf("%d", &lt);
  for (int i = 2; i + 2 <= n; i++) {
    printf("? %d %d %d\n", i, i + 1, i + 2);
    fflush(stdout);
    scanf("%d", &t);
    if (lt != t) {
      if (lt == 0)
        x = i - 1, y = i + 2;
      else
        x = i + 2, y = i - 1;
      break;
    } else
      lt = t;
  }
  st[x] = 1;
  int p;
  for (int i = 1; i <= n; i++) {
    if (i == x || i == y) continue;
    printf("? %d %d %d\n", x, y, i);
    fflush(stdout);
    scanf("%d", &p);
    if (p == 0) st[i] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (st[i]) cnt++;
  printf("! %d ", cnt);
  for (int i = 1; i <= n; i++) {
    if (st[i]) printf("%d ", i);
  }
  puts("");
  fflush(stdout);
}
signed main() {
  int _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
