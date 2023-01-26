#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll arr[105];
int main(){
	int tmp;
	cin>>tmp;
	while(tmp--){
		int n;
		cin>>n;
		cin>>arr[1];
		bool flag=true;
		for(int i=2;i<=n;i++){
			cin>>arr[i];
			if(arr[i]==arr[i-1]){
				flag=false;
			}
		}
		if(!flag){
			puts("0");
			continue;
		}
		ll g=arr[1];
		for(int i=1;i<=n;i+=2){
			g=__gcd(arr[i],g);
		}
		if(g==1){
			g=arr[2];
			for(int i=2;i<=n;i+=2){
				g=__gcd(g,arr[i]);
			}
			for(int i=1;i<=n;i+=2){
				if(arr[i]%g==0){
					flag=false;
				}
			}
		} 
		else{
			for(int i=2;i<=n;i+=2){
				if(arr[i]%g==0){
					flag=false;
				}
			}
		}
		printf("%lld\n",flag?g:0);
	}
	return 0;
}