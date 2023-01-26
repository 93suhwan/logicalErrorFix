#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iterator>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define x0 abc
#define y0 ABC
#define x1 abcd
#define y1 ABCD
#define xn abcde
#define yn ABCDE

#define lb lower_bound
#define ub upper_bound

#define in insert
#define er erase

#define fi first
#define se second
#define mp make_pair

#define pb push_back
#define pob pop_back

#define uns unsigned

#define ld long double
#define ll long long

#define cont continue
#define re return

#define MAXLL 9000000000000000000LL
#define MAXINT 2000000000

#define MINLL -9000000000000000000LL
#define MININT -2000000000

#define pi acos(-1.)

#define endl '\n'

#define OUT cout << "-------" << endl;

using namespace std;

using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

pair <ll, ll> d[12001];

char c[111][12001];

ll a[12001], b[12001], ans[12001], n, m, i, j, z, t, sum, mx;

    void solve()
    {
        cin >> n >> m;

        for (i = 1; i <= n; i++) cin >> a[i];

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) cin >> c[i][j];

        mx = -1;

        for (z = 0; z < (1LL < n); z++) {
            for (i = 0; i < n; i++)
                if ((z >> i) % 2 == 1) b[i + 1] = 1;
                else b[i + 1] = -1;

            for (j = 1; j <= m; j++) {
                sum = 0;

                for (i = 1; i <= n; i++)
                    if (c[i][j] == '1') sum += b[i];

                d[j] = mp(sum, j);
            }

            sort(d + 1, d + m + 1);

            sum = 0;

            for (i = 1; i <= n; i++) sum += a[i] * b[i] * -1;

            for (i = 1; i <= m; i++) sum += d[i].fi * i;

            if (sum > mx) {
                mx = sum;

                for (i = 1; i <= m; i++) ans[i] = d[i].se;
            }
        }

        for (i = 1; i <= m; i++) cout << ans[i] << " ";

        cout << endl;
    }

int main()
{
    //freopen("maxxor.in", "r", stdin);
    //freopen("maxxor.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) solve();

    re 0;
}
