#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) swap(a, b);
    int jenis = b - a;
    bool bisa = 1;
    if (!(a <= jenis && jenis < b)) bisa = 0;
    if (c > jenis * 2) bisa = 0;
    if (bisa) {
      if (c > jenis)
        printf("%d\n", c - jenis);
      else
        printf("%d\n", c + jenis);
    } else {
      puts("-1");
    }
  }
  return 0;
}
