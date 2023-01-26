#include <bits/stdc++.h>
using namespace std;
int t;
char a[101];
int main() {
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    int ans = 0;
    for (int i = 0; a[i]; ++i) {
      ans += a[i] - '0';
      if (a[i + 1] && a[i] != '0') ans++;
    }
    printf("%d\n", ans);
  }
}
