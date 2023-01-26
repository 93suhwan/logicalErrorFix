#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 200005
#define mod 998244353

struct modint
{
  int val;
  modint(int v = 0) { val = v % mod; }
  int pow(int y)
  {
    modint x = val;
    modint z = 1;
    while (y)
    {
      if (y & 1)
        z *= x;
      x *= x;
      y >>= 1;
    }
    return z.val;
  }
  int inv() { return pow(mod - 2); }
  void operator=(int o) { val = o % mod; }
  void operator=(modint o) { val = o.val % mod; }
  void operator+=(modint o) { *this = *this + o; }
  void operator-=(modint o) { *this = *this - o; }
  void operator*=(modint o) { *this = *this * o; }
  void operator/=(modint o) { *this = *this / o; }
  bool operator==(modint o) { return val == o.val; }
  bool operator!=(modint o) { return val != o.val; }
  int operator*(modint o) { return ((val * o.val) % mod); }
  int operator/(modint o) { return (val * o.inv()) % mod; }
  int operator+(modint o) { return (val + o.val) % mod; }
  int operator-(modint o) { return (val - o.val + mod) % mod; }
};
struct implcit_seg
{
  int l, r;
  modint sum, lazy, lazy2;
  implcit_seg *left_child = nullptr;
  implcit_seg *right_child = nullptr;

  implcit_seg(int l, int r) : l(l), r(r)
  {
    sum = 0;
    lazy = 0;
    lazy2 = 0;
  }
  void check_childs()
  {
    if (!left_child && l != r)
    {
      int mid = (l + r) >> 1;
      left_child = new implcit_seg(l, mid);
      right_child = new implcit_seg(mid + 1, r);
    }
  }
  void add(modint x)
  {
    modint tot = x * (r - l + 1);
    sum += tot;
    if (l != r)
    {
      check_childs();
      left_child->lazy += x;
      right_child->lazy += x;
    }
    lazy = 0;
  }
  void res(modint x)
  {
    sum -= x * 2;
    if (l != r)
    {
      check_childs();
      left_child->lazy2 += left_child->sum;
      right_child->lazy2 += right_child->sum;
    }
    lazy2 = 0;
  }
  void upd(int ql, int qr, modint x)
  {
    if (lazy != 0)
      add(lazy);
    if (lazy2 != 0)
      res(lazy2);
    if (l > r || l > qr || r < ql)
      return;
    if (l >= ql && r <= qr)
    {
      add(x);
      return;
    }
    check_childs();
    left_child->upd(ql, qr, x);
    right_child->upd(ql, qr, x);
    sum = left_child->sum + right_child->sum;
  }
  void sub(int ql, int qr)
  {
    if (lazy != 0)
      add(lazy);
    if (lazy2 != 0)
      res(lazy2);
    if (l > r || l > qr || r < ql)
      return;
    if (l >= ql && r <= qr)
    {
      res(sum);
      return;
    }
    check_childs();
    left_child->sub(ql, qr);
    right_child->sub(ql, qr);
    sum = left_child->sum + right_child->sum;
  }
  modint qry(int ql, int qr)
  {
    if (lazy != 0)
      add(lazy);
    if (lazy2 != 0)
      res(lazy2);
    if (ql <= l && r <= qr)
      return sum;
    if (max(l, ql) >= min(r, qr))
      return 0;
    check_childs();
    return left_child->qry(ql, qr) + right_child->qry(ql, qr);
  }
};
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  implcit_seg *dp = new implcit_seg(1, 1e9);
  for (int i = 0; i < n; i++)
  {
    modint sum = dp->qry(1, 1e9);
    if (!i)
      sum = 1;
    dp->sub(1, 1e9);
    dp->upd(1, v[i], sum);
  }
  cout << dp->qry(1, 1e9).val << endl;
  return 0;
}
// dp[i][j] = soma de dp[i — 1][k], k != j, j <= v[i]
// com isso
// dp[i][j] -= dp[i - 1][j]
// dp[i][j] += soma de todos os dp[i - 1][k]
// a resposta eh a soma de todos os dp[n - 1][j]
