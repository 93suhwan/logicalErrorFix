#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int yes = 0, no = 0;
  char B[4][n];
  int k = 0;
  for (int i = 0; i < n; i++) {
    int A[3];
    for (int i = 0; i < 3; i++) scanf("%d", &A[i]);
    if ((A[0] == A[1] + A[2] || A[1] == A[0] + A[2] || A[2] == A[0] + A[1]) ||
        (((A[0] == A[1]) && A[2] % 2 == 0) ||
         ((A[1] == A[2]) && A[3] % 2 == 0) ||
         ((A[0] == A[2]) && A[1] % 2 == 0)))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
