#include <bits/stdc++.h>
using namespace std;
int n, x, g, w, num, now, p[1000100], s[1000100], b[1000100];
pair<int, int> a[1000100];
int main() {
  for (int i = 1; i <= 8191; ++i) p[i] = 10000000;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  now = 1;
  while (now <= n) {
    w = 1;
    g = a[now].first;
    b[w] = a[now].second;
    now++;
    while (now <= n && a[now].first == g) b[++w] = a[now].second, now++;
    p[g] = min(p[g], b[1]);
    for (int i = 1; i <= 8191; ++i)
      if (p[i] < b[w])
        p[i ^ g] = min(p[i ^ g], b[lower_bound(b + 1, b + 1 + w, p[i]) - b]);
  }
  for (int i = 1; i <= 8191; ++i)
    if (p[i] <= 1000000) num++;
  printf("%d\n0", num + 1);
  for (int i = 1; i <= 8191; ++i)
    if (p[i] <= 1000000) printf(" %d", i);
  return 0;
}
