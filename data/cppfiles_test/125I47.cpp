//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
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
	inline void write(T x ) {
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
int fa[1202],p[1202],col[1202],tag[1202],pre[1202],t1,t2,tot,ans,q[1202],l,r,n,nn,m;
pii ttag[1202];
vector<int>g[1202];
bool gg[1202][1202];
pii kk[1202][1202];
int a[300002],v[1202],ff[1202],A[300002];
inline int findf(int pos){
	return fa[pos]==pos?pos:(fa[pos]=findf(fa[pos]));
}
inline void rev(int pos){
	while(pos){
		p[pos]=pre[pos];
		swap(pos,p[pre[pos]]);
	}
}
inline int lca(int x,int y){
	for(++tot;tag[x=findf(x)]!=tot;x=pre[p[x]],swap(x,y))if(x)tag[x]=tot;
	return x;
}
inline void shrink(int x,int y,int z){
	while(findf(x)!=z){
		pre[x]=y;
		y=p[x];
		fa[x]=fa[y]=z;
		if(col[y]==2)col[y]=1,q[++r]=y;
		x=pre[y];
	}
}
inline bool bfs(int pos){
	F(i,1,n)fa[i]=i;
	memset(col,0,sizeof(col));
	memset(pre,0,sizeof(pre));
	l=1,r=1;
	q[1]=pos;
	col[pos]=1;
	while(l<=r){
		pos=q[l++];
		for(int nxt:g[pos]){
			if(!col[nxt]){
				pre[nxt]=pos;
				if(!p[nxt]){
					rev(nxt);
					return true;
				}
				col[nxt]=2;
				col[p[nxt]]=1;
				q[++r]=p[nxt];
			}else if(col[nxt]==1){
				int x=lca(pos,nxt);
				shrink(pos,nxt,x);
				shrink(nxt,pos,x);
			}
		}
	}
	return false;
}
inline bool ed(int x,int y){
	if(p[x]==114514||p[y]==114514||gg[x][y]||x==y)return false;
		#define t1 x
		#define t2 y
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		if(!p[t1]&&!p[t2])p[t1]=t2,p[t2]=t1,++ans;
		#undef t1
		#undef t2
	gg[x][y]=gg[y][x]=true;
	return true;
}
inline int findff(int x){
	return (ff[x]==x)?x:(ff[x]=findf(ff[x]));
}
inline void merge(int x,int y){
	if(!x)v[findff(y)]=true;
	else if(!y)v[findff(x)]=true;
	else if(findff(x)==findff(y))v[ff[x]]=true;
	else{
		v[ff[y]]|=v[ff[x]];
		ff[ff[x]]=ff[y];
	}
}
bool vis[300002];
vector<int>vec;
int main(){
	cin>>n;nn=n;
	n=min(n,600);int nnn=n;F(i,1,n)fa[i]=i;
	F(i,1,nn){
		read(a[i]);vis[a[i]]=true;
	}F(i,1,nn)if(!vis[i])vec.push_back(i);
	F(i,1,nn-1)if(a[i]==a[i+1]&&a[i]&&p[i]!=114514){
		p[i]=114514;++ans;
	}a[nn+1]=114514;
	F(i,1,nn){
		if(!a[i]){
			F(j,i+1,nn+1){
				if(a[j]){
					int x=a[i-1],y=a[j];if(j==nn+1)y=0;
					if(j-i&1){
						if((!x&&v[findf(y)])||(!y&&v[findf(x)])||(findf(x)==findf(y)&&v[findf(x)]))continue;
						++n;
						ttag[n]=make_pair(i-1,j);
						if(x)ed(n,x);
						if(y)ed(n,y);
						merge(x,y);
					}else{
						if(x&&y&&ed(x,y)){
							kk[x][y]=kk[y][x]=make_pair(i,j-1);
						}
					}
					ans+=(j-i)/2;
					i=j;
					break;
				}
			}
		}
	}
	F(i,1,n)if(!p[i])ans+=bfs(i);
	memcpy(A,a,sizeof(A));F(i,1,nnn)if(vis[i]&&!p[i])vec.push_back(i);
	F(i,nnn+1,n)if(p[i]){
		if(p[i]==a[ttag[i].first]){
			A[ttag[i].first+1]=p[i];
			for(int j=ttag[i].first+2;j<ttag[i].second;j+=2)A[j]=A[j+1]=vec.back(),vec.pop_back();
		}else{
			A[ttag[i].second-1]=p[i];
			for(int j=ttag[i].first+1;j<ttag[i].second-1;j+=2)A[j]=A[j+1]=vec.back(),vec.pop_back();
		}
	}
	F(i,1,nnn)if(p[i]<=nnn){
		pii temp=kk[i][p[i]];
		A[temp.first]=A[temp.first-1];
		A[temp.second]=A[temp.second+1];
		for(int j=temp.first+1;j<temp.second-1;j+=2)A[j]=A[j+1]=vec.back(),vec.pop_back();
	}
	F(i,1,nn){
		if(!A[i]){
			if(!A[i+1]){
				A[i]=A[i+1]=vec.back();vec.pop_back();
			}else{
				A[i]=vec.back();
			}
		}
	}
	//write(ans,'\n');
	cerr<<ans<<endl;
	F(i,1,nn)write(A[i],' ');
    return 0;
}
