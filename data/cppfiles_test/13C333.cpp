#include <bits/stdc++.h>
using namespace std;
char str[1000];
int main() {
  int t, n, i, a, b;
  cin >> t;
  while (t--) {
    scanf("%s", str);
    a = b = 0;
    for (i = 0; str[i] != '\0'; i++) {
      if (str[i] == 'B')
        b++;
      else
        a++;
    }
    if (a == b)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
