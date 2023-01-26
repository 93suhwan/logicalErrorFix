#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define mod 998244353
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};
vector<modint> fac,ifac,iv;
inline void initC(int n)
{
    if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
    int m=iv.size(); ++n;
    if(m>=n)return;
    iv.resize(n),fac.resize(n),ifac.resize(n);
    For(i,m,n-1){
        iv[i]=iv[mod%i]*(mod-mod/i);
        fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
    }
}
inline modint C(int n,int m){
    if(m<0||n<m)return 0;
    return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n,k; int f[21][100005];
void work()
{
	n=read(),k=read();
	if(k>=17){
		printf("%lld\n",n);
		return;
	}
	printf("%lld\n",f[k][n]);
}

int pri[maxn],phi[maxn],tot;
int mu[maxn],smu[maxn];
bool vis[maxn];
void prework(int n)
{
	vis[1]=1,mu[1]=1,phi[1]=1;
	For(i,2,n)
	{
		if(!vis[i])pri[++tot]=i,mu[i]=-1,phi[i]=i-1;
		For(j,1,tot)
		{
			if(i*pri[j]>n)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]){
				mu[i*pri[j]]=-mu[i];
				phi[i*pri[j]]=phi[i]*(pri[j]-1);
			}else{
				mu[i*pri[j]]=0;
				phi[i*pri[j]]=phi[i]*pri[j];
				break; 
			}
		}
	}
	For(i,1,n)smu[i]=smu[i-1]+mu[i];//sphi[i]=sphi[i-1]+phi[i];
}

int l,r,now;
int lstl,lstr,lstnow;
vector<int>d[maxn]; 
int ans[maxn];

inline void addr(){
	++r;
//  now+=(__gcd(i,r)==x),i=[l,r]
	for(auto x:d[r])
		if(x>=l) now+=phi[r/x];
}

inline void delr(){
	for(auto x:d[r])
		if(x>=l) now-=phi[r/x];
	--r;
}

inline int Sum(int l,int r){
	// i<=l,j<=r,gcd(i,j)==l
}
inline void addl(){
	now-=ans[r/l];
	++l;
}
inline void dell(){
	--l;
	now+=ans[r/l];
}

int work(int a,int b,int d)
{
	int res=0;
	for(int l=1,r;l<=min(a,b);l=r+1){
		r=min(a/(a/l),b/(b/l));
		res+=(a/(l*d))*(b/(l*d))*(smu[r]-smu[l-1]);
	}return res;
}

inline int calc(int ql,int qr){
//	cout<<"Calc "<<ql<<" "<<qr<<endl; 
	while(l>ql) dell();
	while(r<qr) addr();
	while(l<ql) addl();
	while(r>qr) delr();
	return now;
}

int nw;
void solve(int tl,int tr,int l,int r)
{
	if(tl>tr||l>r)return;
//	cout<<"solve "<<tl<<" "<<tr<<" "<<l<<' '<<r<<endl;
	int mid=l+r>>1,res=1e18,p=0;
	For(i,tl,tr){
		int t=calc(i+1,mid)+f[nw-1][i];
		if(res>t)res=t,p=i;
	}
	f[nw][mid]=res;
	solve(tl,p,l,mid-1);
	solve(p,tr,mid+1,r);
}

void pre(int n)
{
	prework(n);
	For(i,1,n) ans[i]=ans[i-1]+phi[i];
	For(i,1,n)
		f[1][i]=i*(i+1)/2;
	For(i,1,n)
		for(int j=i;j<=n;j+=i)
			d[j].pb(i);
//	For(i,1,n){
//		cout<<ans[i]<<' ';
//		ans[i]=work(i,i,1);
//		ans[i]=(ans[i]+1)/2;
//		cout<<ans[i]<<endl;
//	}
		
	For(j,2,16) nw=j,l=1,r=0,now=0,solve(j-1,n-1,j,n); 
}

signed main()
{
	pre(10);
	int T=read();
	while(T--)work(); 
	return 0;
}