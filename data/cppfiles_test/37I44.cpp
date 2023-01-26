#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=998244353;
const int N=1e5+5;
int d[N],w[N],ans[N];
vector<int> v[N],tmp;
int n;
queue<int> q;
ll qpow(ll a,ll n){
	ll re=1;
	while(n>0){
		if(n&1){
			re*=a;
			re%=mod;
		}
		a*=a;
		a%=mod;
		n>>=1;
	}
	return re;
}
void run(int x){
	for(int i=1;i<=n;i++){
		d[i]=v[i].size();
		w[i]=0;
		if(d[i]==1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(auto to:v[top]){
			d[to]--;
			w[to]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(w[top]%x==0){
			for(auto to:v[top]){
				d[to]--;
				if(d[to]>=1){
					w[to]++;
				}
				if(d[to]==1){
					q.push(to);
				}
			}
		}
		else if(w[top]%x==x-1){
			for(auto to:v[top]){
				d[to]--;
				if(d[to]>=1){
					w[top]++;
				}
				if(d[to]==1){
					q.push(to);
				}
			}
		}
	}
	int g=0;
	for(int i=1;i<=n;i++){
		g=__gcd(g,w[i]);
	}
	if(g==x)
	ans[x]=1;
	
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].pb(y);v[y].pb(x);
		}
		int up=sqrt(n-1);
		for(int i=1;i<=up;i++){
			if((n-1)%i==0){
				tmp.pb(i);
				if(i!=(n-1)/i){
					tmp.pb((n-1)/i);
				}
			}
		}
		for(int i=1;i<tmp.size();i++){
			run(tmp[i]);
		}
		ans[1]=qpow(2,n-1);
		for(int i=2;i<=n;i++){
			ans[1]+=mod-ans[i];
			ans[1]%=mod;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
			ans[i]=0;v[i].clear();
		}
		
		tmp.clear();
		printf("\n");
	}
	return 0;
}
