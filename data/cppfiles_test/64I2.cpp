#include<bits/stdc++.h>
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define R register
#define endl putchar('\n')
const int N=1000005;
#define int long long
using namespace std;

char s[N],t[N];
int n,m,nex[N],mxr,mxp,ext[N];

const int bs=10,mod[6]={0,(int)1e9+7,(int)1e9+9,998244353,1004535809,19260817};
struct fuck {
	int val[6];
	int& operator [] (const int &x) { return val[x]; }
	fuck operator + (const fuck &b) {
		fuck t; rep(i,1,5) t[i]=(val[i]+b.val[i])%mod[i]; return t;
	}
	fuck operator + (const int &x) {
		fuck t; rep(i,1,5) t[i]=(val[i]+x)%mod[i]; return t;
	}
	fuck operator * (const int &x) {
		fuck t; rep(i,1,5) t[i]=val[i]*x%mod[i]; return t;
	}
	fuck operator * (const fuck &b) {
		fuck t; rep(i,1,5) t[i]=val[i]*b.val[i]%mod[i]; return t;
	}
	fuck operator - (const fuck &b) {
		fuck t; rep(i,1,5) t[i]=(val[i]-b.val[i]+mod[i])%mod[i]; return t;
	}
	fuck operator = (const int &x) {
		rep(i,1,5) val[i]=x; return *this;
	}
	bool operator == (const fuck &b) {
		int flag=1; rep(i,1,5) flag&=val[i]==b.val[i]; return flag;
	}
} pw[N],hs[N],x;
struct hash {
	void init() {
		pw[0]=1;
		rep(i,1,n) pw[i]=pw[i-1]*bs;
		rep(i,1,n) hs[i]=hs[i-1]*bs+(s[i]-'0');
		x=0;
		rep(i,1,m) x=x*bs+(t[i]-'0');
	}
	fuck f(int l,int r) {
		fuck res=hs[r]-hs[l-1]*pw[r-l+1];
		return res;
	}
} h;

void exkmp() {
	nex[1]=m; int nw=0;
	while(t[nw+1]==t[nw+2]&&nw+2<=m) nw++; nex[2]=nw;
	mxp=2,mxr=2+nw-1;
	rep(i,3,m) {
		if(nex[i-mxp+1]+i-1<mxr) nex[i]=nex[i-mxp+1];
		else {
			int nw=max(mxr-i+1,0ll);
			while(t[i+nw]==t[1+nw]&&i+nw<=m) nw++;
			nex[i]=nw,mxr=i+nw-1,mxp=i;
		}
	}
}
void match() {
	int nw=0;
	while(s[1+nw]==t[1+nw]&&1+nw<=min(n,m)) nw++; ext[1]=nw;
	mxp=1,mxr=nw;
	rep(i,2,n) {
		if(nex[i-mxp+1]+i-1<mxr) ext[i]=nex[i-mxp+1];
		else {
			int nw=max(mxr-i+1,0ll);
			while(s[i+nw]==t[1+nw]&&1+nw<=m&&i+nw<=n) nw++;
			ext[i]=nw,mxr=i+nw-1,mxp=i;
		}
	}
}
void done(int l,int r,int x,int y) {
	printf("%lld %lld\n%lld %lld\n",l,r,x,y);
	exit(0);
}
void solve() {
	rep(i,1,n-(m-1)*2+1) {
		fuck v1=h.f(i,i+(m-1)-1),v2=h.f(i+(m-1),i+2*(m-1)-1);
		if(v1+v2==x) done(i,i+(m-1)-1,i+(m-1),i+2*(m-1)-1);
	}
	exkmp();
	match();
	rep(i,1,n) {
		if(ext[i]==m||i+m-1>n) continue;
		fuck v1=h.f(i,i+m-1),v2;
		if(i+m+(m-ext[i])-1<=n) {
			v2=h.f(i+m,i+m+(m-ext[i])-1);
			if(v1+v2==x) done(i,i+m-1,i+m,i+m+(m-ext[i])-1);
		}
		if(i-(m-ext[i])>=1) {
			v2=h.f(i-(m-ext[i]),i-1);
			if(v1+v2==x) done(i-(m-ext[i]),i-1,i,i+m-1);
		}
		if(ext[i]==m-1) continue;
		if(i+m+(m-ext[i]-1)-1<=n) {
			v2=h.f(i+m,i+m+(m-ext[i]-1)-1);
			if(v1+v2==x) done(i,i+m-1,i+m,i+m+(m-ext[i]-1)-1);
		}
		if(i-(m-ext[i]-1)>=1) {
			v2=h.f(i-(m-ext[i]-1),i-1);
			if(v1+v2==x) done(i-(m-ext[i]-1),i-1,i,i+m-1);
		}
	}
}

signed main() {
	srand(time(0));
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	h.init();
	solve();
	return 0;
}