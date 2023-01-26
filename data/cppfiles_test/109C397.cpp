#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int num;
  while (t--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%1d", &num);
      if (i == n)
        cnt += num;
      else if (num)
        cnt += num + 1;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
