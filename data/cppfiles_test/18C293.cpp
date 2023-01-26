#include <bits/stdc++.h>
using namespace std;
int t, n, k, x[205];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    fill(x + 1, x + n * 2 + 1, 0);
    for (int i = 0; i < k; i++) {
      int ta, tb;
      scanf("%d%d", &ta, &tb);
      x[ta] = tb;
      x[tb] = ta;
    }
    vector<int> v;
    for (int i = 1; i <= n * 2; i++)
      if (!x[i]) {
        v.push_back(i);
        x[i] = -(int)v.size();
      }
    for (int i = 1; i <= n * 2; i++)
      if (x[i] < 0) x[i] = v[(-x[i] - 1 + v.size() / 2) % v.size()];
    int ans = 0;
    for (int i = 1; i <= n * 2; i++)
      if (i < x[i])
        for (int j = i + 1; j <= n * 2; j++)
          if (j < x[j]) ans += j < x[i] && x[i] < x[j];
    printf("%d\n", ans);
  }
}
