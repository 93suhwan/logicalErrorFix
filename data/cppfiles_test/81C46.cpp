#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, pair<int, int>>;
pii p[500007];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i != n; i++)
    scanf("%d%d", &p[i].second.first, &p[i].second.second);
  for (int i = 0; i != n; i++)
    p[i].first = max(p[i].second.second, p[i].second.first);
  sort(p, p + n);
  int ans = 0;
  for (int i = 0; i != n; i++)
    if (d <= p[i].second.first) ans++, d = max(d, p[i].second.second);
  printf("%d", ans);
  return 0;
}
