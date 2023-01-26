#include <inttypes.h>
#include <stdio.h>

void print(char c, int n) {
  while (n--) putchar(c);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    long long x;
    scanf("%d%d%"PRId64"", &n, &k, &x);
    char s[n+1];
    scanf("%s", s);
    int pattern[2001] = {}, len = -1;
    char p = '\0';
    for (int i = 0; ; i++) {
      if (s[i] != p) len++;
      if (s[i] == '\0') break;
      if (s[i] == 'a') pattern[len]--;
      else if (s[i] == '*') pattern[len] += k;
      p = s[i];
    }

    long long count[2001] = {};
    for (int i = len-1; i >= 0 && x > 0; i--) {
      if (pattern[i] < 0) continue;
      count[i] = x % (pattern[i]+1);
      x /= (pattern[i]+1);
    }
    for (int i = 0; i < len; i++) {
      if (pattern[i] < 0) print('a', -pattern[i]);
      else print('b', (count[i]+pattern[i]) % (pattern[i]+1));
    }
    putchar('\n');
  }

  return 0;
}
