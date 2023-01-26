#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
//mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> gen(-1e9, 1e8); ///(min, max)
//int random() {return gen(mt_rand);}
const int mxN = 5e5+5;
const int mod = 998244353;
const int mxlogN = 20;
const int mxK = 26;
const ll inf = 1e18;
int x[mxN];
string s[mxN];
int p[mxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> s[i];
        ll ans = -1;
        for(int i = 0; i < (1<<n); i++)
        {
            ///i&(1<<j) => evaluate jth with x-r
            ll cur = 0;
            vector<int> c(m, 0);
            for(int j = 0; j < n; j++)
            {
                int sign = (i&(1<<j))? 1 : -1;
                cur += x[i]*sign;
                for(int k = 0; k < m; k++) if(s[j][k]=='1') c[k]-=sign;
            }
            vector<int> order(m);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int i, int j)
            {
                return c[i] < c[j];
            });
            for(int j = 0; j < m; j++) cur += c[order[j]]*(j+1);
            if(cur > ans)
            {
                ans = cur;
                for(int j = 0; j < m; j++) p[order[j]]= j+1;
            }
        }
        for(int i = 0; i < m; i++) cout << p[i] << " ";
        cout << "\n";
    }
}
