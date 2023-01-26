#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char a[2][105];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s%s", a[0], a[1]);
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[0][i] == '1' && a[1][i] == '1') {
        flag = false;
        break;
      }
    }
    if (flag) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
