#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int c) {
  int v = abs(b - a);
  if ((a > v && b > v) || c > 2 * v) {
    return -1;
  }
  return ((c - 1) + v) % (2 * v) + 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = solve(a, b, c);
    printf("%d\n", ans);
  }
  return 0;
}
