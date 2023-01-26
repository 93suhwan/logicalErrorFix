#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    int A[20] = {0}, B[20] = {0};
    int La = 0, Lb = 0;
    while (n) {
      A[La++] = n % 10;
      n /= 10;
    }
    while (m) {
      B[Lb++] = m % 10;
      m /= 10;
    }
    int C[20] = {0}, Lc = 0;
    n = La, m = Lb;
    La = Lb = 0;
    while (Lb < m) {
      if (B[Lb] >= A[La]) {
        C[Lc++] = B[Lb] - A[La];
        Lb++;
        La++;
      } else {
        if (B[Lb + 1] != 1) {
          Lc = -1;
          break;
        }
        C[Lc++] = B[Lb] - A[La] + 10;
        Lb += 2;
        La++;
      }
    }
    if (Lc == -1 || La < n)
      printf("-1\n");
    else {
      int I = 0;
      for (int i = Lc - 1; i >= 0; i--) {
        if (C[i] != 0) I = 1;
        if (I == 0) continue;
        printf("%d", C[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
