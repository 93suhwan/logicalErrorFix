#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, q, fa[N];
ll ans[N];
pair<int, int> Q[N], a[N * 2];
int find(int x) { return fa[x] <= 0 ? x : fa[x] = find(fa[x]); }
int main() {
  cin >> n >> m >> q;
  ll sum = 0;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i].first);
    sum += a[i].first, a[i].second = 1;
  }
  for (int i = (n + 1); i <= (n + m); i++) scanf("%d", &a[i].first);
  for (int i = (1); i <= (q); i++) scanf("%d", &Q[i].first), Q[i].second = i;
  sort(a + 1, a + n + m + 1), sort(Q + 1, Q + q + 1);
  vector<pair<int, int>> ord;
  for (int i = (1); i <= (n + m); i++) {
    fa[i] = a[i].second - i;
    if (i > 1) ord.emplace_back(a[i].first - a[i - 1].first, i);
  }
  sort(ord.begin(), ord.end());
  int j = 1;
  for (auto [d, i] : ord) {
    while (j <= q && Q[j].first < d) ans[j++] = sum;
    int x = find(i--);
    while (-fa[i] < i && -fa[x] > i)
      sum += a[-fa[x]++].first - a[- --fa[i]].first;
    if (-fa[i] < i) fa[x] = fa[i];
    fa[i] = x;
  }
  for (int i = (1); i <= (q); i++) printf("%lld\n", ans[i]);
}
