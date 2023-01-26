#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N];
int n, m;
int par[N], pos[N], sz[N];
int pa(int x) {
  if (par[x] == x) return x;
  return par[x] = pa(par[x]);
}
void join(int x, int y) {
  if (pa(x) == pa(y)) return;
  int tmp1 = pa(x);
  int tmp2 = pa(y);
  par[tmp1] = tmp2;
  sz[tmp2] += sz[tmp1];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      join(i, pos[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (pa(i) == i) {
        if (sz[i] % 2 == 0) {
          ++cnt;
        }
      }
    }
    if (cnt % 2 == 0) {
      printf("Yes\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
