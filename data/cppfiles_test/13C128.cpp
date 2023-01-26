#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i <= t; i++) {
    char arr[50];
    gets(arr);
    int d = 0;
    d = strlen(arr);
    int a = 0, b = 0, c = 0;
    for (int j = 0; j < d; j++) {
      if (arr[j] == 'A') {
        a++;
      } else if (arr[j] == 'B') {
        b++;
      } else if (arr[j] == 'C') {
        c++;
      }
    }
    int e = a + c;
    if (e == 0 && b == 0) {
    } else if (e == b) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
