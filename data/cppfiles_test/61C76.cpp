#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int mod = 1e9 + 7;
char s[maxn];
int t[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int fir = -1;
    for (int i = 1; i <= n; i++) {
      if (s[i] != '?') {
        fir = i;
        break;
      }
    }
    if (fir == -1) {
      for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
          printf("B");
        } else {
          printf("R");
        }
      }
      puts("");
      continue;
    }
    for (int i = fir - 1; i > 0; i--) {
      if (s[i] == '?') {
        if (s[i + 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    }
    for (int i = fir + 1; i <= n; i++) {
      if (s[i] == '?') {
        if (s[i - 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%c", s[i]);
    }
    puts("");
  }
  return 0;
}
