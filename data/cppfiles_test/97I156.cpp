//https://www.luogu.com.cn/problem/CF1567F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define mem(x,y) memset(x,y,sizeof(x))
#define br putchar('\n')
#define Fin(s) freopen(s".in","r",stdin)
#define Fout(s) freopen(s".out","w",stdout)
#define File(s) Fin(s);Fout(s)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define For(i,j,k) for(register int i=j;i<=k;i++)
#define Rof(i,j,k) for(register int i=j;i>=k;i--)
#define uid(i,j,k) uniform_int_distribution<ll> i(j,k)
#define Rand(s) s(rand_num)
unsigned seed=chrono::system_clock::now().time_since_epoch().count();//种子 值为从1970/1/1 8:00到现在的秒数乘上10^9
mt19937 rand_num(seed);//大随机数
inline ll read(){//快读
	ll s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
template<class T> inline void ckmx(T &a,T b){ if(a<b)a=b; }//check max
template<class T> inline void ckmn(T &a,T b){ if(a>b)a=b; }//check min
const ll mod=998244353;//不能大于int_max
inline void madd(ll &a,ll b){ a=((a+b)%mod+mod)%mod; }//取模意义下的加法
inline void mmul(ll &a,ll b){ a=(a*b%mod+mod)%mod; }//取模意义下的乘法

/*--------------------------非常不华丽的头文件分割线--------------------------*/
#define N 520 
#define pi pair<int,int>
const int val[2]={1,4};
char ch;
bool mp[N][N];
int id[N][N];
int tot=0;
int ans[N][N];
bool col[N*N],vis[N*N];
int n,m;
vector<int> e[N*N];
vector<pi> vec;
int gid(int x,int y){
	if(!id[x][y]) id[x][y]=++tot;
	return id[x][y];
}
inline void adde(int x,int y){
	e[x].pb(y);
	e[y].pb(x);
}
void dfs(int x,bool y){
	vis[x]=1;
	col[x]=y;
	for(int i:e[x]){
		if(vis[i]) continue;
		dfs(i,!y);
	}
}
signed main(){
	IOS;
	cin>>n>>m;
	For(i,1,n){
		For(j,1,m){
			cin>>ch;
			mp[i][j]=(ch=='X');
		}
	} 
	For(i,2,n-1)For(j,2,m-1)
		if((mp[i+1][j]+mp[i-1][j]+mp[i][j+1]+mp[i][j-1])&1){
			cout<<"NO"<<endl;
			return 0;
		}
	For(i,2,n-1)For(j,2,m-1)
		if((mp[i+1][j]+mp[i-1][j]+mp[i][j+1]+mp[i][j-1])==0){
			adde(gid(i+1,j),gid(i,j+1));
			adde(gid(i+1,j),gid(i,j-1));
			adde(gid(i-1,j),gid(i,j+1));
			adde(gid(i-1,j),gid(i,j-1));
		}
	For(i,2,n-1)For(j,2,m-1)
		if((mp[i+1][j]+mp[i-1][j]+mp[i][j+1]+mp[i][j-1])==2){
			vec.clear();
			if(!mp[i+1][j]) vec.pb({i+1,j});
			if(!mp[i-1][j]) vec.pb({i-1,j});
			if(!mp[i][j+1]) vec.pb({i,j+1});
			if(!mp[i][j-1]) vec.pb({i,j-1});
			assert(vec.size()==2);
			adde(gid(vec[0].first,vec[0].second),gid(vec[1].first,vec[1].second));
		}
	For(i,1,tot)
		if(!vis[i]) dfs(i,0);
	
	For(i,1,n)
		For(j,1,m)
			if(id[i][j])
				ans[i][j]=val[col[id[i][j]]];
	
	For(i,1,n)
		For(j,1,m)
			if(mp[i][j]){
				if(id[i+1][j])ans[i][j]+=ans[i+1][j];
				if(id[i-1][j])ans[i][j]+=ans[i-1][j];
				if(id[i][j+1])ans[i][j]+=ans[i][j+1];
				if(id[i][j-1])ans[i][j]+=ans[i][j-1];
			}
	
	For(i,1,n)
		For(j,1,m)
			if(!ans[i][j])
				ans[i][j]=1;
	
	cout<<"YES"<<endl;
	For(i,1,n){
		For(j,1,m){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	} 
    return 0;
}
