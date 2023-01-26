#include <bits/stdc++.h>
using namespace std;
int T, row, col;
string s;
int main() {
  scanf("%d", &T);
  while (T--) {
    row = col = 1;
    puts("1 1");
    fflush(stdout);
    for (; row <= 8;) {
      cin >> s;
      if (s == "Done") break;
      bool flag = false;
      if (s != "Down") {
        flag = true;
        for (col = 2; col <= 8; ++col) {
          printf("%d %d\n", row, col);
          fflush(stdout);
          cin >> s;
          if (s == "Done") break;
          if (s == "Down") break;
        }
      }
      if (s == "Done") break;
      row++;
      if (flag) col--;
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
