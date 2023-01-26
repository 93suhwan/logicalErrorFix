#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn], C[maxn];
map<int, int> yinshe, chuxian;
int lowerbit(int x) { return x & (-x); }
int getsum(int x) {
  int ans = 0;
  while (x > 0) {
    ans += C[x];
    x -= lowerbit(x);
  }
  return ans;
}
void add(int id, int val) {
  while (id <= n) {
    C[id] += val;
    id += lowerbit(id);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    yinshe.clear();
    chuxian.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    if (n <= 2) {
      printf("0\n");
      continue;
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
      C[i] = 0;
      if (i > 1 && b[i] == b[i - 1])
        continue;
      else
        yinshe[b[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int u = yinshe[a[i]];
      add(u, 1);
      int p = getsum(u);
      int dayuta = i - p;
      int xiaoyuta;
      if (chuxian.count(u)) {
        xiaoyuta = p - 1 - chuxian[u];
        chuxian[u]++;
      } else {
        xiaoyuta = p - 1;
        chuxian[u] = 1;
      }
      ans += min(xiaoyuta, dayuta);
    }
    printf("%d\n", ans);
  }
  return 0;
}
