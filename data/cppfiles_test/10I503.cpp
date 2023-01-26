#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define fo(i,a,n) for (int i = a; i <(int)n ; i++)
#define fo1(i,a,n) for (int i = a;i<(int)n;)
#define rfo(i,k,n) for (int i = k; i >= n; --i)

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(long long t) {cerr << t;}
void _print(long double t) {cerr<<t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void print(int t) {cout << t;}
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}

template <class T, class V> void print(pair <T, V> p) {cout << print(p.ff); cout<<" "; print(p.ss); }
template <class T> void print(vector <T> v) { for (T i : v) {print(i); cout << " ";}}
template <class T> void print(set <T> v) { for (T i : v) {print(i); cout << " ";}}
template <class T> void print(multiset <T> v) { for (T i : v) {print(i); cout << " ";}}
template <class T, class V> void print(map <T, V> v) { for (auto i : v) {print(i); cout << " ";} }

#define dbg(x) cerr << #x <<" "; _print(x);
#define test int t;cin>>t;while(t--)
#define ll long long
#define ld long double
#define vll vector<ll>
#define Bp __builtin_popcount
#define pll pair<ll,ll>
#define I insert
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define fu(v) (v),0,(v).size()
#define Mod2 (int)1000000007
#define Mod1 (int)998244353
#define fio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

vi fa,sv;

void sieve(){fo(i,0,1e6+5)sv.pb(i);fo(i,2,1e6+5){for(int j = min(i*1ll*i,(ll)1e6+5);j<1e5+5;j+=i)sv[j] = min(sv[j],i);}}
ll mul(ll a, ll b) {return((a%Mod1 *1ll* b%Mod1)%Mod1 + Mod1)%Mod1;}
ll mul1(ll a,ll b, ll Mod) {ll res = (a)*1ll*(b); res %=Mod; if(res < 0) res += Mod; return res;}
int mad(int a,int b){ll res = ((a%Mod1 + b%Mod1)%Mod1 + Mod1)%Mod1;return res;}
ll mad1(ll a,ll b, ll Mod) {ll res = ((a%Mod + b%Mod)%Mod + Mod)%Mod;return res;}
int power(int x,int y){ll res = 1;while(y){if(y&1)res = mul(res,x);y>>=1;x=mul(x,x);}return res;}
int inv(int x){return power(x,Mod1-2);}
void fact(){fa.pb(1);fo(i,1,1e6 + 5)fa.pb(mul(fa.back(),i));}
int comb(int n,int r){if (r > n)return 0;ll res = mul(fa[n],inv(mul(fa[n-r],fa[r])));return res;}
void pv(auto v,int a,int sz){fo(i,a,sz)cout<<v[i]<<" ";cout<<endl;}
void rpv(vi v,int sz,int a){rfo(i,sz,a)cout<<v[i]<<" ";cout<<endl;}
void pa(auto z[],int a,int sz){fo(i,a,sz)cout<<z[i]<<" ";cout<<endl;}
void rpa(int z[],int a,int sz){rfo(i,a,sz)cout<<z[i]<<" ";cout<<endl;}
void Google(ll ans,int cnt){cout<<"Case #"<<(cnt)<<": "<<ans<<endl;}

int main()
{
    test
    {
        int n,k,x;
        cin>>n>>k;
        vi v(n);
        map<int,vector<int>>mp1;
        fo(i,0,n)
        {
            cin>>x;
            mp1[x].pb(i);
        }
        vi ans(n);
        fo(i,1,k+1)
        {
            auto it = mp1.begin();
            while(it != mp1.end()){
                if ((it->se).size())
                    ans[(it->se).back()] = i,(it->se).pop_back(),it++;
                else
                {
                    auto it1 = it;
                    it++;
                    mp1.erase(it1);
                }
            }
        }
        pv(ans,0,ans.size());
    }
}
