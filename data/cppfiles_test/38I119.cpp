#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
#define endl "\n"
#define int long long
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
int powi(int x,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}
bool isPowerOfTwo(int n) 
{ 
    if (n == 0) 
        return 0; 
    while (n != 1) 
    { 
        if (n%2 != 0) 
            return 0; 
        n = n/2; 
    } 
    return 1; 
} 
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
void solve(){
    int n,m;
    cin>>n>>m;
    int pre[m]={0};
    vector<string> v(n);
    trav(x,v)cin>>x;
    FOR(i,1,n){
        FOR(j,1,m){
            if(v[i][j] =='.' && v[i][j-1] == 'X' && v[i-1][j] == 'X')pre[j] =1;
        }
    }
    FOR(j,1,m)pre[j]+=pre[j-1];
    int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        //cout<<pre[l]<<" "<<pre[r]<<endl;
        if(pre[l]==pre[r]){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    
    int t=1;
    //cin>>t;
    while(t--) solve();
 
 
    return 0;
}
