#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef priority_queue<ll> pqll;
typedef priority_queue<int> pqi;
typedef set<ll> sll;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef multiset<ll> msll;
typedef multiset<int> msi;
typedef unordered_multiset<int> umsi;
typedef unordered_multiset<ll> umsll;
typedef map<ll, ll> mll;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;
typedef unordered_map<ll, ll> umll;
typedef multimap<ll, ll> mmll;
typedef multimap<int, int> mmi;
typedef unordered_multimap<int, int> ummi;
typedef unordered_multimap<ll, ll> ummll;
typedef tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sd second
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for (ll i=a; i<b; i++)
#define REP_BACK(i, a, b) for (ll i=a-1; i>=b; i--)
#define TRAV(a, v) for(auto a : v)
#define file ifstream cin ("Input.txt"); ofstream cout ("Output.txt");
#define randomize srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

const long long int MOD = 1e9+7;
const long long int INF = 1e18;
const long double EPS = 1e-9;

struct pair_hash
{
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &par) const {
        return hash<T1>()(par.first) ^ hash<T2>()(par.second);
    }
};

ll inverse (ll a, ll m)
{
    if (a == 1)
        return a;
    return ((a-inverse(m%a, a))*m+1)/a;
}

int main()
{
    speed;
    int n, q, x;
    cin >> n >> q;
    ll a[3*n+4], b[4] = {0, 3, 3, 1}, ans[3*n+1];
    a[0] = 1;
    for (int i=1; i<=(3*n+3)/2; i++)
    {
        a[i] = (a[i-1]*(3*n+4-i))%MOD;
        a[i] = (a[i]*inverse(i, MOD))%MOD;
    }
    for (int i=(3*n+5)/2; i<=3*n+3; i++)
        a[i] = a[3*n+3-i];
    a[0] --;
    a[1] -= 3;
    a[2] -= 3;
    a[3] --;
    int atual = 3*n+3;
    while (atual >= 3)
    {
        ans[atual-3] = a[atual];
        a[atual] = 0;
        a[atual-1] -= 3*ans[atual-3];
        a[atual-2] -= 3*ans[atual-3];
        while (a[atual-1] < 0)
            a[atual-1] += MOD;
        while (a[atual-2] < 0)
            a[atual-2] += MOD;
        atual --;
    }
    while (q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
    cout << clock();
    return 0;
}
