#include <bits/stdc++.h>
using namespace std;
int t;
char str[350000];
int q;
int add[350000];
int main() {
  scanf("%d", &t);
  while (t--) {
    int len;
    scanf("%d%d", &len, &q);
    scanf("%s", str);
    memset(add, 0, sizeof(add));
    for (int i = 0; i < len; i++) {
      if ((str[i] == '+' && i % 2 == 0) || (str[i] == '-' && i % 2 == 1))
        add[i + 1] = add[i] + 1;
      else
        add[i + 1] = add[i];
    }
    int l, r;
    while (q--) {
      scanf("%d%d", &l, &r);
      int num = add[r] - add[l - 1];
      if (abs(num * 2) == (r - l + 1))
        printf("0\n");
      else if ((l - r + 1 - 2 * num) % 2 == 0)
        printf("2\n");
      else
        printf("1\n");
    }
  }
}
