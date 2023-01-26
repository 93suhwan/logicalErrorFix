#include <bits/stdc++.h>
using namespace std;
int n, m, s, l;
int a[202020];
string st;
bool cmp(int x, int y) { return x > y; }
int main() {
  cin >> n;
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  cin >> st;
  st = " " + st;
  m = 1;
  for (register int i = 2; i <= n; ++i) {
    if (st[i] == st[i - 1]) ++m;
  }
  sort(a + 1, a + m + 1, cmp);
  sort(a + m + 1, a + n + 1, cmp);
  m = 1;
  s = n;
  l = (st[1] == 'L' ? 1 : 0);
  printf("%d %c\n", a[m++], st[1]);
  for (register int i = 2; i <= n; ++i) {
    if (st[i] != st[i - 1]) {
      printf("%d %c\n", a[s--], st[i]);
      continue;
    }
    l = 1 - l;
    printf("%d %c\n", a[m++], (l ? 'L' : 'R'));
  }
  return 0;
}
