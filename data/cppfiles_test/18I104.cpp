#include<bits/extc++.h>
#define eps 1e-7
#define endl '\n'
#define ls (p<<1)
#define rs (p<<1|1)
#define lb(x) (x&-x)
#define pie acos(-1)
#define int long long
#define mid ((l+r)/2)
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define ull unsigned long long
#define inf 4557430888798830399
#define mgp gp_hash_table<int,int>
#define ms0(a) memset(a,0,sizeof(a))
#define myCase int T;for(cin>>T;T--;)
#define mst(a,b) memset(a,b,sizeof(a))
#define IOS std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define que __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag>
#define rbt tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define tri trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int n,d,ans,a[1000010],b[1000010];
void mySolve(){ans=0;
	cin>>n>>d;
	int x=gcd(n,d);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,cnt=0;i<=x;i++,cnt=0){
		for(int j=1;j<=n/x;j++) b[++cnt]=a[(i+d*j-1)%n+1];
		for(int j=1;j<=n/x;j++) b[++cnt]=a[(i+d*j-1)%n+1];
		int num=0,mx=0;
		for(int j=1;j<=cnt;j++){
			if(b[j]) num++;
			else num=0;
			mx=max(mx,num);
		}
		ans=max(ans,mx);
	}
	cout<<(ans==n/x*2?-1:ans)<<endl;
}
signed main(){IOS
	myCase
		mySolve();
return 0;}
/* 	stuff you should look for
 * 	int overflow, array bounds
 * 	special cases (n=1?)
 * 	do smth instead of nothing and stay organized
 * 	WRITE STUFF DOWN
 * 	DON'T GET STUCK ON ONE APPROACH
 *	-- Benq
*/