#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define ft first
#define sc second
using namespace std;
const int mod=1e9+7,INF=1e17;

main(){
   int t;
   cin >> t;
   while(t--){
   	int l,r,ans=0,tot=INF;
   	cin >> l >> r;
   	int dist=r-l+1;
   	int p=1;
   	while(p*2<=l){
   		p*=2;
	   }
	   int c=p;
	   while(c*2<=r){
	   	c*=2;
	   }
	   int res=INF;
	   if(p<l){
	   	res=min(l-(l-p),res);
	   	p*=2;
	   }
	   if(c+1==r){
	   	cout << min(dist-2,(dist-((dist+1)/2))) << endl;
	   	continue;
	   }
	   while(p*2<=c){
	   	res=min(dist-p,res);
	   	p*=2;
	   }
	   res=min(res,dist-(r-c+1));
   	cout << res << endl;
   }
}
