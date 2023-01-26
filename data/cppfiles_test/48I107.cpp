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

struct segtree
{
  int n;
  vector<int> seg;

  segtree(vector<int> &v)
  {
    n = 1;
    while (n < v.size())
      n <<= 1;
    seg.assign(n << 1, 1e18);
    for (int i = 0; i < v.size(); i++)
      seg[i + n] = v[i];
    for (int i = n - 1; i; i--)
      seg[i] = min(seg[i << 1], seg[(i << 1) | 1]);
  }
  int qry(int l, int r)
  {
    int ans = 1e18;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
      if (l & 1)
        ans = min(ans, seg[l++]);
      if (r & 1)
        ans = min(seg[--r], ans);
    }
    return ans;
  }
};
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector<int> c(n);
  for (int i = 0; i < n; i++)
    c[i] = (!i) ? a[i] - b[i] : c[i - 1] + (a[i] - b[i]);
  segtree s(c);
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int sum = c[r];
    sum -= (!l) ? 0 : c[l - 1];
    if (sum != 0)
    {
      cout << -1 << endl;
    }
    else
    {
      int curr = s.qry(l, r) * -1;
      curr += (!l) ? 0 : c[l - 1];
      cout << curr << endl;
    }
  }
  return 0;
}