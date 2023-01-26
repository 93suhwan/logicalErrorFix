#include <bits/stdc++.h>
using namespace std;
int T, col;
string s;
void mov(int x, int y) {
  printf("%d %d\n", x, y);
  col = y;
  cin >> s;
}
int scan(int row) {
  for (int c = (col == 1 ? 2 : 1); c <= 8; ++c) {
    mov(row, c);
    if (s == "Done") return true;
    if (s == "Down") return false;
    if (s == "Up") return scan(row);
  }
  return false;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    col = 1;
    for (int row = 1; row <= 7; row++) {
      mov(row, col);
      if (col != 1) {
        if (s == "Done") break;
        col = 1;
        mov(row, col);
      }
      if (s == "Done") break;
      if (scan(row)) break;
    }
  }
  return 0;
}
