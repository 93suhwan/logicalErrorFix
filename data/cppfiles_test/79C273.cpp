#include <bits/stdc++.h>
using namespace std;
int prime[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 63, 67, 71, 73, 79, 83, 89, 97};
char num[10009];
bool isprime(int x) {
  for (int i = 0; i < 25; ++i)
    if (x == prime[i]) return true;
  return false;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    scanf("%s", num);
    bool flag = 0;
    for (int i = 0; i < k; ++i) {
      num[i] -= '0';
      if (num[i] == 1 || num[i] == 4 || num[i] == 6 || num[i] == 8 ||
          num[i] == 9) {
        printf("1\n%d\n", num[i]);
        flag = 1;
        break;
      }
    }
    if (!flag) {
      for (int i = 0; !flag && i < k; ++i)
        for (int j = i + 1; !flag && j < k; ++j) {
          int a = num[i] * 10 + num[j];
          if (!isprime(a)) {
            printf("2\n%d\n", a);
            flag = 1;
            break;
          }
        }
    }
  }
  return 0;
}
