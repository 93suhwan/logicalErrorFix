#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N];
char str[N];
int b[N];
int c[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1), _t = (n); i <= _t; ++i) scanf("%d", &a[i]);
  scanf("%s", str + 1);
  sort(a + 1, a + n + 1);
  for (int i = (1), _t = (n); i <= _t; ++i) {
    if (str[i] != str[i - 1]) {
      b[i] = 1;
    }
  }
  int l = 1, r = n;
  for (int i = (n), _t = (1); i >= _t; --i) {
    if (b[i] == 1)
      c[i] = a[r--];
    else
      c[i] = a[l++];
  }
  int c1 = 0, c2 = 0;
  for (int i = (1), _t = (n); i <= _t; ++i) {
    if (str[i] == 'L') {
      if (c1 <= c2) {
        ++c1;
        printf("%d L\n", c[i]);
      } else {
        ++c2;
        printf("%d R\n", c[i]);
      }
    } else {
      if (c1 >= c2) {
        ++c2;
        printf("%d R\n", c[i]);
      } else {
        ++c1;
        printf("%d L\n", c[i]);
      }
    }
  }
  return 0;
}
