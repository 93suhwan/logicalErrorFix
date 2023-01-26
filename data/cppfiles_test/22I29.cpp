#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool op = false;
  char c = getchar();
  while (!isdigit(c)) op |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 2e5 + 10;
int n, m, B;
int X[N], Y[N], lst[N], dif[N];
int main() {
  n = read();
  m = read();
  B = sqrt(m);
  for (int i = 1; i <= n; i++) X[i] = read(), Y[i] = read();
  for (int t = 1; t <= m; t++) {
    int op = read();
    if (op == 1) {
      int x = read();
      lst[x] = t;
    }
    if (op == 2) {
      int x = read();
      for (int i = lst[x] + X[x]; i < t; i += X[x] + Y[x]) {
        dif[i]++;
        if (i + Y[x] >= t) dif[t]--;
      }
      for (int i = lst[x] + X[x] + Y[x]; i < t; i += X[x] + Y[x]) {
        dif[i]--;
      }
      lst[x] = 0;
    }
  }
  for (int x = 1; x <= n; x++) {
    if (lst[x]) {
      for (int i = lst[x] + X[x]; i <= n; i += X[x] + Y[x]) dif[i]++;
      for (int i = lst[x] + X[x] + Y[x]; i <= n; i += X[x] + Y[x]) dif[i]--;
    }
  }
  for (int i = 1; i <= m; i++) dif[i] += dif[i - 1], printf("%d\n", dif[i]);
  return 0;
}
