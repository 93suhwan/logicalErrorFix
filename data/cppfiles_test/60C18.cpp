#include <bits/stdc++.h>
using namespace std;
int t, n, b, r;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    scanf("%d", &r);
    for (int j = 1; j < n; j++) {
      scanf("%d", &b);
      r = r & b;
    }
    printf("%d\n", r);
  }
  return 0;
}
