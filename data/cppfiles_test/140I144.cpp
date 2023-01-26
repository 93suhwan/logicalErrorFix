#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  int A[a];
  for (int i = 0; i < a; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < a; ++i) {
    int l, m;
    int K = 0;
    l = (int)(sqrtf(A[i]));
    m = (int)(cbrtf(A[i]));
    int z = 0;
    if (l * l > m * m * m) {
      z = (int)cbrtf(m * m);
    }
    if (l * l < m * m * m) {
      z = (int)cbrtf(l);
    }
    K = (l + m - z);
    printf("%d\n", K);
  }
  return 0;
}
