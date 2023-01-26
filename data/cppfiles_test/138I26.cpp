#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 2e5 + 7;
long long sum[MAX_N];
long long a[MAX_N], b[MAX_N], ans[MAX_N];
long long n, m, q;
long long N = 0;
pair<long long, long long> qry[MAX_N];
struct Node {
  long long idx, val;
  Node(long long _idx = 0, long long _val = 0) : idx(_idx), val(_val) {}
  bool operator<(const Node &x) const { return val > x.val; }
};
priority_queue<Node> que;
map<long long, long long> out, in;
signed main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", a + i), sum[0] += a[i], ++in[a[i]];
  for (long long i = 1; i <= m; ++i) scanf("%lld", b + i), ++out[b[i]];
  for (long long i = 1; i <= n; ++i) {
    long long nxt = out.upper_bound(a[i])->first;
    que.push(Node(a[i], nxt - a[i]));
  }
  long long mx = 0;
  for (long long i = 1; i <= q; ++i) {
    scanf("%lld", &qry[i].first);
    mx = qry[i].first;
    qry[i].second = i;
  }
  sort(qry + 1, qry + q + 1);
  long long k = 0;
  while (!que.empty() && k <= mx) {
    Node p = que.top();
    que.pop();
    if (in[p.idx] && out[p.val + p.idx]) {
      --in[p.idx];
      ++in[p.val + p.idx];
      if (in[p.idx] == 0) in.erase(p.idx);
      ++out[p.idx];
      --out[p.idx + p.val];
      if (out[p.idx + p.val] == 0) out.erase((p.idx + p.val));
      if (in.lower_bound(p.idx) != in.begin()) {
        long long pre = (--in.lower_bound(p.idx))->first;
        que.push(Node(pre, p.idx - pre));
      }
      if (out.upper_bound(p.idx + p.val) != out.end()) {
        long long nxt = out.upper_bound(p.idx + p.val)->first;
        que.push(Node(p.val + p.idx, nxt - p.val - p.idx));
      }
      k = max(k, p.val);
      long long pos =
          lower_bound(qry + 1, qry + q + 1, pair<long long, long long>(k, 0)) -
          qry;
      if (pos <= q) sum[pos] += p.val;
    }
  }
  for (long long i = 1; i <= q; ++i) {
    sum[i] += sum[i - 1];
    ans[qry[i].second] = sum[i];
  }
  for (long long i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
