// Problem: D. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author:tooler!
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
inline ll rd() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define d rd()
#define pb push_back
ll t,n;
ll a[200010];
ll c[200010][50];
ll ask(ll a,ll b){
	ll lo=log2(b-a+1);
	ll po=1<<lo;
	return __gcd(c[a][lo],c[b-po+1][lo]);
}
bool check(ll r){
	ll ans=0;
	f(i,1,n){
		ll x=i,y=(i+r)-1;
		if(y>n)break;
		ans=max(ans,ask(x,y));
	}
	if(ans>1)return 1;
	return 0;
}
int main(){
	t=d;while(t--){
		n=d;f(i,1,n)a[i]=d;
		memset(c,0,sizeof(c));
		f(i,1,n)c[i][0]=a[i]-a[i-1];
		for(int i=1;i<=log2(n);i++)for(int j=1;j+(1<<i)-1<=n;j++){
			int po=1<<(i-1);
			c[j][i]=__gcd(c[j][i-1],c[j+po][i-1]);
		}
		ll l=1,r=n;
		while(l+1<r){
			ll mid=(l+r)>>1;
			if(check(mid))l=mid;
			else r=mid;
		}
		printf("%lld\n",l+1);
	}
	return 0;
}