#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a[200005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0, x = (n / 2);
    sort(a, a + n);
    for (int i = 1; i <= x; i++) {
      cout << a[i] << " " << a[0] << "\n";
    }
  }
  return 0;
}
