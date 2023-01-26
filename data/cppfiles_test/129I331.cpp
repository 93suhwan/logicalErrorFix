#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vll(x) vector<ll> x
#define rep(x,s,e) for(ll x = s ; x < e ; ++x)
#define nl '\n';
 

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n,x;
		cin>>n;
		
		vi arr;
		bool mark[n+2] = {0};
		
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			arr.pb(x);
			
			if(x <= n)
				mark[x] = 1;
		}
		
		sort(arr.begin() , arr.end());
		
		int s = 1 , j = 0 , res = 0;
		
		
		while(s <= n && j < n){
			if( (arr[j] > n || mark[arr[j]] == 0) && arr[j] <= 2*s ){
				res = -1;
				break;
			}
			else{
				if(arr[j] <= n && mark[arr[j]])
				{
					if(s-1 == j)
						++s;
					
					++j;
				}
					
					
				else {
					++j;
					++s;
					++res;
				}	
				
			}
		}
		cout<<res<<nl;
		
	}

return 0;
}
