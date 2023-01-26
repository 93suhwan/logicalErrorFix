#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cout<<#x<<":"<<x<<" ";
#define mod 1000000007;
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve(){

}

int32_t main()
{
	IOS;
	int t=1;
	cin >> t;
	
	while(t--)
	{
		int n,k;
		cin >> n>>k;
		
		vector<int> v(n);

		int ans=0,mx=INT_MIN,mn=INT_MAX,m=0;
		vector<int> x,y;

		for(int i = 0; i < n; i++){
			cin>> v[i];
			
			if(v[i]>0){
				y.pb(v[i]);
			}
			else if(v[i]<0){
				x.pb(v[i]);
			}
			
			m=max(m,abs(v[i]));
		}

		bool f=0,g=0;
		
		sort(all(y));
		sort(all(x));
		reverse(all(x));
		int n1=sz(y),n2=sz(x);
		
		int pending=k;
		
		for(int i=0;i<n1;i++){
			int val = y[i];
			
			if(val==m){
				f=1;
				int remain = n1-i;
				if(pending>=remain){
					g=1;
					pending-=remain;
					break;
				}
				else{
					ans+=val*2;
					g=0;
					i+=(pending-1);
					pending=k;
				}
			}
			else{
				if(pending>1){
					g=1;
					pending--;
				}
				else{
					g=0;
					pending=k;
					ans+=val*2;
				}
			}
			
			if(g && i!=n1-1 && y[i+1]==m && val!=m && pending<(n1-(i+1))){
				ans+=y[i-1]*2;
				pending=k;
			}
				
			// cout<<i<<":"<<ans<<"  ";
			if(pending==0) pending=k;
		}
		// watch(g);		watch(f);
		// cout<<"\n";
		if(g && f) ans+=y[n1-1];
		else if(g) ans+=y[n1-1]*2;
		///////
		pending=k;g=0;
		bool q=1;
		if(f) q=0;
		
		for(int i=0;i<n2;i++){
			int val = abs(x[i]);
			
			if(val==m && f==0){
				int remain = n2-i;
				if(pending>=remain){
					g=1;
					pending-=remain;
					break;
				}
				else{
					ans+=val*2;
					g=0;
					i+=(pending-1);
					pending=k;
				}
				// f=1;
			}
			else{
				if(pending>1){
					g=1;
					pending--;
				}
				else{
					g=0;
					pending=k;
					ans+=val*2;
				}
			}
			
			if(g && i!=n2-1 && abs(x[i+1])==m && val!=m && f==0 && pending<(n2-(i+1))){
				ans+=abs(x[i-1])*2;
				pending=k;
			}
			
			// cout<<i<<":"<<ans<<"  ";
			if(pending==0) pending=k;
		}
		if(g && q) ans+=abs(x[n2-1]);
		else if(g && !q) ans+=abs(x[n2-1])*2;

		// cout<<"\n";
		///////
		
		cout << ans << "\n";
	}
	return 0;
}
