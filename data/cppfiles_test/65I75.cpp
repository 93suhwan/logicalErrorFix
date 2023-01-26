#include <bits/stdc++.h>
const int N = 2e5 + 7, mo = 1e9 + 7;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x;
}
int n, tol, w[N];
char s[N];
int main() {
  n = read();
  for (int i = 1; i <= n;
       w[i++] = read(), (i == n + 1) && (std::sort(w + 1, w + 1 + n),
                                         std::cin >> (s + 1), 0))
    ;
  for (int i = 1; i < n; tol += s[i] != s[i + 1], ++i)
    ;
  printf("%c %d\n", s[1], w[n - tol]);
  for (int l = n - tol, r = l, i = 2; i <= n;
       printf("%c %d\n",
              (s[i] == s[i - 1])
                  ? ((l - 1 & 1) ^ (n - tol & 1) ? (s[1] == 'L' ? 'R' : 'L')
                                                 : (s[1] == 'L' ? 'L' : 'R'))
                  : ((r + 1 & 1) ^ (n - tol & 1) ? (s[1] == 'L' ? 'R' : 'L')
                                                 : (s[1] == 'L' ? 'L' : 'R')),
              s[i] == s[i - 1] ? w[l - 1] : w[r + 1]),
           s[i] == s[i - 1] ? --l : ++r, ++i)
    ;
  return 0;
}
