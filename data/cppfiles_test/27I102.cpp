#include <bits/stdc++.h>
using namespace std;
int readint() {
  int rt = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    rt = (rt << 1) + (rt << 3) + ch - '0';
    ch = getchar();
  }
  return rt * f;
}
long long readll() {
  long long rt = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    rt = (rt << 1) + (rt << 3) + ch - '0';
    ch = getchar();
  }
  return rt * f;
}
int q;
const int maxn = 1e5 + 5;
char s[maxn], t[maxn];
bool flag = 0;
int len1, len2;
void input() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  flag = 0;
}
void solve() {
  len1 = strlen(s + 1);
  len2 = strlen(t + 1);
  if (len1 < len2) {
    flag = 0;
    return;
  }
  for (int i = 1; i <= len1; i++) {
    if (s[i] == t[1] && (i & 1)) {
      int pos = 2;
      int j = i + 1;
      bool f = 1;
      while (1) {
        while (s[j] != t[pos] && j <= len1 && pos <= len2) j += 2;
        if (j > len1) {
          f = 0;
          break;
        }
        pos++;
        j++;
        if (pos > len2) {
          f = 1;
          break;
        }
      }
      if (f) {
        flag = 1;
        return;
      }
    }
  }
  for (int i = 1; i <= len1; i++) {
    if (s[i] == t[1] && !(i & 1)) {
      int pos = 2;
      int j = i + 1;
      bool f = 1;
      while (1) {
        while (pos <= len2 && j <= len1 && s[j] != t[pos]) j += 2;
        if (j > len1) {
          f = 0;
          break;
        }
        pos++;
        j++;
        if (pos > len2) {
          f = 1;
          break;
        }
      }
      if (f) {
        flag = 1;
        return;
      }
    }
  }
}
void output() {
  if (flag) {
    puts("YES");
  } else {
    puts("NO");
  }
}
int main() {
  q = readint();
  while (q--) {
    input();
    solve();
    output();
  }
  return 0;
}
