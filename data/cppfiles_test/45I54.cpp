#include<iostream>
#include<vector>
#include<cstring>
#include<list>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define pb(a) push_back(a)
#define bg() begin()
#define ed() end()
#define endl "\n"
#define res(a,b) reverse(a(),b())
#define mem(a,b) memset(a,b,sizeof a)
#define ll long long
#define flr(i,l,r) for(int i=l;i<=r;i++)
#define frl(i,r,l) for(int i=r;i>=l;i--)
inline ll lread(){register ll x=0,f=1;register char c=getchar();while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
inline int read(){register int x=0,f=1;register char c=getchar();while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
#define INF 0x3f3f3f3f
using namespace std;
#define std std::ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
int gcd(int a,int b){
	return __gcd(a,b);
}
int qpow(int base,int index){int ret=1;while(index){if(index&1) ret=ret*base;index>>=1;base=base*base;} return ret;}
int lowbit(int x){return x&(-x);}
int a[110];
int main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ans=1;cin>>a[1];
		if(a[1]==1) ans+=1;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]==1&&a[i-1]==1) ans+=5;
			else if(a[i]==0&&a[i-1]==0){ans=-1;break;}
			else if(a[i]==1&a[i-1]==0) ans+=1;
		}
		cout<<ans<<endl;
	}
} 
