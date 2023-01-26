#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define pb push_back
//#define mp make_pair
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define openfile ifstream cin; ofstream cout; cin.open("input.txt"); cout.open("output.txt");
#define f(i, x, y) for(int i = x; i < y; i++)
#define all(X) X.begin(), X.end()
#define int long long
#define ll unsigned long long
#define key pair<int, int>
#define keyy pair<pair<int, int>, int>
#define keyyy pair<pair<int, int>, pair<int, int>>
// #define ordered_set<T> tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>
#define keyd pair<double, double>
#define ff first
#define ss second
#define double long double
// const int mod = 1e9 + 7;
// const int mod = 998244353;
// const int mod = 360 * 12 * (double)1e10;
const int inf = 1e18 + 5;
const int infi = 2e9;
using namespace std;
using namespace __gnu_pbds;

main()
{
    fastread;
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n; int a[n+1]; f(i, 1, n+1) cin>>a[i];
        int pos[n+1]; f(i, 1, n+1) pos[a[i]] = i;
        bool fl = true;
        f(i, 1, n+1)
            if((i%2) != (pos[i]%2))
                fl = false;
        if(not fl){ cout<<"-1\n"; continue; }
        vector<int> ans;
        
        int b[n+1]; f(i, 1, n+1) b[i] = a[i];
        
        for(int i = n; i > 1; i -= 2)
        {
            int x = pos[i], y = pos[i-1];
            if(x > y)
            {
                reverse(a+1, a+x+1);
                ans.pb(x);
                f(j, 1, n+1) pos[a[j]] = j;
            }
            x = pos[i]; y = pos[i-1];
            
            // f(j, 1, n+1) cout<<a[j]<<" "; cout<<"\n";
            
            if(x < y-1)
            {
                reverse(a + 1, a + y);    
                ans.pb(y);
            }
            // f(j, 1, n+1) cout<<a[j]<<" "; cout<<"\n";
            
            if(a[1] != i)
            {
                reverse(a+1, a+y+2);
                ans.pb(y+1);
            }
            
            if(a[1] != i)
            {
                reverse(a+1, a+4);
                ans.pb(3);
            }
            
            reverse(a+1, a+i+1);
            ans.pb(i);
            
            f(j, 1, n+1) pos[a[j]] = j;
            
            // f(j, 1, n+1) cout<<a[j]<<" "; cout<<"\n\n";
        }
        
        cout<<ans.size()<<"\n";
        for(int i : ans) cout<<i<<" "; cout<<"\n";
        
        for(int i : ans)
            reverse(b+1, b+i+1);
        
        // f(i, 1, n+1) cout<<b[i]<<" "; cout<<"\n";
    }
}