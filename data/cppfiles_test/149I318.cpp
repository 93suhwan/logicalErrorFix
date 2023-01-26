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
const int mod = 1e9+7;
const int mxlogN = 20;
const int mxK = 26;
const ll inf = 1e9;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        ll n, k; ll x; cin >> n >> k >> x;
        string s; cin >> s;
        /*if(x==1)
        {
            for(char c : s) if(c=='a') cout << "a";
            cout << "\n";
            continue;
        }*/
        ll comb = 1;
        vector<pair<int, ll>> vis;
        for(int i = n-1; i >= 0; i--)
        {
            ll cnt = 0;
            while(i>=0 && s[i]=='*')
            {
                cnt++;
                i--;
            }
            if(!cnt) continue;
            ll cur = cnt*k+1;
            ll nowL = comb*cur;
            if(nowL >= x || nowL < 0)
            {
                string ans;
                int pre = 0;
                vis.push_back({i, comb});
                while(vis.size())
                {
                    auto par = vis.back();
                    vis.pop_back();
                    i = par.first;
                    for(int j = pre; j <= i; j++) if(s[j]=='a') ans.push_back('a');
                    pre = i+1;
                    comb = par.second;
                    while(x > comb)
                    {
                        x -= comb;
                        ans.push_back('b');
                    }
                }
                for(int j = pre; j < n; j++) if(s[j]=='a') ans.push_back('a');
                cout << ans << "\n";
                break;
            }
            else
            {
                vis.push_back({i, comb});
                i++;
                comb = nowL;
            }
        }
    }
}
