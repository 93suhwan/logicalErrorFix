#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define M 1000000007
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define d(x) cout << #x << " " << x << "\n";
#define min(x1, x2) (x1 > x2 ? x2 : x1)
#define max(x1, x2) (x1 < x2 ? x2 : x1)
#define min3(x1, x2, x3) (x3 > min(x1, x2) ? min(x2, x1) : x3)
#define max3(x1, x2, x3) (x3 < max(x1, x2) ? max(x1, x2) : x3)
#define ll long long int
#define p pair<ll, ll>
#define ld long double
#define dv(v)                            \
    cerr << #v << "  ";                  \
    for (int i = 0; i < (v).size(); i++) \
        cerr << v[i] << " ";             \
    cerr << "\n";
#define inf INT_MAX
#define mp(x, y) make_pair(x, y)
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

int main()
{
    fio;
    ll t, n, x, y, z, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<ll> v;
        for (int i = 0; i < n; ++i)
        {
            z = 0;
            while (i < n && s[i] == '*')
            {
                ++z;
                ++i;
            }
            if (z)
            {
                v.push_back(z * k + 1);
                --i;
            }
            else
            {
                v.push_back(0);
            }
        }
        vector<ll> suf;
        z = 1;
        bool b0 = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (v[i])
            {
                if (z > 1e18)
                {
                    suf.push_back(-1);
                    continue;
                }
                z *= v[i];
                suf.push_back(z);
            }
        }
        reverse(suf.begin(), suf.end());
        suf.push_back(1);
        suf.push_back(1);
        k = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == 0)
            {
                cout << "a";
            }
            else
            {
                // suf[k]
                if (suf[k + 1] == -1)
                {
                    z = 0;
                }
                else
                {
                    z = x / suf[k + 1];
                    if (x % suf[k + 1])
                    {
                        ++z;
                    }
                }
                for (int i = 1; i <= z - 1; ++i)
                {
                    cout << "b";
                }
                if (z)
                {
                    x -= (z - 1) * suf[k + 1];
                }
                ++k;
            }
        }
        cout << "\n";
    }
    return 0;
}