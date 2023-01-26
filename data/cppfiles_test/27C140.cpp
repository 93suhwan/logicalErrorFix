#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int nxt[maxn][26];
char s[maxn], t[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    for (int i = (0); i < (26); ++i) nxt[n][i] = nxt[n + 1][i] = n;
    for (int i = n - 1; i >= 0; --i) {
      for (int x = (0); x < (26); ++x) nxt[i][x] = nxt[i + 1][x];
      int x = s[i] - 'a';
      nxt[i][x] = i;
    }
    int c = 0;
    int ok = 0;
    int len = strlen(t);
    c = 0;
    int p = -1;
    for (int i = 0; i < len; ++i) {
      int x = t[i] - 'a';
      p = nxt[p + 1][x];
      while (p < n && (p & 1) != c) p = nxt[p + 1][x];
      if (p >= n) break;
      c ^= 1;
    }
    if (p < n && (n - 1 - p) % 2 == 0) ok = 1;
    c = 1;
    p = -1;
    for (int i = 0; i < len; ++i) {
      int x = t[i] - 'a';
      p = nxt[p + 1][x];
      while (p < n && (p & 1) != c) p = nxt[p + 1][x];
      if (p >= n) break;
      c ^= 1;
    }
    if (p < n && (n - 1 - p) % 2 == 0) ok = 1;
    if (ok)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
