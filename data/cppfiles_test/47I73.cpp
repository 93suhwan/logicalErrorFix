#include <bits/stdc++.h>
using namespace std;
int s[10002];
void solve(int a, int b, int c) {
  int x, x1, x2, x3;
  printf("and %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x1);
  printf("or %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x);
  x1 += x;
  printf("and %d %d\n", b, c);
  fflush(stdout);
  scanf("%d", &x2);
  printf("or %d %d\n", b, c);
  fflush(stdout);
  scanf("%d", &x);
  x2 += x;
  printf("and %d %d\n", a, c);
  fflush(stdout);
  scanf("%d", &x3);
  printf("or %d %d\n", a, c);
  fflush(stdout);
  scanf("%d", &x);
  x3 += x;
  x = x1 + x2 + x3 >> 1;
  s[a] = x - x2;
  s[b] = x - x3;
  s[c] = x - x1;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i += 3) solve(i, i + 1, i + 2);
  if (n % 3) solve(n - 2, n - 1, n);
  sort(s + 1, s + n + 1);
  printf("%d", s[k]);
}
