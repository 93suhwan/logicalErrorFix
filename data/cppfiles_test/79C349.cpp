#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
inline int read() {
  char ch = getchar();
  int s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0', ch = getchar();
  }
  return s * w;
}
const int N = 1e6 + 9;
char s[N];
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    scanf("%s", s);
    int flag = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        flag = 1;
        printf("1\n");
        printf("%c\n", s[i]);
        break;
      }
    }
    if (flag == 1)
      continue;
    else {
      if (k == 2 && (strcmp(s, "23") == 0 || strcmp(s, "37") == 0 ||
                     strcmp(s, "53") == 0 || strcmp(s, "73") == 0 ||
                     strcmp(s, "2") == 0 || strcmp(s, "3") == 0 ||
                     strcmp(s, "5") == 0 || strcmp(s, "7") == 0)) {
        printf("-1\n");
      } else {
        printf("%d\n", 2);
        int f = 0;
        for (int i = 0; i < k; i++) {
          if (f == 1) break;
          for (int j = i + 1; j < k; j++) {
            if (!((s[i] == '2' && s[j] == '3') ||
                  (s[i] == '3' && s[j] == '7') ||
                  (s[i] == '5' && s[j] == '3') ||
                  (s[i] == '7' && s[j] == '3'))) {
              printf("%c%c\n", s[i], s[j]);
              f = 1;
              break;
            }
          }
        }
      }
    }
  }
  return 0;
}
