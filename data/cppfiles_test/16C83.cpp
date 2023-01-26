#include <bits/stdc++.h>
int main() {
  int t, n, i, j, permutation;
  char s_original[41], s_sort[41];
  char key;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s_original);
    strcpy(s_sort, s_original);
    for (i = 1; i < n; i++) {
      key = s_sort[i];
      for (j = i - 1; j >= 0 && s_sort[j] > key; j--) {
        s_sort[j + 1] = s_sort[j];
      }
      s_sort[j + 1] = key;
    }
    for (permutation = 0, i = 0; i < n; i++) {
      if (s_original[i] == s_sort[i])
        continue;
      else {
        permutation++;
      }
    }
    printf("%d\n", permutation);
  }
  return 0;
}
