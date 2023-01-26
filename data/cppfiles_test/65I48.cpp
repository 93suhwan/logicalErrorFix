#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
int n, a[N], kind[N], p[N];
char s[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void print(int i) { printf("%d %c\n", a[i], (kind[i] == 1) ? 'R' : 'L'); }
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  scanf("%s", s + 1);
  sort(a + 1, a + 1 + n);
  if (s[n] == 'R')
    for (int i = 1; i <= n; i++) kind[i] = (i & 1);
  else
    for (int i = 1; i <= n; i++) kind[i] = !(i & 1);
  int l = 1, r = n;
  for (int i = n; i >= 2; i--) {
    int op = (s[i - 1] == 'R');
    p[i] = (kind[r] == op) ? l++ : r--;
  }
  p[1] = l;
  for (int i = 1; i <= n; i++) print(p[i]);
}
