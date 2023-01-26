#include <bits/stdc++.h>
using namespace std;
using db = double;
using s64 = long long;
using ld = long double;
using u32 = unsigned int;
using u64 = unsigned long long;
using pii = pair<int, int>;
const double PI = acos(-1);
const double eps = 1e-7;
namespace Solver {
const char endl = '\n';
const int MN = 3e5 + 5;
int n, m, dp[MN], pre[MN];
inline void ckmin(int& x, int y) {
  if (dp[y] < dp[x]) x = y;
}
namespace SegT {
struct Node {
  Node *ls, *rs;
  int tag, val;
  Node() {
    ls = rs = nullptr;
    tag = val = 0;
  }
}* rt = nullptr;
void add(int l, int r, int v, Node*& o = rt, int L = 1, int R = 1e9) {
  if (r < L || R < l) return;
  if (o == nullptr) o = new Node;
  if (l <= L && R <= r) {
    ckmin(o->tag, v);
    ckmin(o->val, v);
    return;
  }
  int mid = L + R >> 1;
  add(l, r, v, o->ls, L, mid);
  add(l, r, v, o->rs, mid + 1, R);
  if (o->ls != nullptr) ckmin(o->val, o->ls->val);
  if (o->rs != nullptr) ckmin(o->val, o->rs->val);
}
int query(int l, int r, Node* o = rt, int L = 1, int R = 1e9) {
  if (o == nullptr || r < L || R < l) return 0;
  if (l <= L && R <= r) return o->val;
  int mid = L + R >> 1, res = o->tag;
  ckmin(res, query(l, r, o->ls, L, mid));
  ckmin(res, query(l, r, o->rs, mid + 1, R));
  return res;
}
}  // namespace SegT
struct O {
  int i, l, r;
} o[MN];
void main() {
  cin >> n >> m;
  for (decay<decltype(m)>::type i = (0), _i = (m); i < _i; ++i)
    cin >> o[i].i >> o[i].l >> o[i].r;
  sort(o, o + m, [](const O& a, const O& b) { return a.i < b.i; });
  for (int i = 0, j; i < m; i = j) {
    int I = o[i].i;
    for (j = i; o[j].i == I; ++j) ckmin(pre[I], SegT::query(o[j].l, o[j].r));
    dp[I] = dp[pre[I]] - 1;
    for (decay<decltype(j)>::type k = (i), _k = (j); k < _k; ++k)
      SegT::add(o[k].l, o[k].r, I);
  }
  int ans = n, p = 0;
  for (decay<decltype(n)>::type i = (1), _i = (n); i <= _i; ++i)
    if (dp[i] + n < ans) ans = dp[i] + n, p = i;
  cout << ans << endl;
  vector<bool> used(n + 1, false);
  for (int i = p; i; i = pre[i]) used[i] = true;
  for (decay<decltype(n)>::type i = (1), _i = (n); i <= _i; ++i)
    if (!used[i]) cout << i << ' ';
  cout << endl;
}
}  // namespace Solver
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  for (decay<decltype(T)>::type _t = (1), __t = (T); _t <= __t; ++_t) {
    Solver::main();
  }
  return 0;
}
