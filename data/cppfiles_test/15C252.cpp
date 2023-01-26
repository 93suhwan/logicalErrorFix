#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline int my_getchar() {
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if (s == e && e == 1048576) {
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if (s == e) {
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x) {
  int k;
  int m = 0;
  x = 0;
  for (;;) {
    k = my_getchar();
    if (k == '-') {
      m = 1;
      break;
    }
    if ('0' <= k && k <= '9') {
      x = k - '0';
      break;
    }
  }
  for (;;) {
    k = my_getchar();
    if (k < '0' || k > '9') {
      break;
    }
    x = x * 10 + k - '0';
  }
  if (m) {
    x = -x;
  }
}
inline void rd(char &c) {
  int i;
  for (;;) {
    i = my_getchar();
    if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) {
      break;
    }
  }
  c = i;
}
inline int rd(char c[]) {
  int i;
  int sz = 0;
  for (;;) {
    i = my_getchar();
    if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) {
      break;
    }
  }
  c[sz++] = i;
  for (;;) {
    i = my_getchar();
    if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) {
      break;
    }
    c[sz++] = i;
  }
  c[sz] = '\0';
  return sz;
}
inline int rd_int(void) {
  int x;
  rd(x);
  return x;
}
struct MY_WRITER {
  char buf[1048576];
  int s;
  int e;
  MY_WRITER() {
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER() {
    if (s) {
      fwrite(buf, 1, s, stdout);
    }
  }
};
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a) {
  if (MY_WRITER_VAR.s == MY_WRITER_VAR.e) {
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a) { my_putchar(a); }
inline void wt_L(const char c[]) {
  int i = 0;
  for (i = 0; c[i] != '\0'; i++) {
    my_putchar(c[i]);
  }
}
int n;
int m;
int k;
char a[110][110];
char target[110][110];
bool within(int x, int y) { return (0 <= x && x < n) && (0 <= y && y < m); }
int ticksize(int x, int y) {
  int i;
  for (i = (0); i < (2 * m); i++) {
    if (!within(x - i, y - i)) {
      return i - 1;
    }
    if (!within(x - i, y + i)) {
      return i - 1;
    }
    if (a[x - i][y - i] == '.') {
      return i - 1;
    }
    if (a[x - i][y + i] == '.') {
      return i - 1;
    }
  }
  return m;
}
void makeit(int x, int y, int tsz) {
  int i;
  for (i = (0); i < (tsz + 1); i++) {
    target[x - i][y - i] = '*';
    target[x - i][y + i] = '*';
  }
}
int main() {
  int djQeACzd;
  int Z8lEHcvz = rd_int();
  for (djQeACzd = (0); djQeACzd < (Z8lEHcvz); djQeACzd++) {
    int i;
    rd(n);
    rd(m);
    rd(k);
    for (i = (0); i < (n); i++) {
      rd(a[i]);
      a[i][m] = 0;
    }
    for (i = (0); i < (n + 1); i++) {
      int j;
      for (j = (0); j < (m + 1); j++) {
        target[i][j] = 0;
      }
    }
    for (i = (0); i < (n); i++) {
      int j;
      for (j = (0); j < (m); j++) {
        target[i][j] = '.';
      }
    }
    for (i = (0); i < (n); i++) {
      int j;
      for (j = (0); j < (m); j++) {
        if (!within(i - 1, j - 1) || !within(i - 1, j + 1)) {
          continue;
        }
        int tsz = ticksize(i, j);
        if (tsz < k) {
          continue;
        }
        makeit(i, j, tsz);
      }
    }
    bool good = true;
    for (i = (0); i < (n); i++) {
      string s1 = (string)a[i];
      string s2 = (string)target[i];
      if (s1 != s2) {
        good = false;
      }
    }
    if (good) {
      wt_L("YES");
      wt_L('\n');
    } else {
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
