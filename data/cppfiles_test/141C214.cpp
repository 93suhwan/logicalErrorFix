#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
char a[MAX], b[MAX], s[MAX];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s%s", a, s);
    int al = strlen(a);
    int sl = strlen(s);
    int i, j;
    int bl = MAX - 1;
    for (i = al - 1, j = sl - 1; i >= 0 && j >= 0;) {
      int ax = a[i] - '0';
      int sx = s[j] - '0';
      if (sx >= ax) {
        b[bl] = sx - ax + '0';
      } else {
        j--;
        if (j < 0) {
          break;
        }
        sx = sx + (s[j] - '0') * 10;
        b[bl] = sx - ax + '0';
      }
      i--;
      j--;
      bl--;
    }
    bool ok = true;
    if (i >= 0) {
      ok = false;
    }
    for (int k = j; k >= 0; k--, bl--) {
      b[bl] = s[k];
    }
    for (int k = bl + 1; k < MAX; k++) {
      if (b[k] < '0' || b[k] > '9') {
        ok = false;
        break;
      }
    }
    if (!ok) {
      printf("-1\n");
    } else {
      bl++;
      while (bl < MAX && b[bl] == '0') {
        bl++;
      }
      for (int k = bl; k < MAX; k++) {
        printf("%c", b[k]);
      }
      printf("\n");
    }
  }
  return 0;
}
