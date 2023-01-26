#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  int t;
  printf("? %d %d\n", x, y), fflush(stdout);
  cin >> t;
  return t;
}
int midx, midy;
int main() {
  midy = (query(1, 1) - query(1, 1e9) + 1e9 + 1) / 2,
  midx = (query(1, 1) - query(1e9, 1) + 1e9 + 1) / 2,
  printf("! %d %d %d %d\n", query(1, midy) + 1, query(midx, 1) + 1,
         1e9 - query(1e9, midy), 1e9 - query(midx, 1e9)),
  fflush(stdout);
  return 0;
}
