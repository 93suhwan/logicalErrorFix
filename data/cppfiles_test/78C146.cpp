#include <bits/stdc++.h>
using namespace std;
int T, a, b;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", b - max(a, b / 2 + 1));
  }
  return 0;
}
