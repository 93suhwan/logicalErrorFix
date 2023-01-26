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
#define ul unsigned long long int
#define p pair<ul, ul>
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
    ul t, n, x, y, z, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<long long> v;
        for (int i = 0; i < n; ++i)
        {
            long long z0 = 0;
            while (i < n && s[i] == '*')
            {
                ++z0;
                ++i;
            }
            if (z0)
            {
                v.push_back(z0 * k + 1);
                --i;
            }
            else
            {
                v.push_back(0);
            }
        }
        vector<ul> suf;
        z = 1;
        bool b0 = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (v[i])
            {
                if (z > x)
                {
                    suf.push_back(x + 1);
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
        long long z0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == 0)
            {
                cout << "a";
            }
            else
            {
                // suf[k]
                if (suf[k + 1] == x + 1)
                {
                    z0 = 0;
                }
                else
                {
                    z0 = x / suf[k + 1];
                    if (x % suf[k + 1])
                    {
                        ++z;
                    }
                }

                for (int i = 1; i <= z0 - 1; ++i)
                {
                    cout << "b";
                }
                if (z0)
                {
                    x -= (z0 - 1) * suf[k + 1];
                }
                ++k;
            }
        }
        cout << "\n";
    }
    return 0;
}