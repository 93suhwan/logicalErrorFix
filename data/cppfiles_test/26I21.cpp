#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long int
#define ull unsigned long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define forn(i, a, b) for (int i=a; i<b; i++)
#define fore(i, a, b) for (int i=a; i<=b; i++)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void fast_io() {
  fastio;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
ull mod = 1000000007;
ull fact(int n)
{
  if (n < INT_MAX)
  {
    ull ans = 1;
    for (int i = 2; i <= n; i++)
      ans = (ans * i) % mod;
    return ans;
  }
  return 0;
}

signed main()
{
  fast_io();
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = fact(2 * n);
    if (n < 7)
      cout << ans / 2 << endl;
    else cout << ans / 2 + 500000004 << endl;
  }
}