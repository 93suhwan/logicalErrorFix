#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long INF = 0x7fffffffffffffff;
const long long MAXN = 4e5 + 9;
long long N, M, K, Ans = 0;
long long fa[MAXN], st[MAXN], ed[MAXN], cur[MAXN], Sum[MAXN], ANS[MAXN];
struct Group {
  long long start_id, k;
  bool operator<(const Group &g) const {
    if (k < g.k)
      return true;
    else if (k == g.k)
      return start_id < g.start_id;
    return false;
  }
  bool operator<=(const Group &g) const {
    if (k < g.k)
      return true;
    else if (k == g.k)
      return start_id <= g.start_id;
    return false;
  }
  bool operator==(const Group &g) const {
    return k == g.k && start_id == g.start_id;
  }
};
set<Group> groups;
struct Node {
  long long id, type, val;
} nodes[MAXN];
struct Question {
  long long id, k, ans;
} Q[MAXN];
inline bool cmp1(Node &a, Node &b) { return a.val < b.val; }
inline bool cmp2(Question &a, Question &b) { return a.k < b.k; }
long long sum(long long id) { return Sum[ed[id]] - Sum[ed[id] - cur[id]]; }
long long get_fa(long long x) {
  if (x == fa[x])
    return x;
  else
    return fa[x] = get_fa(fa[x]);
}
void _union(long long id) {
  long long fx = get_fa(id), fy = get_fa(id - 1);
  Ans -= (sum(fx) + sum(fy));
  fa[fx] = fy;
  st[fx] = st[fy] = min(st[fy], st[fx]);
  ed[fy] = ed[fy] = max(ed[fy], ed[fx]);
  cur[fy] = cur[fx] = cur[fx] + cur[fy];
  Ans += sum(fy);
}
signed main() {
  for (long long i = 0; i < MAXN; i++) fa[i] = i;
  cin >> N >> M >> K;
  for (long long i = 1; i <= N; i++)
    cin >> nodes[i].val, nodes[i].type = 0, nodes[i].id = i,
                         Ans += nodes[i].val;
  for (long long i = 1; i <= M; i++)
    cin >> nodes[i + N].val, nodes[i + N].type = 1, nodes[i + N].id = i;
  for (long long i = 1; i <= K; i++) cin >> Q[i].k, Q[i].id = i;
  sort(nodes + 1, nodes + 1 + N + M, cmp1);
  sort(Q + 1, Q + 1 + K, cmp2);
  Sum[0] = 0;
  for (long long i = 1; i <= N + M; i++) {
    Group g;
    g.start_id = i;
    g.k = i == 1 ? INF : nodes[i].val - nodes[i - 1].val;
    groups.insert(g);
    st[i] = ed[i] = i;
    cur[i] = 1 - nodes[i].type;
    Sum[i] = Sum[i - 1] + nodes[i].val;
  }
  for (long long i = 1; i <= K; i++) {
    while (true) {
      set<Group>::iterator iter = groups.begin();
      if (iter->k <= Q[i].k) {
        _union(iter->start_id);
        groups.erase(iter);
      } else {
        break;
      }
    }
    ANS[Q[i].id] = Ans;
  }
  for (long long i = 1; i <= K; i++) {
    cout << ANS[i] << endl;
  }
}
