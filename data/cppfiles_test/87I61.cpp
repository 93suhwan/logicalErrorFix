#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++) cin>>a[i];
    int count=0;
    ordered_set o_set;
    for(int i=0;i<m;i++){
        int x=o_set.order_of_key(a[i]);
        count+=x;
        o_set.insert(a[i]);
    }
    cout<<count<<'\n';
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--){
	    solve();  
	} 
	return 0;
}
