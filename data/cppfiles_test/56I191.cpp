#include <bits/stdc++.h>
using namespace std;
char Mot[20];
long long Get() {
  Mot[0] = Mot[2] = 'a';
  scanf("%s", Mot);
  if (Mot[2] == 'n') return -1;
  if (Mot[2] == 'w') return 0;
  if (Mot[0] == 'U') return 1;
  return 2;
}
void Read() {
  printf("1 2");
  cout << endl;
  long long nul = Get();
  printf("1 1");
  cout << endl;
  for (long long i = 1; i < 8; i++) {
    long long ans = Get();
    long long col = 1;
    while (ans >= 1) {
      if (ans == 1) {
        if (col == 1)
          col = 2;
        else
          col = 1;
      } else {
        if (col == 8)
          break;
        else
          col++;
      }
      printf("%lld %lld", i, col);
      cout << endl;
      ans = Get();
    }
    if (ans < 0) return;
    printf("%lld %lld", i + 1, col);
    cout << endl;
    if (col > 1) {
      ans = Get();
      if (ans < 0) return;
      printf("%lld 1", i + 1);
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
