#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010];
pair<int, int> p[200010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    p[i] = make_pair(a[i], a[i] - i - 1);
  }
  sort(p, p + n);
  int l = 1;
  b[0] = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second > 0) continue;
    int x = upper_bound(b, b + l, -p[i].second) - b;
    if (x == l) l++;
    b[x] = -p[i].second;
  }
  printf("%d\n", l - 1);
  return 0;
}
