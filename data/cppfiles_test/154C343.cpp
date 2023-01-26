#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] == a[2])
      printf("YES\n");
    else if (a[0] == a[1] && a[2] % 2 == 0)
      printf("YES\n");
    else if (a[0] == a[2] && a[1] % 2 == 0)
      printf("YES\n");
    else if (a[2] == a[1] && a[0] % 2 == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
