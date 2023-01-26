#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef long long ll;
//tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
//__gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> qu;
//typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
const int N = 2005;
int n, m, k;
const ll mod = 1e9 + 7;
map<string, int> foo;
map<ll, int> mp;

ll fpow(ll x, ll r)
{
    ll result = 1;
    while (r)
    {
        if (r & 1)result = result * x % mod;
        r >>= 1;
        x = x * x % mod;
    }
    return result;
}

vector<ll> dfs(ll u)
{
    vector<ll> sum(6, 1);
    for (ll v:{u << 1, u << 1 | 1})
    {
        if (mp.count(v))
        {
            auto vec = dfs(v);
            for (int i = 0; i < 6; i++)
            {
                ll s = 0;
                for (int j = 0; j < 6; j++)
                    if (j != i && i + j != 5)
                        s = (s + vec[j]) % mod;
                sum[i] = sum[i] * s % mod;
            }
        }
    }
    if (mp[u] != -1)
    {
        for (int i = 0; i < 6; i++)
            if (i != mp[u])
                sum[i] = 0;
    }
    return sum;
}

int main()
{
    int i, j, p, q, u, v, w, x, y, z, T;
    foo["green"] = 0;
    foo["blue"] = 5;
    foo["white"] = 1;
    foo["yellow"] = 4;
    foo["red"] = 2;
    foo["orange"] = 3;
    cin >> k >> n;
    mp[1] = -1;
    for (i = 1; i <= n; i++)
    {
        string ss;
        scanf("%lld", &x);
        cin >> ss;
        mp[x] = foo[ss];
        while (x > 1)
        {
            if (!mp.count(x))
                mp[x] = -1;
            x >>= 1;
        }
    }
    ll size = (1ll << k) - 1;
    ll ans = fpow(4, size - mp.size());
    auto vec = dfs(1);
    ans = ans * ((vec[0] + vec[1] + vec[2] + vec[3] + vec[4] + vec[5]) % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
