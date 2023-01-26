#include <bits/stdc++.h>
using namespace std;
int T, num;
inline int read() {
  int ans = 0, sym = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sym = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ans = ans * 10 + ch - '0';
    ch = getchar();
  }
  return ans * sym;
}
int main() {
  T = read();
  while (T--) {
    num = read();
    printf("2 %d\n", num - 1);
  }
  return 0;
}
