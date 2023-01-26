#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s;
    scanf("%d%d", &n, &s);
    int m = s % n;
    if (m)
      printf("%d\n", s / n + m - 1);
    else
      printf("%d\n", s / n);
  }
}
