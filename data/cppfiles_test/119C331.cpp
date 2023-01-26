#include <bits/stdc++.h>
int main() {
  int modi;
  scanf("%d", &modi);
  for (int ktr = modi; ktr > 0; ktr--) {
    int z;
    long long int milk = 0;
    int silk = 0;
    scanf("%d", &z);
    int rrr[z];
    for (int i = z - 1; i >= 0; i--) {
      scanf("%d", &rrr[i]);
      milk = milk + rrr[i];
    }
    milk = milk - 200;
    if ((milk + 200) % z == 0) {
      printf("0\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}
