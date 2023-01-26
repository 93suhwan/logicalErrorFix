#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N];
int n;
int par[N], sz[N];
vector<int> pos[N];
int pa(int x) {
  if (par[x] == x) return x;
  return par[x] = pa(par[x]);
}
void join(int x, int y) {
  int tmp1 = pa(x);
  int tmp2 = pa(y);
  if (tmp1 == tmp2) return;
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
    bool l = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      pos[a[i]].push_back(i);
      if (pos[a[i]].size() > 1) {
        l = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (auto it : pos[i]) join(i, it);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (pa(i) == i) {
        if (sz[i] % 2 == 0) {
          ++cnt;
        }
      }
    }
    if (cnt % 2 == 0 || l) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
