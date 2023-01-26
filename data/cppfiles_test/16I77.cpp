#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  char a[50];
  scanf("%d %s", &n, a);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i] > a[j]) {
        cnt++;
        break;
      }
    }
  }
  if (cnt == 0)
    printf("0\n");
  else
    printf("%d\n", cnt + 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
