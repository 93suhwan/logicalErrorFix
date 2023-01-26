#include <bits/stdc++.h>
using namespace std;
int T, N;
bool ex[((int)1e6 + 10)];
int tv[10];
int v[10];
int reg[((int)1e6 + 10)];
int reginx = 0;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    bool dup = false;
    for (int i = 0; i < N; i++) {
      scanf("%d", v + i);
      if (v[i] == 0) dup = true;
      if (v[i] < 0) v[i] = -v[i];
    }
    sort(v, v + N);
    for (int i = 1; i < N && !dup; i++)
      if (v[i] == v[i - 1]) dup = true;
    if (dup) {
      printf("YES\n");
      continue;
    }
    bool ok = false;
    fill(ex, ex + ((int)1e6 + 10), false);
    reginx = 0;
    reg[reginx++] = v[0];
    ex[v[0]] = true;
    for (int i = 1; i < N && !ok; i++) {
      int val = v[i];
      int rsize = reginx;
      for (int k = 0; k < rsize; k++) {
        int newval = val + reg[k];
        if (ex[newval]) {
          ok = true;
          break;
        } else {
          reg[reginx++] = newval;
          ex[newval] = true;
        }
      }
      if (ex[val]) {
        ok = true;
        break;
      } else {
        reg[reginx++] = val;
        ex[val] = true;
      }
    }
    if (ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
