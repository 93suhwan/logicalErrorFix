#include <bits/stdc++.h>
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    std::vector<int> dadada(7);
    for (int i = 0; i < 7; ++i) {
      scanf("%d", &dadada[i]);
    }
    printf("%d %d %d\n", dadada[0], dadada[1],
           dadada[6] - dadada[1] - dadada[0]);
  }
  return 0;
}
