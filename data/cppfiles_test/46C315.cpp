#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int last = a[n], res = 0;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] > last) {
        res++;
        last = a[i];
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
