#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  int f = 0;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  if (f) x = -x;
}
const int N = 2e5 + 5, M = 1e5;
int f[N], n, a[N];
signed main() {
  int T;
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]), a[n + i] = -a[i];
    memset(f, 0, sizeof(f));
    f[0 + M] = 1;
    for (int i = 1; i <= n * 2; ++i) {
      if (a[i] > 0)
        for (int j = 2 * M; j >= a[i]; --j) f[j] += f[j - a[i]];
      else
        for (int j = 0; j - a[i] <= 2 * M; ++j) f[j] += f[j - a[i]];
    }
    int tag = 0;
    for (int i = 1; i <= n && tag == 0; ++i) {
      int x = abs(a[i]);
      for (int j = 2 * M; j >= x; --j) f[j] -= f[j - x];
      for (int j = 0; j + x <= 2 * M; ++j) f[j] -= f[j + x];
      if (f[a[i] + M] || a[i] == 0) tag = 1;
      for (int j = 2 * M; j >= x; --j) f[j] += f[j - x];
      for (int j = 0; j + x <= 2 * M; ++j) f[j] += f[j + x];
    }
    puts(tag ? "YES" : "NO");
  }
}
