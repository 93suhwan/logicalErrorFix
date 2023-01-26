#include <bits/stdc++.h>
using namespace std;
int B[7], BB[7];
int main() {
  int t, i, a1, a2, a3;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < 7; ++i) scanf("%d", &B[i]);
    a1 = BB[0] = B[0];
    a2 = BB[1] = B[1];
    a3 = BB[2] = B[2];
    BB[3] = a1 + a2;
    BB[4] = a1 + a3;
    BB[5] = a2 + a3;
    BB[6] = a1 + a2 + a3;
    sort(BB, BB + 7);
    for (i = 0; i < 7; ++i)
      if (B[i] != BB[i]) break;
    printf("%d %d %d\n", a1, a2, (i == 7) ? a3 : B[3]);
  }
  return 0;
}
