#include <bits/stdc++.h>
using namespace std;

#define fr first
#define NFS 	ios_base::sync_with_stdio(0) ;cin.tie(0) ;
#define fr first
#define sc second
#define qwer int
#define int long long
#define endl "\n"

bool glas(char a){
	if('a' == a || a == 'e' || 'u' == a || a == 'i' || a == 'o'){
		return true;
	}
	return false;
}
int e;
int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1){
		int y = binpow (a, n-1) * a;
	}
	else {
		int b = binpow (a, n/2);
		return (b*b)%e;
	}
}


void solve(){
	int n;
	cin>>n;
	int a[n];
	map<int,int>mp;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}

	int cnt= n/2;
	for(int i=0;i<n;i++){
		int j =0;
		if(cnt==0) return;
		while(j<=i){
			if(mp[a[i]%a[j]]==0 && i!=j && cnt>0 ||mp[a[j]%a[i]]==0 && i!=j && cnt>0 ){
				cout<<a[i]<<" "<<a[j]<<endl;
				cnt--;
			}
			j++;
		}
	}
	
}

main(){
	NFS
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}

}
 