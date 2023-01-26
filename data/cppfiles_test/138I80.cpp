#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
struct node {
  long long first, id;
  bool operator<(const node &p) const { return first < p.first; }
} a[N];
long long c[N];
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
  val[second] += val[first];
  for (long long i = 0; i < v[first].size(); i++) {
    v[second].push_back(v[first][i]);
    vv[second].push_back(vv[second][vv[second].size() - 1] + v[first][i]);
  }
  if (val[second]) sum += vv[second][val[second] - 1];
  v[first].clear();
  vv[first].clear();
}
long long tree[N * 4], lazy[N * 4];
void push_down(long long s, long long t, long long p) {
  tree[p * 2] = lazy[p];
  tree[p * 2 + 1] = lazy[p];
  lazy[p * 2] = lazy[p];
  lazy[p * 2 + 1] = lazy[p];
  lazy[p] = 0;
}
void update(long long s, long long t, long long p, long long first,
            long long k) {
  if (s >= first) {
    tree[p] = max(tree[p], k);
    lazy[p] = max(lazy[p], k);
    return;
  }
  long long mid = s + t >> 1;
  if (lazy[p]) {
    push_down(s, t, p);
  }
  if (mid >= first) update(s, mid, p * 2, first, k);
  if (t >= first) update(mid + 1, t, p * 2 + 1, first, k);
}
long long query(long long s, long long t, long long p, long long first) {
  if (s == first && t == first) return tree[p];
  long long mid = s + t >> 1;
  if (lazy[p]) {
    push_down(s, t, p);
  }
  if (mid >= first) return query(s, mid, p * 2, first);
  if (mid < first) return query(mid + 1, t, p * 2 + 1, first);
  return 0;
}
signed main() {
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].id = i;
  for (long long i = 1; i <= m; i++)
    scanf("%d", &a[n + i].first), a[n + i].id = n + i;
  for (long long i = 1; i <= q; i++) {
    scanf("%d", &c[i]);
  }
  sort(a + 1, a + n + m + 1, cmp);
  for (long long i = 1; i <= n + m; i++) {
    fa[i] = i;
    v[i].push_back(a[i].first);
    vv[i].push_back(a[i].first);
    if (a[i].id <= n) val[i] = 1, sum += a[i].first;
    d[i] = {a[i].first - a[i + 1].first, i, i + 1};
  }
  sort(d + 1, d + n + m);
  update(0, n + m, 1, 0, sum);
  for (long long i = 1; i <= n + m - 1; i++) {
    long long j = i;
    if (get(d[i].id1) != get(d[i].id2)) merge(get(d[i].id1), get(d[i].id2));
    while (d[j + 1].first == d[i].first && j + 1 <= n + m - 1) {
      ++j;
      if (get(d[j].id1) != get(d[j].id2)) merge(get(d[j].id1), get(d[j].id2));
    }
    update(0, n + m, 1, d[i].first, sum);
    i = j;
  }
  for (long long i = 1; i <= q; i++) {
    printf("%d\n", query(0, n + m, 1, c[i]));
  }
  return 0;
}
