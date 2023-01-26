#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long Num = 0, F = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') F = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    Num = (Num << 1) + (Num << 3) + (ch ^ 48);
    ch = getchar();
  }
  return Num * F;
}
char s[20010];
int n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '0') {
        if (i > n / 2) {
          printf("1 %d 1 %d\n", i, i - 1);
          break;
        } else {
          printf("%d %d %d %d\n", i, n, i + 1, n);
          break;
        }
      } else if (i == n)
        printf("1 %d 2 %d\n", n - 1, n);
    }
  }
  return 0;
}
