#include<bits/stdc++.h>
#define int long long 
#define vi vector<int> 
#define mod 1000000007
#define ii pair<int,int>
#define vii vector<ii>
#define pb push_back
#define ff first
#define fill(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F0R(i,n) for (int i=0; i<(n); i++)
#define all(n) n.begin(),n.end()
#define allr(n) n.rbegin(),n.rend()
#define INF 1e18
using namespace std;
 
int32_t main(){
	int t;cin>>t;
	while(t--){
		int n = 40;
		int ar[n]{};
		int l,r;cin>>l>>r;
		if(l%2==0 && r%2==0){
			ar[0] = (r-l)/2;
		}
		else if(l%2==0 && r%2==1){
			ar[0] = (r-l)/2 + 1;
		}
		else if(l%2==1 && r%2==0){
			ar[0] = (r-l)/2 + 1;
		}
		else if(l%2==1 && r%2==1){
			ar[0] = (r-l)/2 + 1;
		}
		for(int i=1;i<n;i++){
			int p = (1<<i);
			int q = (1<<(i+1))-1;
			if(l <= p){
				if(r>=q){
					ar[i]=q-p+1;
				}
				else{
					ar[i]=r-p+1;
				}
			}
			else{
				if(r>=q){
					ar[i]=q-l+1;
				}
				else{
					ar[i]=r-l+1;
				}
			}
		}
		// for(int i=0;i<30;i++)cout<<ar[i]<<" ";
		int mx=*max_element(ar,ar+n);
		cout<<r-l+1-mx<<'\n';
	}
}