#include <bits/stdc++.h>
using namespace std;
const int N = 8192;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, a[maxn], b[N], st[N], ans;
int main() {
  n = read();
  int sum = 0;
  b[0] = 1;
  for (int i = 1; i <= n; i++) a[i] = read(), sum ^= a[i], b[sum] = 1;
  for (int i = 0; i < N; i++) {
    int flag = 0;
    for (int j = 0; j < N; j++)
      if (b[j] && b[i ^ j]) {
        flag = 1;
        break;
      }
    if (!flag) continue;
    st[++ans] = i;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d ", st[i]);
  puts("");
  return 0;
}
