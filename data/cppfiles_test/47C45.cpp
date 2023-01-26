#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 7;
struct NUM {
  int bit[33];
  int val;
} a[MAXN];
bool cmp(NUM x, NUM y) { return y.val > x.val; }
int main() {
  int n, k;
  cin >> n >> k;
  NUM yu12, yu23, yu13, or12, or23, or13, yu123, or123;
  printf("and 1 2\n");
  fflush(stdout);
  cin >> yu12.val;
  printf("and 2 3\n");
  fflush(stdout);
  cin >> yu23.val;
  printf("and 1 3\n");
  fflush(stdout);
  cin >> yu13.val;
  yu123.val = yu12.val & yu13.val;
  printf("or 1 2\n");
  fflush(stdout);
  cin >> or12.val;
  printf("or 2 3\n");
  fflush(stdout);
  cin >> or23.val;
  or123.val = or12.val | or23.val;
  for (int j = 0; j < 30; j++) {
    int tp = 1 << j;
    if (or123.val & tp) {
      if (yu123.val & tp) {
        a[1].val += tp;
        a[2].val += tp;
        a[3].val += tp;
      } else {
        if ((yu12.val & tp) || (yu23.val & tp) || (yu13.val & tp)) {
          if (yu12.val & tp) {
            a[1].val += tp;
            a[2].val += tp;
          }
          if (yu23.val & tp) {
            a[2].val += tp;
            a[3].val += tp;
          }
          if (yu13.val & tp) {
            a[1].val += tp;
            a[3].val += tp;
          }
        } else {
          if ((or12.val & tp) && (or23.val & tp)) {
            a[2].val += tp;
          } else if (or12.val & tp) {
            a[1].val += tp;
          } else {
            a[3].val += tp;
          }
        }
      }
    }
  }
  for (int i = 4; i <= n; i++) {
    printf("and 1 %d\n", i);
    fflush(stdout);
    cin >> yu12.val;
    printf("or 1 %d\n", i);
    fflush(stdout);
    cin >> or12.val;
    for (int j = 0; j < 30; j++) {
      int tp = 1 << j;
      if (a[1].val & tp) {
        if (yu12.val & tp) {
          a[i].val += tp;
        }
      } else {
        if (or12.val & tp) {
          a[i].val += tp;
        }
      }
    }
  }
  sort(a + 1, a + n + 1, cmp);
  printf("finish %d\n", a[k].val);
  fflush(stdout);
  return 0;
}
