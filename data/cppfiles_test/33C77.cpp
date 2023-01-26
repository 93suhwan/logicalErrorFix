#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int f[N], a[1005];
int main() {
  int n, x;
  scanf("%d", &n);
  memset(a, 0x3f, sizeof(a));
  f[0] = 1;
  while (n--) {
    scanf("%d", &x);
    for (int i = 0; i < N / 2; i++)
      if (f[i] && a[i] < x) {
        f[i ^ x] = 1;
        if (x < a[i ^ x]) a[i ^ x] = x;
      }
    f[x] = 1;
    if (x < a[x]) a[x] = x;
  }
  int s = 0;
  for (int i = 0; i < N; i++) s += f[i];
  printf("%d\n", s);
  for (int i = 0; i < N; i++)
    if (f[i]) printf("%d ", i);
  puts("");
  return 0;
}
