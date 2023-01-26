#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ll long long
#define vi vector<ll>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define pb push_back
#define endl '\n'
#define sa(x) sort((x).begin(), (x).end());
#define int long long

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T> static inline void sd(vector<T> &x) {sort((x).begin(), (x).end(), greater<T>()) ; }


#define ord_set	tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ord_setii tree<ii, null_type,less<ii>, rb_tree_tag, tree_order_statistics_node_update> 


void solve(){
	int n;
	cin>>n;

	vi a(n);
	rep(i,0,n) cin>>a[i];
	vi b(n);
	iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](int i, int j){
		return (a[i] < a[j]);
	});

	cout<<n<<endl;


	for(int i=0; i<n; ++i)
	{
		if((n-b[i])%(n-i))
		cout<<i+1<<" "<<n<<" "<<(n-b[i])%(n-i)<<"\n";
	}


}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int testcases=1;
	cin>>testcases;
	while(testcases--){
		solve();
	}
	return 0;	
}
