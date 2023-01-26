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

string s, s1;

ll x, y, l, r, p;

    string get(ll n)
    {
        string ans = "";

        while (n > 0) {
            ans += char(n % 2 + 48);

            n /= 2;
        }

        reverse(ans.begin(), ans.end());

        re ans;
    }

    bool check(ll l, ll r)
    {
        ll i;

        for (i = 0; i < s1.size(); i++) {
            if (l <= i && i <= r)
            cont;

            if (s1[i] == '0')
            re 0;
        }

        re 1;
    }

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    s = get(x);

    s1 = get(y);

    if (s1.find(s) != string::npos) {
        l = s1.find(s);

        r = l + (ll) s.size() - 1;

        if (check(l, r)) {
            cout << "YES" << endl;

            re 0;
        }
    }

    while (s.back() == '0') s.er(s.size() - 1, 1);

    if (s1.find(s) != string::npos) {
        l = s1.find(s);

        r = l + (ll) s.size() - 1;

        if (check(l, r)) {
            cout << "YES" << endl;

            re 0;
        }
    }

    reverse(s.begin(), s.end());

    if (s1.find(s) != string::npos) {
        l = s1.find(s);

        r = l + (ll) s.size() - 1;

        if (check(l, r)) {
            cout << "YES" << endl;

            re 0;
        }
    }

    cout << "NO" << endl;

    re 0;
}
