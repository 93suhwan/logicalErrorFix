//Common Header Simple over C++11
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree<pair<ll,int>,null_type,less<pair<ll,int>>,rb_tree_tag,tree_order_statistics_node_update> pset;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define make_unique(a) {sort(all(a));a.resize(unique(all(a))-a.begin());}
#define sz(x) ((int)(x).size())
#define count2(x) __builtin_popcount(x)
#define count2l(x) __builtin_popcountll(x)
#define countlz(x) __builtin_clz(x)
#define rint(x) int x;cin>>x;
#define rll(x) ll x;cin>>x;
#define rs(x) string x;cin>>x;
#define rvi(v,n) vector<int>v(n);for(auto &i:v)cin>>i;
#define rvl(v,n) vector<ll>v(n);for(auto &i:v)cin>>i;
#define dd(x) cerr << #x << " = " << x << ' ';
#define de(x) cerr << #x << " = " << x << endl;
#define df cerr << "Passing ["<<__FUNCTION__<<"] in LINE "<<__LINE__<< endl;
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=int(b)-1; i>=(a); i--)
#define pw(x) (1ll<<(x))
//#define endl '\n'
//#define getchar getchar_unlocked
//inline char nc() {
//  static char buf[1000000], *p = buf, *q = buf;
//  return p == q && (q = (p = buf) + fread(buf, 1, 1000000, stdin), p == q)
//             ? EOF
//             : *p++;
//}
const double PI=acos(-1.0);
inline double calcs(int start){return (1.0*clock()-start)/CLOCKS_PER_SEC;}
inline ll rd(){//LLONG_MIN LMAX=9,223,372,036,854,775,807
	ll s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch&15),ch=getchar();
	return s*w;
}
inline int fpow(int a,int b,int p){//a^b mod p; assert(p!=0);
	int ans=1%p,base=a%p;
	for(;b;b/=2){
		if(b&1)ans=(ll)ans*base%p;
		base=(ll)base*base%p;
	}
	return ans;
}
 constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = 1e9 + 9; // 1000000009
const int N=200001;
char p[N];
struct node{
	int lson,rson;
}E[N];
string a;
int id[N];// 中序遍历序转节点id 
void dfs(int pos){
	if(pos==0) return ;
	dfs(E[pos].lson);
	id[a.size()]=pos;
	a+=p[pos];
	dfs(E[pos].rson);
}
bool tag[N],dup[N];
// gao(x, r) -> int 表示，
// 这颗子树还剩余 r 个可用结点，然后返回的是这颗子树最后用了多少结点
int gao(int pos,int r){
	if(pos==0) return 0;
	if(r<=0) return 0;
	// 留一个给根节点用 
	bool use=gao(E[pos].lson,r-1);
	if(use){
		dup[pos]=1;
		r-=use+1;
		return gao(E[pos].rson,r)+use+1;
	}
	else{
		if(tag[pos]){// 如果当前节点扩展能使字典序变小 
			dup[pos]=1;
			return gao(E[pos].rson,r-1)+1;
		}
		else{
			dup[pos]=0;
			return 0;
		}
	} 
} 
void dfs2(int pos){
	if(pos==0) return ;
	dfs2(E[pos].lson);
	cout<<p[pos];
	if(dup[pos])cout<<p[pos];
	dfs2(E[pos].rson);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);cin.exceptions(ios::badbit | ios::failbit);
	rint(n)rint(k)// 最多加倍k次后字典序最短 
	rs(s)
	for(int i=1;i<=n;++i)	p[i]=s[i-1];
	for(int i=1;i<=n;++i)	cin>>E[i].lson>>E[i].rson;
	dfs(1);
	a.push_back(0);
	vector<int>nxt(a.size());
	for(int i=a.size()-1-1;i>=0;i--){
    	// nxt[i] 中序遍历出来的字符串下一个和它不一样的点的值 
		if(a[i]!=a[i+1]){
			nxt[i]=a[i+1];
		}else{
			nxt[i]=nxt[i+1];
		}
		assert(nxt[i]!=a[i]);
		if(nxt[i]>a[i]){
			tag[id[i]]=1;
		}
		else{
			tag[id[i]]=0;
		}
	}
	for(int i=1;i<=n;++i) dup[i]=0;
	gao(1,k);
	dfs2(1);
	return 0;
}

