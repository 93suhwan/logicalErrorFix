#include <bits/stdc++.h>
int v[100000];
int ord[100000];
static inline int fgetint() {
  int n = 0, ch;
  while (!isdigit(ch = fgetc(stdin)))
    ;
  do n = n * 10 + ch - '0';
  while (isdigit(ch = fgetc(stdin)));
  return n;
}
void myqsort(int begin, int end) {
  int b = begin - 1, e = end + 1, p = v[ord[(begin + end) / 2]], aux;
  while (v[ord[++b]] < p)
    ;
  while (v[ord[--e]] > p)
    ;
  while (b < e) {
    aux = ord[b];
    ord[b] = ord[e];
    ord[e] = aux;
    while (v[ord[++b]] < p)
      ;
    while (v[ord[--e]] > p)
      ;
  }
  if (begin < e) myqsort(begin, e);
  if (e + 1 < end) myqsort(e + 1, end);
}
int main() {
  int t, n, i, K, k;
  for (t = fgetint(); t--;) {
    n = fgetint();
    K = fgetint();
    for (i = 0; i < n; i++) {
      v[i] = fgetint();
      ord[i] = i;
    }
    myqsort(0, n - 1);
    k = 1;
    for (i = 1; i < n; i++)
      if (ord[i] != (ord[i - 1] + 1)) k++;
    if (k > K)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
