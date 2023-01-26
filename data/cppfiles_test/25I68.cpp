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

	int ind = 0;
	for(int i=0;i<n;i++){
		if(s[i] == t[ind]){
			int foo = i;
			m--;
			bool right = false;
			while(m--){
				if(foo != n-1 && s[foo+1] == t[ind+1]){
					ind++;
					foo++;
					right = true;
				} else if(foo == n-1 && right == false){
					cout<<"NO"<<nline;
					return;
				} else if(foo != 0 && s[foo-1] == t[ind+1] && right == true){
					ind++;
					foo--;
				} else{
					cout<<"NO"<<nline;
					return;
				}
			}

			cout<<"YES"<<nline;
			return;
		}
	}
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