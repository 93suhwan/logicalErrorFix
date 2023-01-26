#include <bits/stdc++.h>
char a[200001], b[200001];
int main() {
  int T;
  scanf("%d", &T);
  int n;
  while (T--) {
    scanf("%d", &n);
    scanf("%s", &b);
    scanf("%s", &a);
    int cont = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        if (b[i] == '0')
          cont++;
        else if (i - 1 >= 0 && b[i - 1] == '1') {
          b[i - 1] = '2';
          cont++;
        } else if (i + 1 < n && b[i + 1] == '1') {
          b[i + 1] = '2';
          cont++;
        }
      }
    }
    printf("%d\n", cont);
  }
  return 0;
}
