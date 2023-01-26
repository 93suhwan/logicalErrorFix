#include <bits/stdc++.h>
using namespace std;
char a[100];
int n, m;
int main() {
  scanf("%d", &n);
  while (n--) {
    memset(a, 0, sizeof(a));
    scanf("%s", a);
    m = strlen(a);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < m; i++) {
      if (a[i] == 'A')
        cnt1++;
      else if (a[i] == 'B')
        cnt2++;
      else if (a[i] == 'C')
        cnt3++;
    }
    if (m == (cnt2 + cnt3) || m == (cnt2 + cnt1) || cnt2 == (cnt3 + cnt1))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
