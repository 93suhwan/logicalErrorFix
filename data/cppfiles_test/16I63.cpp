#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int t, n, i, permutation;
  int s_original[41], s_sort[41];
  char ch;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0, scanf("%c", &ch); i < n; i++) {
      scanf("%c", &ch);
      s_sort[i] = s_original[i] = ch;
    }
    qsort(s_sort, n, sizeof(int), cmpfunc);
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
