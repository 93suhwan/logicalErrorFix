#include <bits/stdc++.h>
using namespace std;
int out[200001];
int n, mm, q;
string s1, s2;
int main() {
  int t, n;
  scanf("%d%d", &n, &mm);
  for (int i = 1; i <= mm; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    out[x]++;
  }
  scanf("%d", &q);
  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (out[i]) ans--;
  }
  while (q--) {
    int sta, x, y;
    scanf("%d", &sta);
    if (sta == 1) {
      scanf("%d%d", &x, &y);
      if (x > y) swap(x, y);
      out[x]++;
      if (out[x] == 1) {
        ans--;
      }
    } else if (sta == 2) {
      scanf("%d%d", &x, &y);
      if (x > y) swap(x, y);
      out[x]--;
      if (out[x] == 0) {
        ans++;
      }
    } else {
      printf("%d\n", ans);
    }
  }
}
