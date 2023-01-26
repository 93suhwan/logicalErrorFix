#include <bits/stdc++.h>
using namespace std;
int n;
int num;
char c;
char str[int(3 * 10e5 + 1)];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %c", &num, &c);
    scanf("%s", str);
    int a = 0;
    bool have_first = false, have_secend = false;
    for (int j = 0; j < num; ++j) {
      if (str[j] != c) {
        if (!have_first) {
          have_first = true;
        } else if (!have_secend) {
          have_secend = true;
        }
        a = j;
      }
    }
    printf("%d\n", have_first + have_secend);
    if (have_secend) {
      printf("%d %d\n", a + 1, a);
    } else if (have_first) {
      if (a == 0 || a == 1)
        printf("3\n");
      else
        printf("%d\n", a);
    }
  }
  return 0;
}
