#include <bits/stdc++.h>
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    std::vector<int> dadada(7);
    for (int i = 0; i < 7; ++i) {
      scanf("%d", &dadada[i]);
    }
    printf("%d %d ", dadada[0], dadada[1]);
    int sum = dadada[0] + dadada[1];
    int i = 2;
    while (sum == dadada[i]) {
      ++i;
    }
    printf("%d\n", dadada[i]);
  }
  return 0;
}
