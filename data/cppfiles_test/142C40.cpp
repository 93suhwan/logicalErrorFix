#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = (int)1e5 + 5;
int _ = 1;
vector<int> p[N];
int n, m, ans;
int num[N];
void work() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) num[i] = 0;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    p[i].resize(n + 5);
    p[i][0] = 0;
    for (int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
  }
  ans = 0;
  if (m <= n - 1) {
    int l = 1, r = (int)1e9;
    while (l <= r) {
      int mid = l + r >> 1;
      int flag = 1;
      for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 1; j <= m; j++) num += (p[j][i] < mid);
        if (num == m) {
          flag = 0;
          break;
        }
      }
      if (flag)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
  } else {
    int l = 1, r = (int)1e9;
    while (l <= r) {
      int mid = l + r >> 1;
      int flag = 1;
      for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 1; j <= m; j++) num += (p[j][i] < mid);
        if (num == m) {
          flag = 0;
          break;
        }
      }
      if (!flag) {
        r = mid - 1;
        continue;
      }
      flag = 0;
      int num1 = 0, num2 = 0;
      for (int i = 1; i <= m; i++) {
        int num = 0;
        for (int j = 1; j <= n; j++) num += (p[i][j] >= mid);
        if (num >= 2) {
          flag = 1;
          break;
        }
      }
      if (flag)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &_);
  while (_--) {
    work();
  }
  return 0;
}
