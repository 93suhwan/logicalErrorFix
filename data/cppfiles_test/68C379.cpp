#include <bits/stdc++.h>
int main() {
  int tc;
  scanf("%d", &tc);
  for (int a = 0; a < tc; a++) {
    int numb;
    scanf("%d", &numb);
    int i = 1;
    int ii = 3;
    int counteri = 1;
    while (i < numb) {
      i += ii;
      ii += 2;
      counteri++;
    }
    int check;
    check = (i - counteri + 1 < numb) ? 1 : 0;
    int counterj;
    int j;
    if (i - counteri + 1 == numb) {
      printf("%d %d\n", counteri, counteri);
    } else if (check == 1) {
      j = i;
      counterj = 1;
      while (j != numb) {
        j -= 1;
        counterj++;
      }
      printf("%d %d\n", counteri, counterj);
    } else if (check == 0) {
      j = i - counteri + 1;
      counterj = counteri;
      while (j != numb) {
        j -= 1;
        counterj--;
      }
      printf("%d %d\n", counterj, counteri);
    }
  }
  return 0;
}
