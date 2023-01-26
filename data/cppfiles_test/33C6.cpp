#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 0x3f3f3f3f;
int f[N], a[N];
int main() {
  int n, x;
  scanf("%d", &n);
  memset(a, 0x3f, sizeof(a));
  f[0] = 1;
  a[0] = 0;
  while (n--) {
    scanf("%d", &x);
    for (int i = 0; i < N / 2; i++)
      if (f[i] && a[i] < x) {
        f[i ^ x] = 1;
        if (x < a[i ^ x]) a[i ^ x] = x;
      }
  }
  int s = 0;
  for (int i = 0; i < N; i++) s += f[i];
  printf("%d\n", s);
  for (int i = 0; i < N; i++)
    if (f[i]) printf("%d ", i);
  puts("");
  return 0;
}
