#include <bits/stdc++.h>
using namespace std;
int t, n, i, nr, a[2025], poz[2025], b[10004];
bool ok;
void rev(int x) {
  int i;
  if (x == 1) return;
  b[++nr] = x;
  for (i = 1; i <= (x / 2); i++) {
    swap(a[i], a[x - i + 1]);
    swap(poz[a[i]], poz[a[x - i + 1]]);
  }
}
int main() {
  scanf("%d", &t);
  while (t > 0) {
    scanf("%d", &n);
    ok = true;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (((a[i] - i) % 2) != 0) ok = false;
      poz[a[i]] = i;
    }
    nr = 0;
    if (ok == true) {
      for (i = 1; i < n; i += 2) {
        rev(poz[i]);
        rev(poz[i + 1] - 1);
        rev(poz[i + 1] + 1);
        rev(3);
        rev(n - i + 1);
      }
      rev(n);
      printf("%d\n", nr);
      for (i = 1; i <= nr; i++) printf("%d ", b[i]);
      printf("\n");
    } else
      printf("%d\n", -1);
    t--;
  }
  return 0;
}
