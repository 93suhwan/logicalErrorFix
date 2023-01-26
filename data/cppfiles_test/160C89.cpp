#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, rd, cd, rb, cb, _, dr, dc;
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);
    int res = 0;
    dr = dc = 1;
    while (rb != rd && cd != cb) {
      if (rb + dr > n || rb + dr < 1) dr = 0 - dr;
      if (cb + dc > m || cb + dc < 1) dc = 0 - dc;
      rb += dr;
      cb += dc;
      res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
