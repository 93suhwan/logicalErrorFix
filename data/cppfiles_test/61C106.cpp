#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
inline int read() {
  int d = 0, f = 0, c = getchar();
  for (; c < 48 || c > 57; c = getchar()) f |= (c == '-');
  for (; c > 47 && c < 58; c = getchar()) d = (d << 1) + (d << 3) + (c ^ 48);
  return f ? -d : d;
}
char get(int k, char c) { return (k & 1) ? 148 - c : c; }
int main() {
  t = read();
  for (int i; t; t--) {
    n = read();
    cin >> s;
    for (i = 0; i < n && s[i] == '?'; i++)
      ;
    if (i == n)
      for (int j = 0; j < n; j++) putchar((j & 1) ? 'B' : 'R');
    else {
      for (int j = 0; j <= i; j++) putchar(get(i - j, s[i]));
      for (int k = i, j = i + 1; j < n; j++) {
        if (s[j] != '?')
          putchar(s[j]), k = j;
        else
          putchar(get(j - k, s[k]));
      }
    }
    puts("");
  }
  return 0;
}
