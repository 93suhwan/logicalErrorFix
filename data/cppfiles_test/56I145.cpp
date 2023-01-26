#include <bits/stdc++.h>
using namespace std;
int T, row, col;
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
    puts("1 1");
    fflush(stdout);
    for (int row = 1; row <= 8;) {
      mov(row, col);
      if (s == "Done") break;
      if (scan(row)) break;
      row++;
      printf("%d %d\n", row, col);
      fflush(stdout);
      if (col != 1) {
        cin >> s;
        if (s == "Done") break;
        col = 1;
        printf("%d %d\n", row, col);
        fflush(stdout);
      }
    }
  }
  return 0;
}
