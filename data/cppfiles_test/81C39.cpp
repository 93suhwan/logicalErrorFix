#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, d;
pair<int, int> a[N];
inline bool cmp(pair<int, int> x, pair<int, int> y) {
  if (max(x.first, x.second) == max(y.first, y.second))
    return x.first < y.first;
  return max(x.first, x.second) < max(y.first, y.second);
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + 1 + n, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].first >= d) ans++, d = max(d, a[i].second);
  printf("%d", ans);
  return 0;
}
