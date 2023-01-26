#pragma GCC optimize ("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include"iostream"
#include"cassert"
#include"cmath"
#include"cstdio"
#include"cstring"
#include"cstdlib"
#include"map"
#include"set"
#include"queue"
#include"vector"
#include"algorithm"
#include"numeric"
#include"stack"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define Finline __inline__ __attribute__ ((always_inline))
template <typename _Tp>Finline void chmax(const _Tp &a, const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(const _Tp &a, const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x){
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57)f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48 && ch<=57)x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f)x=-x;
}

template <typename _Tp, typename... Args>Finline void read(_Tp &t, Args &...args){
	read(t);read(args...);
}
//diff is constant
//two pointers and segtree for updates
const int N=2e5+10;
int a[N],t[2*N],n;
int g(int l, int r){
	l+=n-1;r+=n-1;
	int x=0;
	while(l<=r){
		if(l%2==1)x=__gcd(abs(t[l++]),x);
		if(r%2==0)x=__gcd(abs(t[r--]),x);
		l/=2;r/=2;
	}
	return x;
}
void add(int k, int x){
	k+=n-1;
	t[k]=__gcd(t[k],abs(x));
	for(k/=2;k>=1;k/=2){
		t[k]=__gcd(t[2*k],t[2*k+1]);
	}
}
void solve(){
	read(n);
	for(int i=0;i<=2*n+10;i++)t[i]=0;
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
		add(i,a[i]);
	}

	int l=1,ans=0;
	//if numbers wouldn't have been distinct
	//had to handle continuous zeroes separately
	//but now there is no issue
	
	for(int r=1;r<n;r++){
		while(l<=r and g(l,r)==1)l++;

		if(g(l,r)>1)ans=max(r-l+2,ans);
	}

	cout<<ans<<"\n";
}
int32_t main()
{
	int t;
	read(t);
	while(t--)solve();
}

