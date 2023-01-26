#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a),i##ss=(b);i<=i##ss;i++)
#define dwn(i,a,b) for(int i=(a),i##ss=(b);i>=i##ss;i--)
#define deb(x) cerr<<(#x)<<":"<<(x)<<'\n'
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int yh(){
	int ret=0;bool f=0;char c=getchar();
	while(!isdigit(c)){if(c==EOF)return -1;if(c=='-')f=1;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n,K;
struct pt{
	ll x,y,id;
	bool operator<(const pt&A)const{
		return x<A.x||(x==A.x&&y<A.y);
	}
}a[maxn],p[maxn];
ll sq(ll x){return x*x;}
db dis(pt i,pt j){
	return sqrt(sq(i.x-j.x)+sq(i.y-j.y));
}
map<pair<ll,ll>,vector<int>> cnt;
void ins(pt i,pt j,int id){
	ll dx=i.x-j.x,dy=i.y-j.y,g=__gcd(dx,dy);
	dx/=g;dy/=g;
	if(dx<0) dx=-dx,dy=-dy;
	else if(dx==0) dy=abs(dy);
	cnt[mkp(dx,dy)].pb(id);
}
signed main(){
	n=yh();K=yh();
	rep(i,1,n) a[i].x=yh(),a[i].y=yh(),a[i].id=i;
	if(n==3){
		ll ans=dis(a[1],a[2])+dis(a[2],a[3])+dis(a[3],a[1]);
		ans-=max(dis(a[K],a[K%3+1]),dis(a[K],a[K==1?3:K-1]));
		cout<<fixed<<setprecision(12)<<ans<<hvie;
	}
	sort(a+1,a+1+n);
	rep(i,2,4){
		ins(a[1],a[i],i);
	}
	if(cnt.size()>2){
		cnt.clear();
		ins(a[2],a[1],1);
		ins(a[2],a[3],3);
		ins(a[2],a[4],4);
	}
	int id=0;
	// for(auto p:cnt){
		// cout<<p.fi.fi<<','<<p.fi.se<<hvie;
	// }
	assert(cnt.size()==2);
	for(auto p:cnt){
		if(p.se.size()==1){
			::p[n]=a[p.se.front()];
			id=::p[n].id;
			// cout<<a[p.se.front()].x<<","<<a[p.se.front()].y<<hvie;
		}
	}
	int R=0,S=0;
	rep(i,1,n)if(a[i].id!=id){
		p[++R]=a[i];
		if(p[R].id==K){
			S=R;
		}
	}
	cout<<fixed<<setprecision(12);
	if(p[n].id==K){
		cout<<dis(p[1],p[R])+min(dis(p[n],p[1]),dis(p[n],p[R]))<<hvie;
		return 0;
	}
	db ans=1e12;
	rep(i,2,S){
		ans=min(ans,dis(p[S],p[i])+dis(p[i],p[R])+dis(p[R],p[n])+dis(p[n],p[i-1])+dis(p[i-1],p[1]));
		ans=min(ans,dis(p[S],p[R])+dis(p[R],p[i])+dis(p[i],p[n])+dis(p[n],p[i-1])+dis(p[i-1],p[1]));
	}
	rep(i,S,R-1){
		ans=min(ans,dis(p[S],p[i])+dis(p[i],p[1])+dis(p[1],p[n])+dis(p[n],p[i+1])+dis(p[i+1],p[R]));
		ans=min(ans,dis(p[S],p[1])+dis(p[1],p[i])+dis(p[i],p[n])+dis(p[n],p[i+1])+dis(p[i+1],p[R]));
	}
	cout<<ans<<hvie;

	return 0;
}
