#include <bits/stdc++.h>
using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int num;
    scanf("%d", &num);
    if (num % 2 == 0) {
      printf("%d %d %d\n", num / 2, num / 2 - 1, 1);
      continue;
    }
    for (const int& p : prime)
      if ((num - 1) % p) {
        printf("%d %d %d\n", p, num - 1 - p, 1);
        break;
      }
  }
}
