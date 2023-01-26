#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long maxv = 2e5;
struct TreeNode {
  long long ls, rs, sum, cnt;
};
TreeNode t[maxn * 21];
long long pol;
long long n;
inline int newnode() {
  t[++pol].sum = 0;
  return pol;
}
inline void pushup(long long p) {
  t[p].sum = t[t[p].ls].sum + t[t[p].rs].sum;
  t[p].cnt = t[t[p].ls].cnt + t[t[p].rs].cnt;
  return;
}
void upd(long long p, long long l, long long r, long long x) {
  if (l == r) {
    t[p].sum += x;
    t[p].cnt++;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid) {
    if (t[p].ls == 0) t[p].ls = newnode();
    upd(t[p].ls, l, mid, x);
  }
  if (x > mid) {
    if (t[p].rs == 0) t[p].rs = newnode();
    upd(t[p].rs, mid + 1, r, x);
  }
  pushup(p);
  return;
}
long long quesum(long long p, long long pl, long long pr, long long l,
                 long long r) {
  if (pl > pr) return 0;
  if (p == 0) return 0;
  if (pl <= l && r <= pr) return t[p].sum;
  long long mid = (l + r) >> 1, res = 0;
  if (pl <= mid) res += quesum(t[p].ls, pl, pr, l, mid);
  if (pr > mid) res += quesum(t[p].rs, pl, pr, mid + 1, r);
  return res;
}
long long quecnt(long long p, long long pl, long long pr, long long l,
                 long long r) {
  if (pl > pr) return 0;
  if (p == 0) return 0;
  if (pl <= l && r <= pr) return t[p].cnt;
  long long mid = (l + r) >> 1, res = 0;
  if (pl <= mid) res += quecnt(t[p].ls, pl, pr, l, mid);
  if (pr > mid) res += quecnt(t[p].rs, pl, pr, mid + 1, r);
  return res;
}
long long merge(long long x, long long y) {
  if (x == 0 || y == 0) return x + y;
  t[x].ls = merge(t[x].ls, t[y].ls);
  t[x].rs = merge(t[x].rs, t[y].rs);
  if (t[x].ls || t[x].rs) {
    pushup(x);
    return x;
  }
  t[x].sum += t[y].sum;
  t[x].cnt += t[y].cnt;
  return x;
}
vector<long long> adj[maxn];
vector<pair<long long, long long>> opt[maxn];
long long rt[maxn];
long long ans[maxn];
void dfs(long long now, long long fa) {
  long long num = 0;
  rt[now] = newnode();
  for (auto t : adj[now]) {
    if (t == fa) continue;
    num++;
    dfs(t, now);
    rt[now] = merge(rt[now], rt[t]);
  }
  for (auto fr : opt[now]) {
    long long vv = fr.first, id = fr.second;
    ans[id] = num + quesum(rt[now], vv, maxv, 0, maxv) -
              quecnt(rt[now], vv, maxv, 0, maxv) * vv;
  }
  if (num) upd(rt[now], 0, maxv, num - 1);
  return;
}
long long q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    long long ux, vx;
    cin >> ux >> vx;
    adj[ux].push_back(vx);
    adj[vx].push_back(ux);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    long long ux, kx;
    cin >> ux >> kx;
    opt[ux].emplace_back(kx, i);
  }
  dfs(1, 0);
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
  cout.flush();
  return 0;
}
