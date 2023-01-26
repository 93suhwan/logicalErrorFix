#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 500001
#define mod 1000000007

int f(int n)
{
  return (n * (n + 1)) >> 1;
}
struct item
{
  int x, y, xx, yy, sz, ans;
};
struct segtree
{
  vector<item> seg;

  segtree(vector<int> &v)
  {
    int n = v.size();
    seg.resize(4 * n);
    build(0, n - 1, 1, v);
  }
  item merge(item a, item b)
  {
    if (a.ans == -1)
      return b;
    if (b.ans == -1)
      return a;
    item ans;
    ans.x = a.x;
    ans.y = b.y;
    ans.sz = a.sz + b.sz;
    if (a.y <= b.x)
    {
      ans.ans = a.ans + b.ans;
      ans.ans -= f(a.xx);
      ans.ans -= f(b.yy);
      ans.ans += f(a.xx + b.yy);
      ans.xx = (a.xx == a.sz) ? a.xx + b.xx : a.xx;
      ans.yy = (b.yy == b.sz) ? b.yy + a.yy : b.yy;
    }
    else
    {
      ans.xx = a.xx;
      ans.yy = b.yy;
      ans.ans = a.ans + b.ans;
    }
    return ans;
  }
  void update(int i, int l, int r, int q, int x)
  {
    if (l == r)
    {
      seg[i] = {x, x, 1, 1, 1, 1};
      return;
    }
    int mid = (l + r) >> 1;
    if (q <= mid)
      update(i << 1, l, mid, q, x);
    else
      update((i << 1) | 1, mid + 1, r, q, x);
    seg[i] = merge(seg[i << 1], seg[(i << 1) | 1]);
  }
  item query(int l, int r, int ql, int qr, int i)
  {
    int mid = (l + r) >> 1;
    if (l > r || l > qr || r < ql)
      return {0, 0, 0, 0, 0, -1};
    if (l >= ql && r <= qr)
      return seg[i];
    return merge(query(l, mid, ql, qr, i << 1), query(mid + 1, r, ql, qr, (i << 1) | 1));
  }
  void build(int l, int r, int i, vector<int> &v)
  {
    if (l == r)
    {
      seg[i] = {v[i], v[i], 1, 1, 1, 1};
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1, v);
    build(mid + 1, r, (i << 1) | 1, v);
    seg[i] = merge(seg[i << 1], seg[(i << 1) | 1]);
  }
};
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  segtree s(v);
  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x, y;
      cin >> x >> y;
      x--;
      s.update(1, 0, n - 1, x, y);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << s.query(0, n - 1, l, r, 1).ans << endl;
    }
  }
  return 0;
}
