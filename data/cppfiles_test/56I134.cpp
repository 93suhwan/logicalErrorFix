#include <bits/stdc++.h>
using namespace std;
char Mot[20];
long long Get() {
  scanf("%s", Mot);
  long long sz = strlen(Mot);
  if (sz == 4 && Mot[2] == 'n') return -1;
  if (sz >= 4 && Mot[2] == 'w') return 0;
  if (sz >= 2 && Mot[0] == 'U') return 1;
  return 2;
}
void Read() {
  printf("1 2");
  cout << endl;
  for (long long i = 1; i < 8; i++) {
    long long ans = Get();
    long long col = 2;
    long long nb = 0;
    while (ans >= 1 && nb < 20) {
      if (ans == 1) {
        nb++;
        if (col <= 2)
          col = 3 ^ col;
        else
          col = 2;
      } else {
        if (col >= 7)
          break;
        else
          col += 2;
      }
      printf("%lld %lld", i, col);
      cout << endl;
      ans = Get();
    }
    if (ans < 0) return;
    printf("%lld %lld", i + 1, col);
    cout << endl;
    if (col != 2) {
      ans = Get();
      printf("%lld 2", i + 1);
      cout << endl;
    }
  }
  return;
}
signed main() {
  long long nbTests = 1;
  scanf("%lld", &nbTests);
  while (nbTests--) {
    Read();
  }
  return 0;
}
