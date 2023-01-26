#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define int long long int
#define f(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define endl "\n"
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector< vector<int> >
#define vvc vector< vector<char> >
#define vip vector< pair<int,int> >
#define pi pair<int,int>
#define mxpq priority_queue<int>
#define mnpq priority_queue<int,vi,greater<int>>
#define sz(x) x.size()
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define setBit(x) __builtin_popcount(x)
#define lb(x,num) lower_bound(all(x),num)
#define ub(x,num) upper_bound(all(x),num)
inline void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
inline int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM(int a, int b) { return a * b / GCD(a, b); }
inline int ceil(int a, int b){  return (a%b==0) ? a/b : a/b +1 ;}
inline double logb(int base,int num){ return (double)log(num)/(double)log(base);}
const int mod = 1e9+7;
const int inf = 1e18;
inline int power(int x, int y){ if(y==0)return 1;x%=mod;if(y%2)return (x*power(x*x, y/2))%mod;return power(x*x, y/2)%mod;}
inline int powe(int a,int b){ if(b<0)return 0; int res=1;f(i,1,b) res*=a;return res;}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
    int n,m;
    cin>>m>>n;
    vvi p(m+1,vi(n+1,0));
    vip ans(n+1,{0,0});
    f(i,1,m)
    {
        f(j,1,n)
        {
            cin>>p[i][j];
            ans[j]=max(ans[j],{p[i][j],i});

        }
    }
    int res=inf;
    set<int> st;
    f(i,1,n)
    {
        res=min(res,ans[i].F);
        st.insert(ans[i].S);
    }
    if(st.size()<=(n-1))
    {
        cout<<res<<endl;
        return;
    }
    res=0;
    f(i,1,n)
    {
        pi mx={0,0};
        f(j,1,n)
        {
            if(j!=i) 
            {
                int idx=ans[j].S;
                int c=min(p[idx][i],p[idx][j]);
                mx=max(mx,{c,j});
            }
        }
        int val=mx.F;
        f(j,1,m)
        {
            int c=min(p[j][i],p[j][mx.S]);
            val=max(val,c);
        }
        res=max(res,val);
    }
    cout<<res<<endl;
}
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
return 0;
}