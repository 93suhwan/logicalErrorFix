#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> a[N];
int sum;
int yw(int x, int fa) {
  int cc = 0;
  for (auto i : a[x]) {
    if (i != fa) cc += yw(i, x);
  }
  if (cc) {
    sum += cc - 1;
    return 0;
  }
  return 1;
}
int main() {
  int t, n, u, v;
  scanf("%d", &t);
  while (t--) {
    sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &u, &v);
      a[u].push_back(v);
      a[v].push_back(u);
    }
    yw(1, 0);
    printf("%d\n", sum + 1);
  }
  return 0;
}
