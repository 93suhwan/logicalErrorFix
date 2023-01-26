#include <bits/stdc++.h>
using namespace std;
signed main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int k, Count = 0, number = 1;
    scanf("%d", &k);
    while (1) {
      if (number % 3 != 0 && number % 10 != 3) Count++;
      if (Count == k) break;
      number++;
    }
    printf("%d\n", number);
  }
  return 0;
}
