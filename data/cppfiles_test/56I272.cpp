#include <bits/stdc++.h>
using namespace std;
char s[15];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int dy = -1;
    bool done = false;
    for (int x = 1; x < 9; x++)
      if (!done) {
        dy *= -1;
        for (int y = (dy == 1 ? 1 : 8); y > 0 && y < 9; y += dy) {
          printf("%d %d\n", x, y);
          fflush(stdout);
          scanf("%s", s);
          if (s[0] == 'D' && s[2] == 'n') {
            done = true;
            break;
          }
        }
      }
  }
}
