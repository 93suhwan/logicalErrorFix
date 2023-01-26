#include <bits/stdc++.h>
int main() {
  float modi;
  scanf("%f", &modi);
  for (int ktr = modi; ktr > 0; ktr--) {
    int z;
    float milk = 0;
    int silk = 0;
    scanf("%d", &z);
    int rrr[z];
    for (int i = z - 1; i >= 0; i--) {
      scanf("%d", &rrr[i]);
      milk = milk + rrr[i];
    }
    milk = milk - 100;
    silk = milk + 200;
    if ((silk - 100) % z == 0) {
      printf("0\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}
