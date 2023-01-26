#include <bits/stdc++.h>
using namespace std;
int T;
char a[110], b[110];
bool flag;
int ls, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    flag = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        flag = false;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
