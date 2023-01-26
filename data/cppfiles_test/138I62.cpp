#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
struct node {
  long long first, id, ans;
  bool operator<(const node &p) const { return first < p.first; }
} a[N], c[N];
struct ndd {
  long long first, id1, id2;
  bool operator<(const ndd &p) const { return first < p.first; }
} d[N];
bool cmp(node a, node b) { return a.first > b.first; }
vector<long long> v[N], vv[N];
long long fa[N], val[N];
long long get(long long first) {
  if (fa[first] == first) return first;
  return fa[first] = get(fa[first]);
}
long long sum = 0;
void merge(long long first, long long second) {
  if (first < second) swap(first, second);
  fa[first] = second;
  if (val[first]) sum -= vv[first][val[first] - 1];
  if (val[second]) sum -= vv[second][val[second] - 1];
  if (val[second] >= val[first]) {
    val[second] += val[first];
    for (long long i = 0; i < v[first].size(); i++) {
      v[second].push_back(v[first][i]);
      vv[second].push_back(vv[second][vv[second].size() - 1] + v[first][i]);
    }
    if (val[second]) sum += vv[second][val[second] - 1];
    v[first].clear();
    vv[first].clear();
  } else {
    val[first] += val[second];
    for (long long i = 0; i < v[first].size(); i++) {
      v[second].push_back(v[first][i]);
      vv[second].push_back(vv[second][vv[second].size() - 1] + v[first][i]);
    }
    v[first].clear();
    vv[first].clear();
    for (long long i = 0; i < v[second].size(); i++) {
      v[first].push_back(v[second][i]);
      vv[first].push_back(vv[second][i]);
    }
    if (val[first]) sum += vv[first][val[first] - 1];
    v[second].clear();
    vv[second].clear();
  }
}
long long ans[N];
bool cmp2(node a, node b) { return a.id < b.id; }
signed main() {
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i].first), a[i].id = i;
  for (long long i = 1; i <= m; i++)
    scanf("%lld", &a[n + i].first), a[n + i].id = n + i;
  for (long long i = 1; i <= q; i++) {
    scanf("%lld", &c[i]);
    c[i].id = i;
  }
  sort(c + 1, c + q + 1);
  sort(a + 1, a + n + m + 1, cmp);
  for (long long i = 1; i <= n + m; i++) {
    fa[i] = i;
    v[i].push_back(a[i].first);
    vv[i].push_back(a[i].first);
    if (a[i].id <= n) val[i] = 1, sum += a[i].first;
    d[i] = {a[i].first - a[i + 1].first, i, i + 1};
  }
  sort(d + 1, d + n + m);
  long long g = 1;
  c[0].ans = sum;
  for (long long i = 1; i <= n + m - 1; i++) {
    long long j = i;
    if (get(d[i].id1) != get(d[i].id2)) merge(get(d[i].id1), get(d[i].id2));
    while (d[j + 1].first == d[i].first && j + 1 <= n + m - 1) {
      ++j;
      if (get(d[j].id1) != get(d[j].id2)) merge(get(d[j].id1), get(d[j].id2));
    }
    while (c[g].first < d[i].first && g <= q) ++g;
    if (c[g].first >= d[i].first) c[g].ans = sum;
    i = j;
  }
  for (long long i = 1; i <= q; i++) {
    c[i].ans = max(c[i].ans, c[i - 1].ans);
  }
  sort(c + 1, c + q + 1, cmp2);
  for (long long i = 1; i <= q; i++) {
    printf("%lld\n", c[i].ans);
  }
  return 0;
}
