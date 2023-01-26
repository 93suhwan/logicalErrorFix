#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 10;
int cnt[505][505];
int x[Maxn], y[Maxn], s[Maxn];
int tmp;
int d[Maxn];
void update(int now, int k, int val) {
  int bl = x[k] + y[k];
  int l = (now + x[k]) % bl;
  int r = (now + x[k] + y[k] - 1) % bl;
  if (l <= r)
    for (int i = l; i <= r; i++) cnt[bl][i] += val;
  else {
    for (int i = 0; i <= r; i++) cnt[bl][i] += val;
    for (int i = l; i < bl; i++) cnt[bl][i] += val;
  }
  return;
}
int query(int t) {
  int res = 0;
  for (int i = 2; i <= tmp; i++) res += cnt[i][t % i];
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  tmp = ceil(sqrt(m));
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int op, k;
    scanf("%d %d", &op, &k);
    if (op == 1) {
      if (x[k] + y[k] > tmp) {
        for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
          d[j]++;
          if (j + y[k] <= m) d[j + y[k]]--;
        }
      } else
        update(i, k, 1);
      s[k] = i;
    } else {
      if (x[k] + y[k] > tmp) {
        for (int j = s[k] + x[k]; j <= m; j += x[k] + y[k]) {
          d[j]--;
          if (j + y[k] <= m) d[j + y[k]]++;
          if (i > j && i <= j + y[k]) ans--;
        }
      } else
        update(s[k], k, -1);
    }
    ans += d[i];
    printf("%d\n", ans + query(i));
  }
}
