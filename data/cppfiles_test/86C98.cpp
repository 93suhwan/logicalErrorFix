#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') f = -1;
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * f;
}
const int N = 2e5 + 5;
int n;
char s[N], t[N];
bool mt[N];
int val[500][500];
int main() {
  int T = read();
  val['0']['0'] = 1, val['0']['1'] = val['1']['0'] = 2;
  while (T--) {
    n = read();
    scanf("%s", s), scanf("%s", t);
    int ans = 0;
    for (int i = 0; i < n; ++i) mt[i] = 0;
    for (int i = 0; i < n; ++i) {
      if (!i)
        ans += val[s[i]][t[i]];
      else if (val[s[i]][t[i]] == 2)
        ans += 2;
      else {
        if (val[s[i]][t[i]] == 1) {
          if (val[s[i - 1]][t[i - 1]] == 0 && !mt[i - 1])
            ans += 2, mt[i] = 1;
          else
            ans += 1;
        } else {
          if (val[s[i - 1]][t[i - 1]] == 1 && !mt[i - 1]) ++ans, mt[i] = 1;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
