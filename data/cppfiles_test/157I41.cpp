#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define forn(i,n) for(int i=0;i<n;i++)
#define minf numeric_limits<int>::min()
#define inf numeric_limits<int>::max()
#define linf numeric_limits<long>::max()
#define lminf numeric_limits<long>::min()
#define llinf numeric_limits<long long>::max()
#define llminf numeric_limits<long long>::min()
#define forln(i,n) for(long i=0;i<n;i++)
#define forlln(i,n) for(long long i=0;i<n;i++)
#define For(i,s,e) for(int i=s; i<=e; i++)
#define rFor(i,s,e) for(int i=s; i>=e; i--)
#define ll long long
#define l long
#define ivec vector<int>
#define lvec vector<l>
#define llvec vector<ll>
#define iimap map<int, int>
#define llmap map<ll, ll>
#define illmap map<int, ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ipair pair<int,int>
#define lpair pair<l,l>
#define llpair pair<ll,ll>
#define vec vector
#define CASE int t; cin>>t; while(t--)
#define len(a) a.size()
#define all(a) a.begin(), a.end()

using namespace std;
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
template<typename T> istream & operator>>(istream& in, vec<T> &a){
	forn(i,a.size()) in>>a[i];
	return in;
}   
template<typename T> ostream & operator<<(ostream& out, vec<T> &a){
	forn(i,a.size()) out<<a[i]<<" ";
	out<<endl;
	return out;
}  
template<typename T> T max(vec<T> a){
	T ans=numeric_limits<T>::min();
	forn(i, a.size()) ans=max(ans, a[i]);
	return ans;
}
template<typename T> T min(vec<T> a){
	T ans=numeric_limits<T>::max();
	forn(i, a.size()) ans=min(ans, a[i]);
	return ans;
}

ll mod=998244353;
ll modpow(ll u, ll p, ll mod){
    ll ret=1;
    while(p>0){
        if(p&1) ret=(ret*u)%mod;
        u=(u*u)%mod;
        p>>=1;
    }
    return ret;
}
llvec fac(1e5+10,1), ifac(1e5+10,1);
ll modinv(ll u){
	return modpow(u,mod-2,mod);
}
ll ncr(int n, int r){
	if(n<0 || r<0 || r>n) return 0;
	return ((fac[n]*ifac[r]%mod)*ifac[n-r]%mod);
}
void init(){
	fac[0]=1;
	For(i,1,len(fac)-1) fac[i]=(fac[i-1]*i)%mod, ifac[i]=modinv(fac[i]);
}

int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif
	init();
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s; s+="1";
	int c=0;
	forn(i,n) c+=s[i]=='1'; 
	if(k==0 || c<k) return cout<<1<<endl,0;

	int st=0, en=0, ct=(s[0]=='1');
	ll ans=0;
	while(en!=n){
		while(en<n && ct<=k) ct+=(s[++en]=='1');
		cout<<st<<" "<<en<<endl;
		if(en!=n){
			ans=(ans+ncr(en-st-1,k))%mod;
		}
		else{
			ans=(ans+ncr(en-st,k))%mod;
		}
		while(st<en && ct>k) ct-=(s[st++]=='1');
	}
	cout<<ans<<endl;
}