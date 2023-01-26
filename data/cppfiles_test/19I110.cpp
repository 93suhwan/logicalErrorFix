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
#define MAXN 101
#define mod 1000000007

struct seg
{
  int len, l, r, fim;
};

bool cmp(seg a, seg b)
{
  return a.len < b.len;
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    vector<seg> segs;
    segs.pb({v[0], 0, v[0], v[0]});
    for (int i = 1; i < n; i++)
    {
      vector<seg> new_seg;
      for (auto const &j : segs)
      {
        {
          int l = j.l, r = j.r;
          int fim = j.fim - v[i];
          l = min(l, fim);
          r = max(r, fim);
          new_seg.pb({r - l, l, r, fim});
        }
        {
          int l = j.l, r = j.r;
          int fim = j.fim + v[i];
          l = min(l, fim);
          r = max(r, fim);
          new_seg.pb({r - l, l, r, fim});
        }
      }
      sort(new_seg.begin(), new_seg.end(), cmp);
      while (new_seg.size() > 500)
        new_seg.pop_back();
      segs = new_seg;
    }
    cout << segs[0].len << endl;
  }
  return 0;
}