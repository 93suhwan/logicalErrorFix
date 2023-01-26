#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
char str[N];
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  for (int j = 0; j < n; j++) {
    scanf("%s", &str);
    int a = 0, b = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == 'E')
        a++;
      else
        ++b;
    }
    if (a && b == 1)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
