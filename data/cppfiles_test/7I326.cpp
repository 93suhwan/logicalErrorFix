//╔═╦╗╔╦╗╔═╦═╦╦╦╦╗╔═╗
//║╚╣║║║╚╣╚╣╔╣╔╣║╚╣═╣
//╠╗║╚╝║║╠╗║╚╣║║║║║═╣
//╚═╩══╩═╩═╩═╩╝╚╩═╩═╝

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define nl "\n"
#define ll long long
#define st first
#define nd second
#define PII pair<int,int>



//#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>


using namespace std;
//using namespace __gnu_pbds;

void input()
{
    #define task "tenbai"
    if(fopen("BACHO.inp","r")){
        freopen("BACHO.inp","r",stdin);
        freopen("BACHO.out","w",stdout);
    }
    else if(fopen("BACHO.in","r")){
        freopen("BACHO.in","r",stdin);
        freopen("BACHO.out","w",stdout);
    }
    else if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    else if(fopen(task".in","r")){
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
}

#define int ll
const int maxn=2e5+5,mod=1e9+7,oo=1e18;
//const double pi=atan2(0,-1);

int t,n,a[maxn],dp[maxn][40];

int solve(int vt,int i)
{
    int cnt=vt-i+1;
    int d=log2(cnt);
    return __gcd(dp[vt-(1<<d)+1][d],dp[i][d]);
}


int32_t main()
{
    input();
    fastio();

    cin>>t;
    for(int o=0;o<t;++o){
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        if(n<=2){
            cout<<n<<nl;
            continue;
        }
        int ans=2,vt=2;;
        for(int i=1;i<=n;++i) dp[i][0]=abs(a[i-1]-a[i]);
        for(int j=1;(1<<j)<=n;++j){
            for(int i=2;i+(1<<j)-1<=n;++i){
                dp[i][j]=__gcd(dp[(1<<(j-1))+i][j-1],dp[i][j-1]);
            }
        }
        for(int i=2;i<=n;++i){
            if(vt>n) break;
            if(vt<i) vt=i;
            while(vt<=n && solve(vt,i)!=1){
                ans=max(ans,vt+2-i);
                ++vt;
            }
        }
        cout<<ans<<nl;
    }


    return 0;
}
