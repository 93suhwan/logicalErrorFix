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
    l = (int)(sqrtl(A[i]));
    m = (int)(cbrtl(A[i]));
    int z = 0;
    if (sqrtl(A[i]) * sqrtl(A[i]) > cbrtl(A[i]) * cbrtl(A[i]) * cbrtl(A[i])) {
      z = (int)cbrtl(cbrtl(A[i]) * cbrtl(A[i]));
    } else {
      z = (int)cbrtl(sqrtl(A[i]));
    }
    K = (l + m - z);
    printf("%d\n", K);
  }
  return 0;
}
