#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> a[N];
int ok[N];
int can(int x) {
  for (int i = 0; i < n; i++) ok[i] = 0;
  int okk = 0;
  for (int i = 0; i < m; i++) {
    int co = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] >= x) {
        co++;
        ok[j] = 1;
      }
    }
    okk |= co > 1;
  }
  for (int i = 0; i < n; i++) okk &= ok[i];
  return okk;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
      a[i] = vector<int>(n);
      for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    }
    int st = 0, en = 1e9, ans = 0;
    while (st <= en) {
      int mid = (st + en) >> 1;
      if (can(mid)) {
        ans = mid;
        st = mid + 1;
      } else
        en = mid - 1;
    }
    printf("%d\n", ans);
  }
}
