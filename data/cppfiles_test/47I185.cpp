#include <bits/stdc++.h>
using namespace std;
const int N = 10111;
int n, K;
int AND[N], OR[N], XOR[N];
int a[N];
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 2; i <= n; i++) {
    printf("and %d %d\n", 1, i);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    AND[i] = x;
    printf("or %d %d\n", 1, i);
    fflush(stdout);
    scanf("%d", &x);
    OR[i] = x;
    XOR[i] = AND[i] ^ OR[i];
  }
  for (int i = 2; i <= n; i++) {
    a[1] |= AND[i];
  }
  printf("or %d %d\n", 2, 3);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  int XORSUM = 0x7fffffff;
  for (int i = 2; i <= n; i++) {
    XORSUM &= XOR[i];
  }
  for (int i = 0; i < 31; i++) {
    if (((XORSUM >> i) & 1) && (!((x >> i) & 1))) {
      a[i] |= 1 << i;
    }
  }
  for (int i = 2; i <= n; i++) a[i] = a[1] ^ XOR[i];
  sort(a + 1, a + n + 1);
  printf("finish %d\n", a[K]);
  fflush(stdout);
}
