#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;

const int mxN = 55;
const int mod = 998244353;
const int mxlogN = 20;
const int mxK = 26;

ll powb(ll a, ll x)
{
    ll ret = 1;
    a %= mod;
    while(x)
    {
        if(x&1)ret=ret*a%mod;
        x>>=1;
        a=a*a%mod;
    }
    return ret;
}
char ans[mxN][mxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> twos;
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='2') twos.push_back(i);
        }
        if(twos.size() == 1 || twos.size() == 2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int j = 0; j < n; j++) for(int i = 0; i < n; i++) ans[j][i] = '=';
        for(int i = 0; i < twos.size(); i++)
        {
            int x = twos[i];
            int y = twos[(i+1)%twos.size()];
            ans[x][y] = '+';
            ans[y][x] = '-';
        }
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < n; i++) cout << ans[j][i];
            cout << "\n";
        }

    }
}
/**
V
V
^
^
*/
