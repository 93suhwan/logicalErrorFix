#include <bits/stdc++.h>
using namespace std;
int N, A, B;
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &N, &A, &B);
    if (abs(A - B) > 1) {
      printf("-1\n");
      continue;
    }
    if (A * 2 + 1 > N || B * 2 + 1 > N || A + B > N - 2) {
      printf("-1\n");
      continue;
    }
    if (A >= B) {
      for (int i = 0; i < A; i++) {
        printf("%d %d ", i + 1, N - i);
      }
      if (A == B) {
        for (int i = A + 1; i < N - A + 1; i++) {
          printf("%d%c", i, " \n"[i == N - A]);
        }
      } else {
        for (int i = N - A; i > A; i--) {
          printf("%d%c", i, " \n"[i == A + 1]);
        }
      }
    } else {
      for (int i = 0; i < B; i++) {
        printf("%d %d ", N - i, i + 1);
      }
      for (int i = B + 1; i < N - B + 1; i++) {
        printf("%d%c", i, " \n"[i == N - B]);
      }
    }
  }
  return 0;
}
