#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", r % (max(l, r / 2 + 1)));
  }
  return 0;
}
