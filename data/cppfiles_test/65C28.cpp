#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, a1[N], l, r, cnt;
char str[N], ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a1[i]);
  sort(a1 + 1, a1 + n + 1);
  scanf("%s", str + 1);
  cnt = 0;
  str[0] = 'A';
  for (int i = 1; i <= n; ++i)
    if (str[i] != str[i - 1]) ++cnt;
  l = r = n - cnt + 1;
  for (int i = 1; i <= n; ++i) {
    if (str[i - 1] != str[i]) {
      printf("%d %c\n", a1[r], str[i]);
      ans[r] = str[i];
      ++r;
    } else {
      char ch;
      if (ans[l] == 'L')
        ch = 'R';
      else
        ch = 'L';
      --l;
      printf("%d %c\n", a1[l], ch);
      ans[l] = ch;
    }
  }
  return 0;
}
