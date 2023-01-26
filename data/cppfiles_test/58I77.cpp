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

#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}

template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

const int MAXN = 200001;
ordered_set global_set;
vector<long long> fact(2 * MAXN);
vector<long long> invfact(2 * MAXN);

long long binpowy(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long res = binpowy(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2)
    {
        res = (res * a) % MOD;
    }
    return res;
}

void precomp()
{
    for (int i = 1; i < MAXN; i++)
    {
        global_set.insert(i);
    }
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < 2 * MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = binpowy(fact[i], MOD - 2);
    }
}

long long nck(long long n, long long k)
{
    long long res = fact[n];
    res = (res * invfact[k]) % MOD;
    res = (res * invfact[n - k]) % MOD;
    return res;
}

void Solve()
{
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> pos(m);
    for (int i = 0; i < m; i++)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    reverse(pos.begin(), pos.end());
    set<int> deleted;
    set<int> marked;
    for (auto x : pos)
    {
        marked.insert(*global_set.find_by_order(x.second));
        auto todel = global_set.find_by_order(x.second - 1);
        deleted.insert(*todel);
        global_set.erase(todel);
    }
    cout << nck(2 * n - 1 - marked.size(), n) << "\n";
    for (auto x : deleted)
    {
        global_set.insert(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ntest;
    cin >> ntest;
    precomp();
    for (long long i = 0; i < ntest; i++)
    {
        Solve();
    }
}