#include <bits/stdc++.h>
using namespace std;

#define fr first
#define NFS 	ios_base::sync_with_stdio(0) ;cin.tie(0) ;
#define fr first
#define sc second
#define qwer int
#define int long long

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
int len(int x){
	int cnt=0;
	while(x>0){
		x/=10;
		cnt++;
	}	
	return cnt;
}
bool check(int x){
	
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
	sort(a,a+n);
	int cnt= (n+1)/2;
	for(int i=0;i<n;i++){
		for(int j =0;j<n;j++){
			if(i!=j && 0==mp[a[i]%a[j]] && cnt>0){
				cout<<a[i]<<" "<<a[j]<<endl;
				cnt--;
			}
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
 