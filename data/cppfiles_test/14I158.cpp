#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
#define vec(T) vector<T>
#define printv(v) for(auto i: v)cout<<i<<" ";cout<<"\n";
#define scanv(v) for(auto& i: v)cin>>i;
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
	int n,k;cin>>n>>k;
	int a[n],dp[n]={0},t[n];
	for(int i=0;i<n;i++){
		cin>>a[i];t[i]=i+1-a[i];
	}
	if(t[0]==0)dp[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(t[j]<0)continue;
			else if(t[i]+dp[j]>i)continue;
			else {
				amax(dp[i],dp[j]+1);
			}
		}
	}

	int res=n;
	for(int i=0;i<n;i++){
		if(t[i]<0)continue;
		else if(dp[i]<k)continue;
		else {
			amin(res,t[i]);
		}
	}

	if(res!=n)cout<<res<<"\n";
	else cout<<"-1\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}