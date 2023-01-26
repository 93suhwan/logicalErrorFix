#include <bits/stdc++.h>
const int N = 2e5 + 10;
using namespace std;
long long ne[N], Length[N], query[N];
vector<pair<long long, long long> > qs, seg;
pair<long long, long long> a[N];
long long st[N], sum[N], ans;
int n, m, q;
long long Find(long long x) {
  if (ne[x] == x)
    return x;
  else
    ne[x] = Find(ne[x]);
  return ne[x];
}
void Merge(long long a, long long b) {
  long long L = a - Length[Find(a)], R = a + Length[Find(b)];
  long long l1 = a - (st[a] - st[L]), r1 = a;
  long long r2 = R, l2 = r2 - (st[r2] - st[a]);
  ans -= sum[r2] - sum[l2] + sum[r1] - sum[l1];
  Length[Find(b)] = Length[Find(a)] + Length[Find(b)];
  ne[Find(a)] = ne[Find(b)];
  ans += sum[r2] - sum[r2 - st[r2] + st[L]];
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    a[i] = {x, 1};
    ans += x;
  }
  for (int i = n + 1; i <= n + m; i++) {
    long long x;
    cin >> x;
    a[i] = {x, 0};
  }
  sort(a + 1, a + n + m + 1);
  for (int i = 2; i <= n + m; i++) {
    if (a[i].first - a[i - 1].first > 0)
      seg.push_back({a[i].first - a[i - 1].first, (long long)i - 1});
  }
  sort(seg.begin(), seg.end());
  for (int i = 1; i <= n + m; i++) {
    st[i] = st[i - 1] + a[i].second;
    sum[i] = sum[i - 1] + a[i].first;
  }
  for (int i = 1; i <= q; i++) {
    long long x;
    scanf("%lld", &x);
    qs.push_back({x, i});
  }
  sort(qs.begin(), qs.end());
  int p = 0;
  for (int i = 1; i <= n + m; i++) ne[i] = (long long)i;
  for (int i = 1; i <= n + m; i++) Length[i] = 1;
  long long las = -1;
  for (auto t : qs) {
    long long i = t.first;
    if (i == las) {
      query[t.second] = ans;
      continue;
    }
    las = i;
    while (p < seg.size() && seg[p].first <= i) {
      Merge(seg[p].second, seg[p].second + 1);
      p++;
    }
    query[t.second] = ans;
    if (p >= seg.size()) break;
  }
  for (int i = 1; i <= q; i++) {
    cout << query[i] << endl;
  }
}
