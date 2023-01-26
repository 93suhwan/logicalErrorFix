//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,t1,t2;
inline bool cmp(pii x,pii y){
	return x.second<y.second;
}
struct S{
	pii a[100002],b[100002];
	int cnt;
}s[4];
inline bool orz(int p,int x){
	int ff=s[p].a[x].first;
	int qwq=(p==1?3:p-1);
	int qaq=1^2^3^p^qwq;
	int cnt=0,tot=0,t1=0,t2=2e9;
	F(i,1,n){
		if(s[qwq].b[i].first>ff)++cnt,t1=s[qwq].b[i].second;
		if(cnt==x)break;
	}
	UF(i,n,1){
		if(s[qaq].b[i].first>ff)++tot,t2=s[qaq].b[i].second;
		if(tot==x)break;
	}
	if(cnt==x&&tot==x&&t1<t2)return true;
	ff=s[p].a[n-x+1].first;
	cnt=tot=t1=0;t2=2e9;
	F(i,1,n){
		if(s[qwq].b[i].first<ff)++cnt,t1=s[qwq].b[i].second;
		if(cnt==x)break;
	}
	UF(i,n,1){
		if(s[qaq].b[i].first<ff)++tot,t2=s[qaq].b[i].second;
		if(tot==x)break;
	}
	if(cnt==x&&tot==x&&t1<t2)return true;
	swap(qwq,qaq);
	cnt=tot=t1=0;t2=2e9;
	F(i,1,n){
		if(s[qwq].b[i].first<ff)++cnt,t1=s[qwq].b[i].second;
		if(cnt==x)break;
	}
	UF(i,n,1){
		if(s[qaq].b[i].first<ff)++tot,t2=s[qaq].b[i].second;
		if(tot==x)break;
	}
	if(cnt==x&&tot==x&&t1<t2)return true;
	ff=s[p].a[x].first;
	cnt=tot=t1=0;t2=2e9;
	F(i,1,n){
		if(s[qwq].b[i].first>ff)++cnt,t1=s[qwq].b[i].second;
		if(cnt==x)break;
	}
	UF(i,n,1){
		if(s[qaq].b[i].first>ff)++tot,t2=s[qaq].b[i].second;
		if(tot==x)break;
	}
	if(cnt==x&&tot==x&&t1<t2)return true;
	return false;
}
inline bool check(int x){
	F(i,1,3)if(orz(i,x))return true;
	return false;
}
int main() {
	cin>>n;
	F(i,1,n){
		read(t1);read(t2);
		int p=read();
		++s[p].cnt;
		s[p].a[s[p].cnt]=s[p].b[s[p].cnt]=make_pair(t1,t2);
	}
	n/=3;
	F(i,1,3)sort(s[i].a+1,s[i].a+n+1),sort(s[i].b+1,s[i].b+n+1,cmp);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	r=n;
	F(i,1,3){
		F(j,1,n){
			swap(s[i].a[j],s[i].b[j]);
			swap(s[i].a[j].first,s[i].a[j].second);
			swap(s[i].b[j].first,s[i].b[j].second);
		}
	}
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l*3;
	return 0;
}
