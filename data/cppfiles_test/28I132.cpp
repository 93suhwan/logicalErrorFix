#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int cha = 0;
    if (c % 2) {
      cha = 3;
    }
    if (b % 2) {
      if (cha == 3) {
        cha = 1;
      } else {
        cha = 2;
      }
    }
    if (a % 2) {
      if (cha == 1) {
        cha = 0;
      } else if (cha == 2) {
        cha = 1;
      } else if (cha == 0) {
        cha = 1;
      } else {
        if (a > 1) {
          cha = 0;
        } else {
          cha--;
        }
      }
    } else {
      if (cha == 2) {
        cha = 0;
      } else if (cha == 1 || cha == 3) {
        cha = 1;
      }
    }
    printf("%d\n", cha);
  }
}
