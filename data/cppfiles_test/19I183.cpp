#include <bits/stdc++.h>
using namespace std;
const int int_inf = 0x7fffffff;
const long long ll_inf = (1ll << 63) - 1;
const double eps = 1e-7;
inline int read() {
  int f = 1, x = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  x = ch - '0';
  while (isdigit(ch = getchar())) x = x * 10 + ch - '0';
  return x * f;
}
inline void read(int num, ...) {
  va_list res;
  va_start(res, &num);
  for (int i = 1; i <= num; i++) *va_arg(res, int*) = read();
  va_end(res);
  return;
}
const int N = 20;
int n, a[N], b[N], ok = 0;
inline void dfs(int pos) {
  if (ok) return;
  if (pos > n) {
    for (int i = 1; i <= n; i++) {
      int fl = 0;
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if (a[i] == b[j] - b[k]) fl = 1;
      if (!fl) return;
    }
    ok = 1;
    return;
  }
  for (int i = 1; i < pos - 1; i++)
    for (int j = 1; j < pos - 1; j++)
      if (b[i] - b[j] == a[pos - 1]) {
        ok = 1;
        return;
      }
  for (int i = 1; i < pos; i++) {
    b[pos] = b[i] + a[pos];
    dfs(pos + 1);
  }
  return;
}
inline void work() {
  cin >> n;
  ok = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  b[1] = 0;
  dfs(2);
  if (ok || a[1] == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
