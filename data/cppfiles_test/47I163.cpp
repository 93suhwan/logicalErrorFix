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
				x.pb(abs(v[i]));
			}
			
			m=max(m,abs(v[i]));
		}

		bool g=0;
		
		sort(all(y));
		sort(all(x));
		// reverse(all(x));
		int n1=sz(y),n2=sz(x);
		
		int pending=k;
		
		for(int i=0;i<n1;i++){
			int val = y[i];
			
			if(pending>1){
				g=1;
				pending--;
			}
			else{
				g=0;
				pending=k;
				ans+=val*2;
			}
			
			// cout<<i<<":"<<ans<<"  ";
			if(pending==0) pending=k;
		}
		// watch(ans);
		if(g){
			ans+=y[n1-1]*2;
		}
		// watch(ans);
		
		bool f=0;
		auto it = lower_bound(all(y),m);
		if(it!=y.end()){
			int z = it-y.begin();
			int total = n1-z;
			int remain = n1-total;
			
			if(remain%k!=0 && sz(y)>k){
				int last = y[z]-y[z-1];
				// watch(last);
				// watch(y[z-1]);
				// watch(y[z]);
				ans-=last*2;
				f=1;
			}
		}

// 15 3
// -5 -10 -15 6 5 8 3 7 4 15 15 15 15 -15 -15

		
		///////
		pending=k;g=0;
// watch(n2);
		for(int i=0;i<n2;i++){
			int val = abs(x[i]);

			if(pending>1){
					g=1;
					pending--;
			}
			else{
				// cout<<"here "<<i<<" ";
				g=0;
				pending=k;
				ans+=val*2;
			}
			
			// cout<<i<<":"<<ans<<"  ";
			if(pending==0) pending=k;
		}
		// watch(ans);
		if(g){
			ans+=x[n2-1]*2;
		}
		// watch(ans);
		ans-=(m);
		
		it = lower_bound(all(x),m);
		if(it!=x.end()){
			int z = it-x.begin();
			int total = n2-z;
			int remain = n2-total;
			
			if(remain%k!=0 && sz(x)>k){
				// cout<<"here2 ";
				int last = x[z]-x[z-1];
				ans-=last*2;
				// watch(last);
				// watch(x[z-1]);
				// watch(x[z]);
				f=1;
			}
		}
		// cout<<"\n";
		///////
		
		cout << ans << "\n";
	}
	return 0;
}
