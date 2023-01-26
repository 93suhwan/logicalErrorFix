#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
int T, n;
char s[MAXN];
char a[66][66];
int stc[MAXN], sc = 0;
int read() {
  int s = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + ch - '0', ch = getchar();
  return f ? -s : s;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    cin >> s + 1;
    int x = 0, y = 0, z = 0;
    sc = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '2') {
        if (x && y && !z) z = i;
        if (x && !y) y = i;
        if (!x) x = i;
        stc[++sc] = i;
      }
    }
    if (!x && !y && !z) {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i != j)
            printf("=");
          else
            printf("X");
        }
        puts("");
      }
      continue;
    }
    if (x && !z) {
      puts("NO");
      continue;
    }
    if (x && y && z) {
      puts("YES");
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) a[i][j] = '=';
      for (int i = 1; i <= n; ++i) a[i][i] = 'X';
      stc[sc + 1] = stc[1];
      for (int i = 1; i <= sc; ++i) {
        a[stc[i]][stc[i + 1]] = '+';
        a[stc[i + 1]][stc[i]] = '-';
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          printf("%c", a[i][j]);
        }
        puts("");
      }
    }
  }
  return 0;
}
