#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const ll INF = 1000000007LL;
const ll MOD = 998244353LL;
const int LIM = 2e5 + 5;

void solve()
{
    int n, m, k, tmp;
    cin >> n >> m >> k;
    
    ordered_set sx, sy;
    map<int, int> mx, my;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sx.insert(tmp);
        mx[tmp] = 1;
    }
    for(int j = 0; j < m; j++)
    {        
        cin >> tmp;
        sy.insert(tmp);
        my[tmp] = 1;
    }

    int res = 0;
    map<int, int> mx1, my1;
    map<pair<int, int>, int> mpix, mpiy;
    
    for(int i = 0; i < k; i++)
    {
        int xcoord, ycoord;
        cin >> xcoord >> ycoord;
        if(mx[xcoord] == 1 && my[ycoord] == 1)
            continue;
        
        if(mx[xcoord] == 1)
        {
            int cnt = sy.order_of_key(ycoord);
            res+= mx1[cnt];
            mx1[cnt]++;

            res-=mpix[{xcoord, cnt}];
            mpix[{xcoord, cnt}]++;
        }
        else
        {
            int cnt = sx.order_of_key(xcoord);
            res+= my1[cnt];
            my1[cnt]++;

            res-=mpiy[{ycoord, cnt}];
            mpiy[{ycoord, cnt}]++;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}