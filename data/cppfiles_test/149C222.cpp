#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar(), fl = 1;
  while (ch > '9' || ch < '0') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  long long p = 0;
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * fl;
}
char ch[2005];
long long len[2005], ans[2005];
int main() {
  int T = read();
  while (T--) {
    long long n = read(), k = read(), x = read() - 1;
    scanf("%s", ch + 1);
    int l = strlen(ch + 1), cnt = 0, num = 0;
    for (int i = 1; i <= l + 1; ++i) {
      if (ch[i] == '*') num++;
      if (ch[i] != '*' && ch[i - 1] == '*') {
        len[++cnt] = k * num + 1;
        num = 0;
      }
    }
    for (int i = cnt; i >= 1; --i) {
      ans[i] = x % len[i];
      x /= len[i];
    }
    num = 1;
    for (int i = 1; i <= n; ++i) {
      if (ch[i] == 'a')
        putchar('a');
      else {
        while (ch[i] == '*') i++;
        --i;
        for (int j = 1; j <= ans[num]; ++j) putchar('b');
        num++;
      }
    }
    putchar('\n');
  }
  return 0;
}
