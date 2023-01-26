#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, a[N], res;
int ans[N][N];
void make(int cur, int t) {
  res = max(res, t);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (((i - 1) / cur) != ((j - 1) / cur) &&
          ((i - 1) / cur / k) == ((j - 1) / cur / k))
        ans[i][j] = t;
  if ((n - 1) / (cur * k) > 0) make(cur * k, t + 1);
}
int main() {
  cin >> n >> k;
  make(1, 1);
  printf("%d\n", res);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", ans[i][j]);
  return 0;
}
