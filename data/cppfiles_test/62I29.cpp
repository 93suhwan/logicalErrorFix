




#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")


#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


#define F first

#define S second
#define pb push_back
#define ll long long
#define int ll
#define pii pair < ll, ll >
#define ld long double
#define ull unsigned long long

using namespace std;
using namespace __gnu_pbds;


template < typename T > using ordered_set = tree < T, null_type,
                              less < T >, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 gen(time(0));

const int M = 500005;
const int N = 1e3 + 10;
const int inf = 1e16;
const int MOD = 1e9 + 7;
const ld eps = 0.000000000001;

int dp[N][N][2];
bool a[N][N];
int ans = 0;
void solve (int i, int j)
{
    ans -= dp[i][j][0];
    ans -= dp[i][j][1];
    if (dp[i][j][0]) ans++;
    dp[i][j][0] = 0;
    dp[i][j][1] = 0;
    if (a[i][j]) return;
    dp[i][j][0] = 1;
    dp[i][j][1] = 1;
    dp[i][j][1]+=dp[i - 1][j][0];
    dp[i][j][0] += dp[i][j - 1][1];
    ans+=dp[i][j][1] + dp[i][j][0] - 1;
    return;
}
int32_t main ()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);
#endif // LACOL
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        solve (i, j);
    }
  }

  while (q--)
  {
      int x, y;
      cin >> x >> y;
      a[x][y]^=1;
      for (int i = 1; i <= n; i++) {
        if  (!(x >= 1 && x <= n && y >= 1 && y <= m)) break;
        if (x - 1 >= 1) solve (x - 1, y);
        if  (y - 1 >= 1) solve (x, y - 1);
        solve (x, y);
        x++; y++;

      }
      cout <<  ans << '\n';
  }

  return 0;
}



