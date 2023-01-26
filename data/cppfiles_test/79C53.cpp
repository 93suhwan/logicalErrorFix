#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int N = 3e5 + 5;
int a[N], b[N], f[N], pre[N];
int n;
void print(int x) {
  if (x == n) return;
  print(pre[x]);
  cout << x << " ";
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = n, v = n - 1; i >= 1; i--) {
    for (int u = i + b[i]; v >= u - a[u] && v >= 0; v--)
      f[v] = f[i] + 1, pre[v] = i;
    if (v == i - 1) return cout << -1 << endl, 0;
  }
  cout << f[0] << endl;
  print(0);
  cout << endl;
}
