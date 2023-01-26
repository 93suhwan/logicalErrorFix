#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N = 1e6+10;
int n,m,tp=0,a[N],b[N],p[N],vis[N],q[N],f[N],g[N];
bool flag[N];
inline void init(){
	n=read(),flag[1]=1;
	if (!tp) m=read();
	else {
		For(i,1,n) if (rand()&1) a[++m]=i,b[i]=1,printf("%d ",i);
		puts("");
	}
	For(i,2,n){
		if (!vis[i]) vis[i]=i,flag[i]=1,p[++*p]=i;
		for (int j=1;j<=*p&&i*p[j]<=n;++j){
			vis[i*p[j]]=p[j];
			if (i%p[j]==0) break;
			flag[i*p[j]]=flag[i];
		}
	}
	int tot=0;
	For(i,1,n) tot+=flag[i];
	printf("%d ",tot);
	For(i,1,n) if (flag[i]) printf("%d ",i),q[++*q]=i;
	cout<<endl;
	For(i,1,tot){
		if (!tp) f[q[i]]=read();
		else {
			For(j,1,m) if (__gcd(a[j],q[i])==1) f[q[i]]^=a[j];
		}
	}
	g[1]=f[1];
	For(i,2,n) if (flag[i]){
		poly v;
		for (int j=i;j>1;j/=vis[j]) v.pb(vis[j]);
		FOR(j,0,1<<siz(v)){
			int x=1;
			FOR(k,0,siz(v)) if (j>>k&1) x*=v[k];
			g[i]^=f[x];
		}
	}
}

int cnt;
bool ans[N];
struct xxj{
	pa a[20];
	bitset<20>b[20];
	inline void init(){
		FOR(i,0,20) a[i]=mp(0,0),b[i].reset();
	}
	inline bool insert(int x,int y){
		bitset<20>tmp;
		Dow(i,19,0) if (x>>i&1){
			if (!a[i].fi) return a[i]=mp(x,y),b[i]=tmp,b[i][i]=1,1;
			x^=a[i].fi,tmp^=b[i];
		}
		return 0;
	}
	inline void get(int x){
		bitset<20>tmp;
		Dow(i,19,0) if (x>>i&1) x^=a[i].fi,tmp^=b[i];
		FOR(i,0,20) if (tmp[i]) ans[a[i].se]=1,++cnt;
	}
	inline int get2(int x){
		int ret=0;
		bitset<20>tmp;
		Dow(i,19,0) if (x>>i&1) x^=a[i].fi,tmp^=b[i];
		FOR(i,0,20) if (tmp[i]) ++ret;
		return ret;
	}
}s;
mt19937 rnd(2333);
bool vis2[N];
poly v[N];
inline void solve(){
	int mx=0;
	Dow(i,n,1) if (flag[i]){
		For(j,1,n/i){
			if (!vis2[i*j]) v[i].pb(i*j),vis2[i*j]=1;
			else if (flag[i*j]) g[i]^=g[i*j];
		}
		if (siz(v[i])>siz(v[mx])) mx=i;
		/*printf("azhe %d %d\n",i,g[i]);
		int tmp=0;
		For(j,1,m){
			int x=a[j];
			while (__gcd(x,i)>1) x/=__gcd(x,i);
			if (x==1&&a[j]%i==0){
				tmp^=a[j];
				printf("%d %d\n",i,a[j]);
			}
		}
		assert(tmp==g[i]);*/
	}
	ans[1]=g[1];
	while (233){
		cnt=ans[1];
		For(i,2,n) ans[i]=0;
		Dow(i,n,2) if (flag[i]){
			s.init();
			int S=g[i];
			for (auto j:v[i]) if (!s.insert(j,j)){
				if (rnd()%2==0) ans[j]=1,++cnt,S^=j;
			}
			if (cnt>m) break;
			s.get(S);
		}
		if (cnt>m) continue;
		if (cnt==m) break;
		s.init();
		poly tmp;
		for (auto j:v[mx]){
			cnt-=ans[j],ans[j]=0;
			if (!s.insert(j,j)) tmp.pb(j); 
		}
		For(T,1,10000){
			random_shuffle(all(tmp));
			int now=cnt,S=g[mx];
			for (auto j:tmp){
				if (now>m) break;
				if (now+s.get2(S)==m){
					s.get(S);
					goto finish;
				} 
				++now,S^=j,ans[j]=1;
			}
 		}
	}
	finish:;
	For(i,1,n) if (ans[i]) printf("%d ",i);
	cout<<endl;
}

int main(){
	init(),solve();
}