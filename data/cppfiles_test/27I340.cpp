 /*                 कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ||
                    By the authority of god       ****author-Tushar Upadhyay****

 */
        #include <bits/stdc++.h> 
        #include <ext/pb_ds/assoc_container.hpp>
        using namespace std; 
        using namespace __gnu_pbds;
        #define ll long long
        const ll mod = 1e9+7;
        //const ll mod= 998244353;
        const ll INF = 1ll<<62;
        const long double pi=3.1415926535897932384626433832795;
        #define fo(i,n) for(ll i=0;i<(ll)n;++i)
        #define fos(j,i,n) for(ll j=i;j<(ll)n;++j)
        #define all(v) v.begin(),v.end()
        //#define endl "\n"
        #define dis(k) cout << k << endl
        #define ret(k) { dis(k); return;}
        #define ror(i,n) for(ll i=(ll)n-1;i>=0;--i)
        #define ve vector
        #define fi first
        #define se second
        #define pb push_back
        #define eb emplace_back
        #define setz(a) memset(a,0,sizeof(a))
         #define setn(a,n) memset(a,n,sizeof(a))
        #define seti(a) memset(a,0x7f,sizeof(a))
        #define setmi(a) memset(a,0xc0,sizeof(a))
        typedef ve< ll > vi;
        typedef ve< vi > vvi;
        typedef pair< ll ,ll > ii;
        typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indset;
        
        
         vector<vector<ll>>day;
         ll lmax(ll a,ll b){
             if(a>b)
             return a;
             return b;
         }
        ll lmin(ll a,ll b){
             if(a<b)
             return a;
             return b;
         }
ll const maxn=2000005;

// ll dp[maxn];
// ll fact[maxn];
// ll power(ll x, ll y)
// {
//     ll res=1;
//     x=x%mod;
//      if(x==0)
//          return 0;
//      else
//      {
//         while(y)
//         {
//             if(y&1)
//                 res=(res*x)%mod;
//             y=y>>1;
//             x=(x*x)%mod;
//         }
//     }
//     return res;
// }
// ll minverse(ll n, ll p)
// {
//     return power(n,p-2);
// }
// ll ncr(ll n, ll r)
// {
//     if(n<r)
//         return 0;
//     ll num=fact[n];
//     ll den1=minverse(fact[n-r],mod);
//     ll den2=minverse(fact[r],mod);
//     ll ans=(num%mod*den1%mod*den2%mod)%mod;
//     return ans;
// }
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll minp;
    if(m>n*(n-1)/2|| m<n-1)
    minp=INF;
    else if(m==n-1)
    minp=n-1;
    else if(m==n*(n-1)/2)
    minp=1;
    else
    minp=2;
    if(minp<k-1)
    dis("YES");
    else
    dis("NO");
}      int main(){
        	ios_base::sync_with_stdio(false);
        	cin.tie(NULL);
        	ll t=1;
            cin >> t;         
            //ll temp=t;
            // fact[0]=1;
            // fact[1]=1;
            // fos(i,2,200005)
            // fact[i]=(fact[i-1]%mod*i%mod)%mod;          
        	while(t--){
             //cout<<"Case #"<<temp-t<<": ";
              solve();
             
            }
 
        return 0;
      }
      