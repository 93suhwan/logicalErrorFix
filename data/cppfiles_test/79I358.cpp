#include <bits/stdc++.h>
using namespace std;
void input() {
  int k;
  string n;
  scanf("%d", &k);
  cin >> n;
  int seven = 0, three = 0;
  for (int i = 0; i < k; i++) {
    if (n[i] == '7') seven++;
    if (n[i] == '3') three++;
    if (seven == 2) {
      printf("%d\n", 2);
      printf("%d\n", 77);
      break;
    }
    if (three == 2) {
      printf("%d\n", 2);
      printf("%d\n", 33);
      break;
    }
    if (n[i] != '2' and n[i] != '3' and n[i] != '5' and n[i] != '7' and
        n[i] != '1') {
      printf("%d\n", 1);
      printf("%c\n", n[i]);
      break;
    } else if ((n[i] == '2' or n[i] == '5') and i > 0) {
      printf("%d\n", 2);
      printf("%c%c\n", n[i - 1], n[i]);
      break;
    } else if ((n[0] == '2' or n[0] == '5' or n[0] == '7') and n[i] == '7' and
               i > 0) {
      printf("%d\n", 2);
      printf("%c%c\n", n[0], n[i]);
      break;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) input();
  return 0;
}
