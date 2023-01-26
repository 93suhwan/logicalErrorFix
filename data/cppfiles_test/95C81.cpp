#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s, n;
    scanf("%d %d", &s, &n);
    s = s - n;
    for (int i = 0; i < n - 1; ++i) {
      int num = 1;
      while (10 * num - 1 <= s) {
        num *= 10;
      }
      s -= (num - 1);
      printf("%d ", num);
    }
    printf("%d\n", s + 1);
  }
  return 0;
}
