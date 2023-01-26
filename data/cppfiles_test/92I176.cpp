#include <bits/stdc++.h>
using namespace std;
char ch[114];
int val[114];
int main() {
  int t, sum;
  scanf("%d", &t);
  while (t--) {
    sum = 0;
    memset(val, 0, sizeof(val));
    scanf("%s", ch);
    int len = strlen(ch);
    for (int i = 0; i < len - 1; i++) {
      if (ch[i] == 'a' && ch[i + 1] == 'b') {
        val[i]++;
        val[i + 1]++;
      } else if (ch[i] == 'b' && ch[i + 1] == 'a') {
        val[i]--;
        val[i + 1]--;
      }
      sum += val[i];
    }
    sum += val[len - 1];
    sum = sum / 2;
    if (!sum)
      printf("%s\n", ch);
    else {
      int fir = len + 1, las = len + 1;
      for (int i = 0; i < len; i++) {
        if (val[i]) {
          fir = i;
          break;
        }
      }
      for (int i = len - 1; i >= 0; i--) {
        if (val[i]) {
          las = i;
          break;
        }
      }
      if (sum == 1) {
        if (fir + 1 < len - las) {
          for (int i = 0; i <= fir; i++) ch[i] = 'b';
        } else {
          for (int i = len - 1; i >= las; i--) ch[i] = 'a';
        }
      } else if (sum == -1) {
        if (fir + 1 < len - las) {
          for (int i = 0; i <= fir; i++) ch[i] = 'a';
        } else {
          for (int i = len - 1; i >= las; i--) ch[i] = 'b';
        }
      }
      printf("%s\n", ch);
    }
  }
  return 0;
}
