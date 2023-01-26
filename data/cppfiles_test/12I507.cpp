#include<bits/stdc++.h>
#include <iomanip>
#define ll long long int
#define ld long double
#define f first
#define inf 100000000000000000
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define s second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define Sort(a) sort(a.begin(),a.end());
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
ll const mod=1000000007;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// ordered_set os.find_by_order os.order_of_key
// b/w l and r os.order_of_key(r+1)-order_of_key(l)

// ll arr1[1000009];
// //ll parent[1000009];
// set<ll> sieve;
// void sievefun(ll n){
//     for(ll i=2;i<=n;i++){
//         if(arr1[i]==0){
//  //              parent[i]=i;
//             for(ll j=i*i;j<=n;j+=i){
//    //         	if(arr1[j]==0)parent[j]=i;
//                 arr1[j]=1;
//             }
//         }
//     }
//     for(int i=2;i<=n;i++){
//     	if(arr1[i]==0)sieve.insert(i);
//     }
// }
ll power(ll x, ll y,ll m) {
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2,m)%m;
	if (y%2 == 0)
		return ((temp)*(temp))%m;
	else
		return (((x)%m)*((temp*temp)%m))%m;
}

// ll fac[1000009];
// void factorial(){
// 	fac[0]=1;
// 	for(int i=1;i<=1000000;i++)fac[i]=(i*fac[i-1])%mod;
// }
// ll ncr(ll n,ll r){
// 	return (fac[n]*((power(fac[r],mod-2)*power(fac[n-r],mod-2))%mod))%mod;
// }

int main()
{	//sievefun(1000000);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll ans = 1;
		if(n%2){
			if(m%2)ans = 0;
			else{
				ll temp = m/2;
				if(temp%2){
					if(k%2==0 or k < temp)ans = 0;
				}else{
					if(k%2 or k < temp) ans = 0;
				}
			}
		}else{
			if(k%2) ans = 0;
		}
		if(ans)cout<<"YES\n";
		else cout<<"NO\n";
	}	

}