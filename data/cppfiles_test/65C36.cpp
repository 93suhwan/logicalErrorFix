#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
const int N = 1e6 + 10;
int n, a[N], ans[N];
char s[N], t[N];
char re(char c) {
  if (c == 'L') return 'R';
  return 'L';
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  scanf("%s", s + 1);
  sort(a + 1, a + n + 1);
  int l = 1, r = n, flag = n & 1;
  for (int i = n; i > 1; i--) {
    if (s[i - 1] == s[i]) {
      t[i] = flag ? s[i] : re(s[i]);
      flag ^= 1;
      ans[i] = a[l++];
    } else {
      ans[i] = a[r--];
      flag ^= 1;
      t[i] = s[i];
    }
  }
  ans[1] = a[l];
  t[1] = s[1];
  for (int i = 1; i <= n; i++) printf("%d %c\n", ans[i], t[i]);
  return 0;
}
