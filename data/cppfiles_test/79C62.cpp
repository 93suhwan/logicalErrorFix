#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], b[N], lst[N], dis[N];
vector<int> vec;
inline void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int X;
  for (int i = n, j = n - 1; i; --i) {
    X = i + b[i];
    while (j >= X - a[X]) {
      dis[j] = dis[i] + 1;
      lst[j] = i;
      --j;
    }
    if (j == i - 1) {
      puts("-1");
      return;
    }
  }
  int u = 0;
  while (u != n) {
    vec.push_back(u);
    u = lst[u];
  }
  reverse(vec.begin(), vec.end());
  printf("%d\n", dis[0]);
  for (int v : vec) {
    printf("%d ", v);
  }
}
int main() {
  init();
  return 0;
}
