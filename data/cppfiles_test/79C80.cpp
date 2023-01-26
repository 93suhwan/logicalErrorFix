#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, c, d, e, f, j, k, g, h;
  int a[300005], b;
  cin >> n;
  vector<int> trip(n + 5, 0);
  vector<int> jump(n + 5, 0);
  vector<int> flag(n + 5, 0);
  vector<int> ans;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &b);
    flag[i] = i + b;
  }
  for (i = n, j = n - 1; i >= 1; i--) {
    c = flag[i];
    while (j >= c - a[c]) {
      jump[j] = jump[i] + 1;
      trip[j] = i;
      j--;
    }
    if (i == j + 1) {
      printf("-1\n");
      return 0;
    }
  }
  c = 0;
  while (c != n) {
    ans.push_back(c);
    c = trip[c];
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", jump[0]);
  for (int x : ans) {
    printf("%d ", x);
  }
  printf("\n");
}
