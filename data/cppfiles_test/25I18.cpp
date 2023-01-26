#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define int long long 
#define nline '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define mp make_pair
#define pi 3.141592653589
#define INF 1e18
//using namespace __gnu_pbds;
//typedef tree<int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update>
//pbds;


auto solve(){
	string s,t;
	cin>>s>>t;
	int n = s.length();
	int m = t.length();

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int foo = 0;
			bool yes = false;
			for(int k=i;k<=j;k++){
				if(s[k] == t[foo]){
					foo++;
				} else {
					break;
				}

				if(foo == m){
					yes = true;
					break;
				}
			}

			if(yes){
				cout<<"YES"<<nline;
				return;
			}

			for(int k=j-1;k>=0;k--){
				if(s[k] == t[foo]){
					foo++;
				} else{
					break;
				}
				if(foo == m){
					yes = true;
					break;
				}
			}

			if(yes){
				cout<<"YES"<<nline;
				return;
			}
		}
	}


	cout<<"NO"<<nline;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	// t = 1;
	while(t--){
		solve();
	} 
	return 0;
}