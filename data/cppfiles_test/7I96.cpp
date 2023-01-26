#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqs             priority_queue<int,vi,greater<int> >
#define mod             1000000007
#define int             long long
#define pb              push_back
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(t)            int t; cin>>t; while(t--)
#define mp              make_pair
#define endl            "\n"
#define pqb             priority_queue<int>
#define ceil(a , b)     ((a / b) + (a%b && 1))
#define rep(i,a,b)      for(int i=a;i<(int)b;i++)
#define repr(i,a,b)     for(int i=a;i>=(int)b;i--)
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(v)          v.begin(), v.end()
#define ff              first
#define ss              second
template<typename... T> void pn(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
template<typename... T> void ps(T... args) { ((cout << args << " "), ...); cout<<""; }
// void start()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }
int power(int a, int b,int P=mod) {
	int res = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P)
		if (b & 1)
			res = 1ll * res * a % P;
	return res;
}
vector<int> tree,temp;
void buildTree(int s,int e,int index) {
	if(s==e) {
		tree[index]=temp[s];
		return;
	}
	int mid=s+(e-s)/2;
	buildTree(s,mid,2*index);
	buildTree(mid+1,e,2*index+1);
	tree[index]=__gcd(tree[2*index],tree[2*index+1]);
	return;
}
int query(int ss,int se,int qs,int qe,int index) {
	if(ss>=qs&&se<=qe)	return tree[index];
	if(qe<ss||qs>se)	return 0;
	int mid=(ss+se)/2;
	int left=query(ss,mid,qs,qe,2*index);
	int right=query(mid+1,se,qs,qe,2*index+1);
	return __gcd(left,right);
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}
	temp.clear();
	tree=vector<int>(4*n+5,0);
	for(int i=0; i<n-1; i++)
	{
		temp.pb(abs(arr[i]-arr[i+1]));
	}
	int ans=1;
	buildTree(0,n-2,1);
	for(int i=0; i<n-1; i++)
	{
		int t=0;
		int st=i+ans;
		int en=n-2;
		if(query(0,n-2,i,st,1)==1)	continue;
		while(st<=en)
		{
			int mid=st+(en-st)/2;
			if(query(0,n-2,i,mid,1)>1)
			{
				t=max(t,mid-i+1);
				st=mid+1;
			}
			else
			{
				en=mid-1;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans+1<<endl;
}
int32_t main()
{
	fastio;
	w(t)
	{
		solve();
	}

	return 0;
}