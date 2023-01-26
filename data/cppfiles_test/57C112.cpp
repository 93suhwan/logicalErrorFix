#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int a[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  vector<int> ans;
  for (int i = n; i >= 3; i -= 2) {
    for (int j = 1; j <= i; ++j) {
      if (a[j] == i) {
        if (j & 1) {
          reverse(a + 1, a + j + 1);
          ans.push_back(j);
          break;
        } else {
          printf("-1\n");
          return;
        }
      }
    }
    for (int j = 1; j <= i; ++j) {
      if (a[j] == i - 1) {
        if (~j & 1) {
          reverse(a + 1, a + j);
          ans.push_back(j - 1);
          break;
        } else {
          printf("-1\n");
          return;
        }
      }
    }
    reverse(a + 1, a + i + 1);
    ans.push_back(i);
    for (int j = 1; j <= i; ++j) {
      if (a[j] == i) {
        reverse(a + 1, a + j + 1);
        ans.push_back(j);
        break;
      }
    }
    reverse(a + 1, a + i + 1);
    ans.push_back(i);
  }
  int sz = ans.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) {
    printf("%d%c", ans[i], i < sz - 1 ? ' ' : '\n');
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
