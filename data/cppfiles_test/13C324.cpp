#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    int a = 0, b = 0, c = 0;
    char d[55];
    gets(d);
    for (int i = 0; i < strlen(d); i++) {
      if (d[i] == 'A')
        a++;
      else if (d[i] == 'B')
        b++;
      else if (d[i] == 'C')
        c++;
    }
    if (b == a + c)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
