#include <bits/stdc++.h>
using namespace std;
char c[300000], d[300000];
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%s", c);
    scanf("%s", d);
    long long n = strlen(c);
    long long m = strlen(d);
    bool bl = 0;
    long long cnt = 0;
    long long mark = 0;
    bool ji = 1, ou = 1;
    for (int i = 0; i < n; i++) {
      if (c[i] == d[0] && (ji || ou)) {
        cnt = 0;
        if (i % 2 == 0) {
          ji = 0;
        } else {
          ou = 0;
        }
        cnt++;
        mark = i;
        while (1) {
          bool bb = 0;
          if (c[mark + 1] == d[cnt]) {
            mark++;
            cnt++;
            bb = 1;
          } else {
            for (int i = mark + 3; i < n; i += 2) {
              if (c[i] == d[cnt]) {
                cnt++;
                mark = i;
                bb = 1;
                break;
              }
            }
          }
          if (bb == 0) {
            break;
          }
          if (cnt == m) {
            bl = 1;
            break;
          }
          if (mark > n) {
            break;
          }
        }
      }
      if (ji == 0 && ou == 0) {
        break;
      }
    }
    if (bl == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
