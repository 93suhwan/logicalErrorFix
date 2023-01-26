//clear adj and visited vector declared globally after each test case
//check for long long overflow  
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Incase of close mle change language to c++17 or c++14  
#include <bits/stdc++.h>     
#include <ext/pb_ds/assoc_container.hpp>  
#define int long long    
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007ll //998244353ll
#define lld long double
#define mii map<int, int> 
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
const long long N=200005, INF=2000000000000000000;
lld pi=3.1415926535897932;
int lcm(int a, int b)
{
    int g=__gcd(a, b);
    return a/g*b;
}
int power(int a, int b, int p)
    {
        if(a==0)
        return 0;
        int res=1;
        a%=p;
        while(b>0)
        {
            if(b&1)
            res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }
int ans[105][105];
char fin[105][105];
void fun(int n, int m)
{
    cout<<n<<" "<<m<<"\n";
    int a[n+2][m+2];
    fill(a, -1);
    rep(i,1,n+1)
    {
        rep(j,1,m+1)
        {
            a[i][j]=ans[i-1][j-1];
        }
    }
    rep(i,0,n+2)
    {
        rep(j,0,n+2)
        fin[i][j]='?';
    }
    rep(i,1,n+1)
    {
        rep(j,1,m+1)
        {
            if(fin[i][j]!='?')
            continue;
            rep(k,0,26)
            {
                char c=(char)('a'+k);
                if(c==fin[i-1][j] ||c==fin[i][j-1])
                continue;
                if(i+1<=n && a[i][j]==a[i+1][j])
                fin[i][j]=fin[i+1][j]=c;
                else if(j+1<=m)
                fin[i][j]=fin[i][j+1]=c;
                break;
            }
        }
    }
    // if(m==17)
    // {
    //     print2d(ans, n-1, m-1);
    //     print2d(a, n, m);
    // }
    rep(i,1,n+1)
    {
        rep(j,1,m+1)
        cout<<fin[i][j];
        cout<<"\n";
    }
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        if(n&1)
        {
            int req=m/2;
            if(k>=req && (k-req)%2==0)
            {
                cout<<"YES\n";
                int cur=1;
                fill(ans, 0);
                for(int i=0;i<m;i+=2)
                {
                    ans[0][i]=ans[0][i+1]=cur++;
                    k--;
                }
                for(int i=1;i<n;i+=2)
                {
                    for(int j=0;j<m;j+=2)
                    {
                        if(k==0)
                        break;
                        ans[i][j]=ans[i][j+1]=cur++;
                        ans[i+1][j]=ans[i+1][j+1]=cur++;
                        k-=2;
                    }
                }
                for(int i=0;i<n-1;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(ans[i][j]==0 && ans[i+1][j]==0)
                        ans[i][j]=ans[i+1][j]=cur++;
                    }
                }
                // print2d(ans, n-1, m-1);
                fun(n, m);
            }
            else
            cout<<"NO\n";
        }
        else if(m&1)
        {
            int op=((n*m)/2)-k;
            int req=n/2;
            if(op>=req && (op-req)%2==0)
            {
                cout<<"YES\n";
                int cur=1;
                fill(ans, 0);
                for(int i=0;i<n;i+=2)
                {
                    ans[i][0]=ans[i+1][0]=cur++;
                    op--;
                }
                for(int i=1;i<m;i+=2)
                {
                    for(int j=0;j<n;j+=2)
                    {
                        if(op==0)
                        break;
                        ans[j][i]=ans[j+1][i]=cur++;
                        ans[j][i+1]=ans[j+1][i+1]=cur++;
                        op-=2;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m-1;j++)
                    {
                        if(ans[i][j]==0 && ans[i][j+1]==0)
                        ans[i][j]=ans[i][j+1]=cur++;
                    }
                }
                // print2d(ans, n-1, m-1);
                fun(n, m);
            }
            else
            cout<<"NO\n";
        }
        else if(k%2==0)
        {
            cout<<"YES\n";
            int cur=1;
            fill(ans, 0);
            for(int i=0;i<n;i+=2)
            {
                for(int j=0;j<m;j+=2)
                {
                    if(k==0)
                    break;
                    ans[i][j]=ans[i][j+1]=cur++;
                    ans[i+1][j]=ans[i+1][j+1]=cur++;
                    k-=2;
                }
            }
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(ans[i][j]==0 && ans[i+1][j]==0)
                    ans[i][j]=ans[i+1][j]=cur++;
                }
            }
            // print2d(ans, n-1, m-1);
            fun(n, m);
        }
        else
        cout<<"NO\n";
    }
}