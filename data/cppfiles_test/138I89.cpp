#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

long long MOD = 1000000007;
long long x[11];
string crct[11];

void Solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> crct[i];
    }
    long long ans = -1;
    vector<int> p(m);
    for (int permutation = 0; permutation <= (1 << n); permutation++)
    {
        long long curr = 0;
        vector<pair<int, int>> contri(m, {0, 0});
        for (int i = 0; i < m; i++)
        {
            contri[i].second = i;
        }
        for (int j = 0; j < n; j++)
        {
            int mult = 1;
            if ((permutation >> j) & 1)
            {
                curr += x[j];
                mult = -1;
            }
            else
            {
                curr -= x[j];
            }
            for (int k = 0; k < m; k++)
            {
                if (crct[j][k] == '1')
                {
                    contri[k].first += mult;
                }
            }
        }
        sort(contri.begin(), contri.end());
        for (int i = 0; i < m; i++)
        {
            curr += contri[i].first * (i + 1);
        }
        if (curr > ans)
        {
            ans = curr;
            for (int i = 0; i < m; i++)
            {
                p[contri[i].second] = (i + 1);
            }
        }
    }
    for (auto x : p)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ntest;
    cin >> ntest;
    for (long long i = 0; i < ntest; i++)
    {
        Solve();
    }
}