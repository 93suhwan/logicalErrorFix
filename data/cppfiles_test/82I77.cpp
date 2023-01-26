#include <bits/stdc++.h>
using std::pair;
using std::priority_queue;
using std::vector;
const int N = 300005;
int n, Q, k, l[N], r[N], a[N], len[N], fa[N];
long long sum[N], rans[N];
priority_queue<pair<int, int> > q, del;
vector<int> e[N];
inline int findfa(int first) {
  return first == fa[first] ? first : fa[first] = findfa(fa[first]);
}
inline void upt(int first) {
  sum[first] = 1ll * a[first] * len[first] +
               (first + len[first] * k <= n ? sum[first + len[first] * k] : 0);
}
inline void fix(int first, int v) {
  a[first] = v;
  upt(first);
  while (first + len[first] * k <= n && v <= a[first + len[first] * k]) {
    fa[first + len[first] * k] = first;
    len[first] += len[first + len[first] * k];
    upt(first);
  }
}
inline void fix(void) {
  while (!del.empty() && q.top() == del.top()) q.pop(), del.pop();
}
int main() {
  scanf("%d%d%d", &n, &Q, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= Q; ++i)
    scanf("%d%d", l + i, r + i), e[l[i]].push_back(i);
  std::iota(fa, fa + n + 1, 0);
  for (int i = n; i; --i) {
    while (1) {
      fix();
      if (q.empty() || q.top().first <= a[i]) break;
      auto t = q.top();
      q.pop();
      fix(t.second, a[i]);
      t.first = a[i];
      q.push(t);
    }
    len[i] = 1;
    if (i + k <= n) del.push({a[i + k], i + k});
    fix(i, a[i]);
    upt(i);
    q.push({a[i], i});
    for (int first : e[i]) {
      int r = ::r[first];
      r = (r - i) / k * k + k + i;
      int fr = findfa(r);
      rans[first] = sum[i] -
                    (fr + len[fr] * k <= n ? sum[fr + len[fr] * k] : 0) -
                    1ll * a[fr] * (len[fr] - (r - fr) / k);
    }
  }
  for (int i = 1; i <= Q; ++i) printf("%lld\n", rans[i]);
  return 0;
}
