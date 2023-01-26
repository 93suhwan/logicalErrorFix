//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define uni(x) sort(all(x)),x.resize(unique(all(x))-x.begin());
#define GETPOS(c,x) (lower_bound(all(c),x)-c.begin())
#define lown1(x,val) low(in(x),val)-x
#define lowm1(x,val) low(im(x),val)-x
#define low1(x,nums,val) low(x+1,x+nums+1,val)-x
#define mst(x,val) memset((x),val,sizeof((x)))
#define ls rt<<1
#define rs rt<<1|1
#define lson rt<<1,l,M
#define rson rt<<1|1,M+1,r
#define PI acos(-1)
#define MM int M=(l+r)>>1;
#define fu(i,r,t) for(int i=r;i<=t;i++)
#define fd(i,r,t) for(int i=r;i>=t;i--)
#define fh(i,be,e) for(int i=head[be];~i;i=e[i].next)
#define fa(i,V) for(auto i:V)
#define far(i,V) for(auto &i:V)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lcm(a,b) ((a)*(b))/__gcd(a,b)
#define cp(i,ans) printf("%.if",ans);
#define cpp(i,ans) cout<<setprecision(i)<<fixed<<ans<<endl;
#define ppb pop_back
#define ppf pop_front
#define pb push_back
#define pf push_front
#define pq priority_queue
#define lowbit(x) ((x)&(-x))
#define all(V) V.begin(),V.end()
#define ms multiset
#define mod(x) (((x)<0)?(x)%mum+mum:(x)%mum)
#define vc vector
#define vct vector<int>
#define SET set<int>
#define dq deque<int>
#define out(i) cout<<(i)<<endl;
#define fi first
#define se second
#define fun(i) fu(i,1,n)
#define fut(i) fu(i,1,t)
#define fum(i) fu(i,1,m)
#define ld long double
#define umap unordered_map
#define Umap unordered_map<int, int, custom_hash>
#define P pair<int,int>
#define mk make_tuple
#define eps 1e-6
//Remember cancel"#define endl '\n'" in interactive questions or use "<<flush"
#define endl '\n'
#define low lower_bound
#define upp upper_bound
#define yn(key) out(key?"YES":"NO")
//#define yn(key) out(key?"Yes":"No")
#define in(i) i+1,i+1+n
#define im(i) i+1,i+1+m
#define ik(i,k) i+1,i+1+k
#define bffs(i) __builtin_ffs(i)
#define bcount(i) __builtin_popcount(i)
#define bone(i) ((1<<i)-1)
#define db double
#define ll long long
#define got(container,num) get<num-1>(container)
#define int long long
#define print(a,n) fun(i)cout<<a[i]<<(i!=n?' ':endl);
#define outcase(x) cout<<"Case #"<<(++case_of_T)<<": "<<(x)<<endl;
#define ptcase(x) printf("Case #%d: %d\n",++case_of_T,x);
#define plcase(x) printf("Case #%lld: %lld\n",++case_of_T,x);
using namespace std;
struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31); }size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM); }};
//Remember to cancel the line below and declare INT=INT_MAX/2; when you want to change long to int
const int INF=LLONG_MAX/4,SINF=0x3f3f3f3f,Lim=1<<20,MINF=LLONG_MAX;
//const int INF=INT_MAX/4,SINF=0x3f;
// use C:printf("%.16f", x);  ->  printf("%.10f", x); can accelerate the program
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};//down up left right
const int maxn=1e6+1e5;
int mum=1e9+7;
//const int mum=998244353;
int n,m,a[maxn],b[maxn],ans,case_of_T;
vct h;
int jiu[10];
void solve()
{
    cin>>n>>m;
    fun(i)cin>>a[i];
    a[0]=-1;
    int have=0;b[0]=1;
    fu(i,1,n-1)
    {
        int tohave=jiu[a[i+1]-a[i]];
        if(tohave+have>=m)
        {
            out((m-have+1)*b[a[i]]+jiu[a[i]])
            return;
        }else{
            have+=tohave;
        }
    }
    out((m-have+1)*b[a[n]]+jiu[a[n]])
    return ;
}
main()
{
    IOS
    b[0]=1;
    fu(i,1,10)b[i]=b[i-1]*10;
    fu(i,1,10)jiu[i]=jiu[i-1]*10+9;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
