#include<bits/stdc++.h>
using namespace std;
#define ff               first
#define ss               second
#define nl              cout<<'\n'
#define pr(s)           cout<<s;
#define gf              cout<< ' ';
#define pb              push_back
#define pi              2*acos(0.0)
#define sz(x)           (int)x.size()
#define no              printf("No\n")
#define yes             printf("Yes\n")
#define fillVec(a, v)   fill(all(a), v)
#define btz(a)          __builtin_ctz(a)
#define all(v)          v.begin(),v.end()
#define parity(a)       __builtin_parity(a)
#define countone(a)     __builtin_popcount(a)
#define mem(a,v)        memset(a, v, sizeof(a))
#define rsort(a)        sort(a), reverse(all(a))
#define fileinput       freopen("input.txt","r",stdin) ;
#define fileoutput      freopen("output.txt","w",stdout) ;
#define precision(x)    cout << setprecision(x) << fixed
#define un(a)           sort(a), (a).erase(unique(all(a)),a.end())
#define faster          ios_base::sync_with_stdio(false);cin.tie(NULL)

/**------- ShortCuts----------*/
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<ll, ll>        pii;
typedef pair<ll, ll>          pll;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<ll>            vl;
typedef vector<pii>           vii;
typedef vector<iii>           viii;
typedef vector<vi>            vvi;
typedef map<int, int>         mapii;
typedef map<int, bool>        mapib;
typedef map<int, string>      mapis;
typedef map<ll, ll>           mapll;
typedef map<ll, bool>         maplb;
typedef map<ll, string>       mapls;
typedef set<int>              seti;


ll setbit(ll num,ll nth) {return num|=(1LL<<nth);}
ll clearbit(ll num,ll nth) {return num&=~(1LL<<nth);}
ll toggle(ll num,ll nth) {return num^=(1LL<<nth);}
ll check(ll num,ll nth) {return (num>>nth)&1LL;}
ll change(ll num,ll nth,ll val) {return num^=(-val^num)&(1LL<<nth);}

int fx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };///knight
int fy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

/**--------Loops--------------*/
#define forab(i, a, b)      	for(__typeof(b) i=(a); i<=(b); i++)
#define for0(i, n)          	frab(i, 0, n-1)
#define for1(i, n)          	frab(i, 1, n)

/** Range Query */
#define left(p) 	(2*p)
#define right(p) 	(2*p)+1
#define mid(l,r) 	(l + (r-l)/2)
#define bitf(i)		(i & (-i))

/**--------Constant------------*/
#define eps                1e-9
#define mx2                101
#define mx3                1001
#define mx4                10001
#define mx5                100001
#define mx6                1000001
#define INF                0x3f3f3f3f
#define mx                 5000003
#define mod                1000000007

/**-------Upper & Lower Bound-------*/
#define lb(a, v)            (lower_bound(all(a), v))
#define ub(a, v)            (upper_bound(all(a), v))

ll dx[4]={+1,-1,+0,-0};
ll dy[4]={+0,-0,+1,-1};



ll n,k;
string str,s;
ll a[mx];

int main()
{
    faster;
    int tt=1,cas=0;

    cin>>tt;
    while(tt--){

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll g=a[1];

        for(int i=1;i<=n;i+=2){
            g=__gcd(a[i],g);
        }
        ll ok=0;
        for(int i=1;i<=n;i+=2){
            if(i+1<=n && a[i+1]%g==0) ok=1;
        }
        if(ok==0){
            cout<<g<<endl;
            continue;
        }
        g=a[2];
        for(int i=2;i<=n;i+=2){
            g=__gcd(a[i],g);
        }
        ok=0;
        //cout<<g<<endl;
        for(int i=2;i<=n;i+=2){
            if(a[i-1]%g==0) ok=1;
        }
        //cout<<ok<<" "<<g<<endl;
        if(ok==0){
            cout<<g<<endl;
            continue;
        }
        cout<<0<<endl;











    }

    return 0;
}
