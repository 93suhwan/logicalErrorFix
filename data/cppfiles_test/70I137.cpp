//By ligen131
//#pragma GCC optimize(3)
// #define ADD_STACK int size = 512 << 20;\
// 	char *pp = (char*)malloc(size) + size;  \
// 	__asm__("movl %0, %%esp\n" :: "r"(pp))
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<bitset>
#include<ctime>
#include<vector>
#include<assert.h>
#define ll long long
#define ull unsigned long long
#define mn 200020
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))
#define Abs(x) (((x)<(0))?(-(x)):(x))
#define infll (ll)(1e18)
#define infint (1<<30)
#define FOR(a,b,c) for (register int a=b;a<=c;++a)
#define FORD(a,b,c) for (register int a=b;a>=c;--a)
using namespace std;
// char buf[1<<20],*p1=buf,*p2=buf;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
inline ll read() {
	ll x = 0, f = 1; char c;
	for (c = getchar(); c < '0' || c > '9'; f = ((c == '-') ? -1 : f), c = getchar());
	for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
	return x * f;
}
template<typename T>
inline void write(T a) {
	if (a == 0) {
		putchar('0');
		return;
	} if (a < 0)putchar('-'), a = -a; char c1[120]; int h = 0;
	while (a)c1[++h] = a % 10 + '0', a /= 10; FORD(i, h, 1)putchar(c1[i]);
}
inline void write_() {
	return;
}
template<typename T, typename... Args>
inline void write_(T a, Args... b) {
	write(a);
	putchar(' ');
	write_(b...);
}
inline void writeln() {
	putchar('\n');
	return;
}
template<typename T, typename... Args>
inline void writeln(T a, Args... b) {
	write(a);
	putchar(' ');
	writeln(b...);
}
//need c++11

//inline void write(ll a){
//    if(a==0){putchar('0');return;}if(a<0)putchar('-'),a=-a;char c1[120];int h=0;
//    while(a)c1[++h]=a%10+'0',a/=10;FORD(i,h,1)putchar(c1[i]);
//}
//inline void write_(ll a){write(a);putchar(' ');}
//inline void writeln(ll a){write(a);putchar('\n');}
inline ll gcd(ll a, ll b) {
	return a == 0 ? b : gcd(b % a, a);
}
inline ll lcm(ll a, ll b) {
	return 1ll * a / gcd(a, b) * b;
}
inline ll Pow(ll n, ll a,ll Mod) {
	ll b = 1;
	while (a) {
		if (a & 1)b = 1ll * b * n % Mod;
		n = 1ll * n * n % Mod;
		a >>= 1;
	} return b;
}
//---------------------Head Files--------------------------//
char s[500020];
struct node{
	char c;
	int x;
}a[32];
inline bool cmp(node a,node b){return a.x<b.x;}
int v[120];
bool vv[120];
ll Mod[2]={19260817,998244353};
ll p[2]={13,17};
ll Hash[500020][2],h2[500020][2];
int R[500020];
inline ll Has(int k,int l,int r){
	ll po=Pow(p[k],r-l+1,Mod[k]);
	return (Hash[r][k]-1ll*Hash[l-1][k]*po%Mod[k]+Mod[k])%Mod[k];
}
signed main(){
#ifdef LOCAL_LIGEN
	freopen("0.in","r",stdin);
	//freopen("0.out","w",stdout);
	double be = clock();
#endif
	int T=read();
	// if(T==2054){FOR(i,1,115)scanf("%s",s+1);printf("%s",s+1);return 0;}
	while(T--){
		scanf("%s",s+1);
		int tot=0,n=strlen(s+1);
		FOR(i,0,25)v[i]=0,vv[i]=0;
		FOR(i,1,n)if(!v[s[i]-'a'])v[s[i]-'a']=++tot,a[tot].c=s[i],a[tot].x=i;
		else a[v[s[i]-'a']].x=i;
		if(tot==1){
			printf("%s %c\n",s+1,s[1]);
			continue;
		}
		sort(a+1,a+1+tot,cmp);
		FOR(i,1,n)FOR(j,0,1)Hash[i][j]=(1ll*Hash[i-1][j]*p[j]%Mod[j]+s[i])%Mod[j];
		int now=0,h=0;
		while(now<tot){
			++h;
			if(!vv[s[h]-'a'])vv[s[h]-'a']=1,++now;
			// writeln(h,now,tot);
		}
		if(h==n){writeln(-1);continue;}
		bool ch,chh=0;
		int r=h+1,len=0;
		FOR(i,1,h)if(s[i]!=a[1].c){
			++len;
			FOR(k,0,1)h2[len][k]=(s[i]+1ll*h2[len-1][k]*p[k]%Mod[k])%Mod[k];
		}
		// FOR(i,1,tot)putchar(a[i].c),putchar(' '),writeln(a[i].x);
		int Rn=0;
		while(r<=n){
			ch=1;
			if(r+len-1>n)break;
			FOR(k,0,1)ch&=(bool)(h2[len][k]==Has(k,r,r+len-1));//,writeln(r,len,h2[len][k],Has(k,r,r+len-1),ch);
			if(ch){chh=1;R[++Rn]=r;}
			if(s[r]!=a[1].c){
				++len;
				FOR(k,0,1)h2[len][k]=(s[r]+1ll*h2[len-1][k]*p[k]%Mod[k])%Mod[k];
			}
			++r;
		}
		if(!chh){writeln(-1);continue;}
		FOR(j,1,Rn){
			int n2=R[j],ni=0,lsn=1;
			chh=1;
			// writeln(R[j]);
			FOR(i,1,n){
				// writeln(i,n2,lsn,ni);
				if(n2>n)break;
				if(i>=n2){chh=0;break;}
				if(i==lsn)++ni,lsn=n2;
				if(s[i]==a[ni].c)continue;
				if(s[i]!=s[n2]){chh=0;break;}
				++n2;
			}
			if(chh){
				FOR(i,1,R[j]-1)putchar(s[i]);
				putchar(' ');
				FOR(i,1,tot)putchar(a[i].c);
				putchar('\n');
				break;
			}
		}
		if(!chh){writeln(-1);continue;}
	}
#ifdef LOCAL_LIGEN
	double en = clock();
	printf("Time: %.0lfms\n", en - be);
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}
