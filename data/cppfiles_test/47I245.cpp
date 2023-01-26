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

//#define endl '\n'

#define OUT cout << "-------" << endl;

using namespace std;

using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll a[111][111], o[111][111], x[111][111], b[111], c[12001], n, i, j, bit, k, val, val1;

    ll get(ll a, ll b, ll c)
    {
        ll val;

        if (c == 0)
        cout << "and " << a << " " << b << endl;
        else cout << "or " << a << " " << b << endl;

        cin >> val;

        re val;
    }

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;

    for (i = 1; i <= 3; i++)
        for (j = i + 1; j <= 3; j++) {
            a[i][j] = get(i, j, 0);

            o[i][j] = get(i, j, 1);

            x[i][j] = o[i][j] - a[i][j];
        }

    for (bit = 0; bit < 40; bit++) {
        if ((x[1][2] >> bit) % 2 == 0) {
            if ((a[1][2] >> bit) % 2 == 1)
            c[1] += (1LL << bit);

            cont;
        }

        if ((x[1][3] >> bit) % 2 == 0) {
            if ((a[1][3] >> bit) % 2 == 1)
            c[1] += (1LL << bit);

            cont;
        }

        if ((x[2][3] >> bit) % 2 == 0) {
            if ((a[2][3] >> bit) % 2 == 0)
            c[1] += (1LL << bit);

            cont;
        }
    }

    for (i = 2; i <= 3; i++) c[i] = (c[i - 1] ^ x[i - 1][i]);

    for (i = 1; i <= n; i++) cout << c[i] << " ";

    cout << endl;

    for (i = 4; i <= n; i++) {
        val = get(i, i - 1, 0);

        val1 = get(i, i - 1, 1);

        c[i] = (c[i - 1] ^ (val1 - val));
    }

    sort(c + 1, c + n + 1);

    cout << "finish " << c[k] << endl;

    re 0;
}
