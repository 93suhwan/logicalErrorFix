#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int w = 1, c = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) c = (c << 1) + (c << 3) + (ch ^ 48);
  return w * c;
}
const int M = 1e6 + 10;
vector<int> c[M];
int s[M], n, m;
char t[M];
int main() {
  n = read();
  m = read();
  for (int i = (1); i <= (n); ++i) {
    c[i].resize(m + 2);
    scanf("%s", t + 1);
    for (int j = (1); j <= (m); ++j) {
      if (t[j] == 'X') {
        if (i > 1 && j < m && c[i - 1][j + 1]) s[j]++;
        c[i][j] = 1;
      }
    }
  }
  for (int i = (1); i <= (m); ++i) s[i] += s[i - 1];
  int Q = read();
  while (Q--) {
    int l = read(), r = read();
    if (s[r - 1] - s[l - 1])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
