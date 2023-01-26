// Problem: E. Middle Duplication
// Contest: Codeforces - Codeforces Round #763 (Div. 2)
// URL: https://codeforces.com/contest/1623/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: abhidot

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007
#define mod2 998244353
#define lld long double
#define pii pair<int, int>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define rep(i,x,y) for(int i=x; i<y; i++)
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define V vector
#define setbits(x) __builtin_popcountll(x)
#define w(x)  int x; cin>>x; while(x--)
using namespace std;
using namespace __gnu_pbds; 
template <typename num_t> using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N=200005, INF=2000000000000000000, inf = 2e9+5;

int power(int a, int b, int p){
	if(a==0)
	return 0;
	int res=1;
	a%=p;
	while(b>0)
	{
		if(b&1)
		res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}


void print(bool n){
    if(n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int n, k;
string s;

int btree[N][2];
int p[N][20];
vector<vector<int>> g;
int tin[N], tout[N], lim[N];

vector<int> inorder;
int tim=0;


void traversal(int u, int cnt=1){
	if(u==0) return;
	tin[u] = ++tim;
	lim[u]=cnt;
	traversal(btree[u][0], cnt+1);
	inorder.push_back(u);
	traversal(btree[u][1], 1);
	tout[u] = ++tim;
}

int32_t main()
{
    IOS;
    cin>>n>>k>>s;
    s = "$"+s;
    vector<int> col(n+1, 0);
    col[0]=1;
    for(int i=1;i<=n;i++){
    	cin>>btree[i][0]>>btree[i][1];
    	if(btree[i][0]) p[btree[i][0]][0]=i;
    	if(btree[i][1]) p[btree[i][1]][0]=i;
    }
    
    traversal(1);
    
    // Binary Lifting
    for(int j=1;j<20;j++){
    	for(int i=1;i<=n;i++){
    		p[i][j] = p[p[i][j-1]][j-1];
    	}
    }
    
    int left=k;
    int i;
    
    auto calc = [&](int on){
    	if(col[on]) return 0LL;
    	int ans=1;
    	// cout<<on<<": ";
    	for(int j=19;j>=0;j--){
    		if(col[p[on][j]]==0){
    			on = p[on][j];
    			// cout<<on<<" ";
    			ans+=(1<<j);
    		}
    	}
    	// cout<<": "<<ans<<"\n";
    	// cout<<"\n";
    	
    	return ans;
    };
    
    string d;
    d+=s[inorder[0]];
    int val[n+1]={0};
    val[inorder[0]]=0;
    for(int i=1;i<n;i++){
    	if(s[inorder[i]]!=d.back()){
    		d+=s[inorder[i]];
    	}
    	val[inorder[i]] = d.size()-1;
    }
    
    
    int upto=0;
    for(i=0;inorder[i]!=1;i++){
    	if(val[inorder[i]]==d.size()-1||d[val[inorder[i]]]>d[val[inorder[i]]+1]||tin[inorder[i+1]]<upto){
    		// upto = max(upto, tout[inorder[i]]);
    		continue;
    	}
    	int req = calc(inorder[i]);
    	if(req>left||req>lim[inorder[i]]) continue;
    	left-=req;
    	int on=inorder[i];
    	while(on&&col[on]==0){
    		col[on]=1;
    		on = p[on][0];
    	}
    }
    
    // cout<<inorder[i]<<" "<<inorder[i+1]<<" "<<val[inorder[i]]<<" "<<val[inorder[i]+1]<<"\n";
	if(i<n-1&&val[inorder[i]]<d.size()-1&&d[val[inorder[i]]]<d[val[inorder[i]]+1]){
		int req = calc(inorder[i]);
    	if(req<=left){
	    	left-=req;
	    	int on=inorder[i];
	    	while(col[on]==0){
	    		col[on]=1;
	    		on = p[on][0];
	    	}
    	}	
	}
    
    if(col[1]==1){
    	i++;
    	for(;i<n-1;i++){
    		if(left==0) continue;
    		if(val[inorder[i]]==d.size()-1||d[val[inorder[i]]]>d[val[inorder[i]]+1]){
    			upto = max(upto, tout[inorder[i]]);
    		}
	    	int req = calc(inorder[i]);
	    	if(req>left||req>lim[inorder[i]]) continue;
	    	left-=req;
	    	int on=inorder[i];
	    	while(col[on]==0){
	    		col[on]=1;
	    		on = p[on][0];
	    	}
    	}
    }
    
    for(int i=0;i<n;i++){
    	cout<<s[inorder[i]];
    	if(col[inorder[i]]) cout<<s[inorder[i]];
    }
}