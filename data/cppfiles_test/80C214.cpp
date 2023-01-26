#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
char s[N + 9];
int n;
void into() { scanf("%d%s", &n, s + 1); }
void work() {
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') continue;
    i << 1 <= n ? printf("%d %d %d %d\n", i, n, i + 1, n)
                : printf("%d %d %d %d\n", 1, i, 1, i - 1);
    return;
  }
  printf("%d %d %d %d\n", 1, n - 1, 2, n);
}
void outo() {}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
