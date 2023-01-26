#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define endl ("\n")
#define mp make_pair
#define lb lower_bound
#define ff first
#define inf 1e18
#define ss second
#define cn continue
#define br break
#define ins insert
#define int long long
#define bit(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define up upper_bound
#define read(a,n) rep(i,0,n){cin>>a[i];}
#define print(a,n) rep(i,0,n) cout<<a[i]<<" ";
#define yy cout<<"YES"<<endl;
#define nn cout<<"NO"<<endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define lld double
#define pre(x) setprecision(x)
#define pi 3.14159265359
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool cp(pair<int, int> a, pair<int, int> b)
{


    return a.ff < b.ff;
}

bool bipartiteDfs(int node, vector<int> adj[], int color[])
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it, adj, color))
            {
                return false;
            }
        } else if (color[it] == color[node]) return false;
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartiteDfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}



int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = clock();
    int t = 1 ;
    cin >> t ;
    while (t--)
    {
        int n;
        cin >> n;
        int ans[n];
        vector<pair<int, int> >liked, unliked;
        int a[n];
        read(a, n);
        string s;
        cin >> s;
        rep(i, 0, n)
        {
            if (s[i] == '1')
            {
                liked.pb({a[i], i});
            }
            else
            {
                unliked.pb({a[i], i});
            }
        }
        sort(all(liked));
        sort(all(unliked));
        int y = n;
        for (auto x : liked)
        {
            ans[x.ss] = y;
            y--;
        }
        for (auto x : unliked)
        {
            ans[x.ss] = y;
            y--;
        }


        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
    cerr << "\nTIME: " << (long double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
    T = clock();
    return 0;
}

