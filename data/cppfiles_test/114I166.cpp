#include <bits/stdc++.h>
using namespace std;
#define fr first
#define NFS 	ios_base::sync_with_stdio(0) ;cin.tie(0) ;
#define sc second
#define int long long
#define endl "\n"

bool glas(char a){
	if('a' == a || a == 'e' || 'u' == a || a == 'i' || a == 'o'){
		return true;
	}
	return false;
}
int len (int x){
	int cnt=0;
	while(x>0){
		cnt++;
		x/=10;
	}
	return cnt;
}
void solve(){
	int n;
	cin>>n;
	vector<bool> rec(1e6+1,0);
	vector<int>vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
		rec[vec[i]]=1;
	}
	sort(vec.begin(),vec.end());
	vector<pair<int,int> >ans ;
	for(int i=1;i<n;i++){
		for(int j = 0; j< i;j++ ){
			if(i!=j &&rec[vec[i]%vec[j]]){
				ans.push_back({vec[i],vec[j]});
			}
			if(ans.size()>= n/2){
				break;
			}


		}
		if(ans.size()>=n/2){
			break;
		}
	}
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	
}
main(){
	NFS
	int t;
	cin>>t;
	while(t--){
    	solve();
  	}
}