#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 7;
long long sum[MAX_N];
int a[MAX_N], b[MAX_N];
long long ans[MAX_N];
int n, m, q;
int N = 0;
std::pair<int, int> qry[MAX_N];
struct Node {
  int idx, val;
  Node(int _idx = 0, int _val = 0) : idx(_idx), val(_val) {}
  bool operator<(const Node &x) const { return val > x.val; }
};
std::priority_queue<Node> que;
map<int, int> in, out;
set<pair<int, int> > vis;
signed main() {
  scanf("%d%d%ld", &n, &m, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), sum[0] += a[i], ++in[a[i]];
  for (int i = 1; i <= m; ++i) scanf("%d", b + i), ++out[b[i]];
  for (int i = 1; i <= n; ++i) {
    if (out.upper_bound(a[i]) != out.end()) {
      int nxt = out.upper_bound(a[i])->first;
      que.push(Node(a[i], nxt - a[i]));
      vis.insert(pair<int, int>(a[i], nxt));
    }
  }
  int mx = 0;
  for (int i = 1; i <= q; ++i) {
    scanf("%d", &qry[i].first);
    mx = max(qry[i].first, mx);
    qry[i].second = i;
  }
  sort(qry + 1, qry + q + 1);
  int k = 0, pos = 0;
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
        int pre = (--in.lower_bound(p.idx))->first;
        if (!vis.count(pair<int, int>(pre, p.idx))) {
          que.push(Node(pre, p.idx - pre));
          vis.insert(pair<int, int>(pre, p.idx));
        }
      }
      if (out.upper_bound(p.idx + p.val) != out.end()) {
        int nxt = out.upper_bound(p.idx + p.val)->first;
        if (!vis.count(pair<int, int>(p.val + p.idx, nxt))) {
          que.push(Node(p.val + p.idx, nxt - p.val - p.idx));
          vis.insert(pair<int, int>(p.val + p.idx, nxt));
        }
      }
      k = max(k, p.val);
      while (pos <= q && qry[pos].first < k) ++pos;
      if (pos <= q) sum[pos] += p.val;
    }
  }
  for (int i = 1; i <= q; ++i) {
    sum[i] += sum[i - 1];
    ans[qry[i].second] = sum[i];
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
