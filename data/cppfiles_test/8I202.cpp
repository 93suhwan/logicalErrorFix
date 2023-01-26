#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int , null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> pbds;


int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll one=n/3,two=n/3;
		ll x=n-(one+two*2);
		if(x==1)cout << one+1 << " " << two << endl;
		else cout << one << " " << two+1 << endl;
	}
	return 0;
}