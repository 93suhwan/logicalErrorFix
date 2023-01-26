
// Problem : C. Paprika and Permutation
// Contest : Codeforces - Codeforces Round #761 (Div. 2)
// URL : https://codeforces.com/contest/1617/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define rep(i,a,n) for(lli i=a;i<n;i++)
#define rrep(i,n,a) for(lli i=n-1;i>=a;i--) 
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define sz(v) v.size()
#define pi 3.141592653589793238
#define fr first
#define sc second
#define ins insert
const lli mod=1e9+7;
const int N = 1e5 + 5;
using namespace std;
lli lcm(lli a,lli b) { return (a/__gcd(a,b))*b;}
lli min(lli a,lli b,lli c) {return min(a,min(b,c));}
lli max(lli a,lli b,lli c) {return max(a,max(b,c));}
void solve(){
	lli n,a,b,c,k;
	cin>>n;
	lli ar[n];
	rep(i,0,n) cin>>ar[i];
	sort(ar,ar+n);
	bool ok=true;
	set<lli>st;
	rep(i,0,n) st.insert(i+1);
	
	
	rep(i,0,n){
		if(ar[i]<=n) st.erase(ar[i]);
	}
	
	
	lli ans=0;
	
	
	rep(i,0,n){
		if(ar[i]>n){
			k=*st.begin();
			if(2*k<ar[i]){
				st.erase(k);
				ar[i]=k;
				ans++;
			}
		}
	}
	
	if(st.size()==0 and ok) cout<<ans<<endl;
	else cout<<"-1\n";
	
	
}
int main()
{

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	lli t=1;
	cin>>t;
	while(t--){
		solve();
	}

	
	
	return 0;
}