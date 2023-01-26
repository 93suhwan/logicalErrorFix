#include "bits/extc++.h"
using namespace std; using namespace __gnu_pbds; using ll = long long; using pbds = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>; using vll = vector<ll>; using vvll = vector<vll>;
ll MX = 1e6+1, mod = 1e9+7, inf = 1e18; double eps = 1e-9; void setMod(ll m = 998244353){ mod = m; }
#define endl '\n'
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)
#define mop(a, op, b) ((a%mod op b%mod) + mod)%mod
/* get(array, n); get(n, array1, array2); get(2D array, n, m); get(...); */ void get(ll* a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } void get(vll& a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } void get(ll n, ll* a, ll* b){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } void get(ll n, vll& a, vll b){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } void get(ll** a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } void get(vvll& a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } 
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v){ for(auto i = v.begin(); i != v.end(); i++) out<<(*i)<<' '; return out; } template<typename T> ostream& operator<<(ostream& out, const set<T>& s){ out<<'['; for(auto i = s.begin(); i != s.end(); i++) out<<(i!=s.begin()?", ":"")<<(*i); return(out<<']'); } template<typename T1, typename T2> ostream& operator<<(ostream& out, const map<T1, T2>& m){ out<<'{'<<endl; for(auto x : m) out<<"    "<<x.first<<" -> "<<x.second<<endl; return(out<<'}'); } template<typename T> T mpow(T x, ll n){ T ans = 1; while(n){ if(n&1) ans = mop(ans, *, x); n >>= 1, x = mop(x, *, x); } return ans; } ll modinv(ll x){ return mpow(x, mod-2); } vll FACT(1, 1); ll ncr(ll n, ll r){ if(n < r) return 0; while(n >= FACT.size()) FACT.push_back(mop(FACT[FACT.size()-1], *, FACT.size())); return mop(FACT[n],*,mop(modinv(FACT[r]),*,modinv(FACT[n-r]))); } ll fact(ll n){ while(n >= FACT.size()) FACT.push_back(mop(FACT[FACT.size()-1], *, FACT.size())); return FACT[n]; }
void zenit(bool tieIO = 1){ cout<<fixed<<setprecision(9); if(tieIO){ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }} mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int main(){
    zenit();
    test{
            ll n;
            cin>>n;
            ll arr[n];
            get(arr,n);
            if(n==1){cout<<"YES"<<endl;cout<<arr[0]<<endl;continue;}
            ll sum=0;
            for(ll i=0;i<n;i++)sum+=arr[i];
            ll val=(n*(n+1))/2;
            ll ratio=sum/val;
            if(ratio<n || sum%val!=0)
            {
                cout<<"NO"<<endl;continue;
            }
            ll res[n]={0};
            bool flag=true;
            for(ll i=0;i<n && flag;i++)
            {
               ll var=arr[i]-arr[(i+1)%n];
               var+=ratio;
                if(var%n!=0 && var==0)
                {cout<<"NO"<<endl;flag =false;}
                res[(i+1)%n]=var/n;
            }
            if(flag)
            {cout<<"YES"<<endl;
            for(ll i=0;i<n;i++)
            cout<<res[i]<<" ";
            cout<<endl;
            }
    }
return 0;
}