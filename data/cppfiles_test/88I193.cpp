#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    if (n % 2 == 0)
      puts("YES");
    else {
      int flag = 0;
      for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) flag = 1;
      }
      if (flag)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
