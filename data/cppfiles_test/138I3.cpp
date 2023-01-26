#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<list>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<time.h>
#include<random>
using namespace std;
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#include<ext/rope>
using namespace __gnu_cxx;

#define int long long
#define PI acos(-1.0)
#define eps 1e-9
#define lowbit(a) ((a)&-(a))
#define mid ((l+r)>>1)
#define mem(x,y) memset(x,y,sizeof x)
typedef pair<int, int> pii;

const int mod = 1e9+7;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
const int INF = 0x3f3f3f3f;
const int N = 1e6+10;
int n,m,q,o,ans;
struct edge{
	int id,w;
	bool friend operator <(edge a,edge b){
		return a.w>b.w;
	}
};
struct data{
	int id,w,ans;
}Q[N];
bool cmp1(data a,data b){return a.w<b.w;}
bool cmp2(data a,data b){return a.id<b.id;}
vector<pii>f,p;
vector<int>pre;
int find(int x){return x==f[x].first?x:f[x].first=find(f[x].first);}
void merge(int x,int y){
	int fx=find(x),fy=find(y);	
	//cout<<f[fx].second<<" "<<f[fy].second<<endl;
	//cout<<"Del:"<<pre[f[fx].first]-pre[f[fx].first-f[fx].second]+pre[f[fy].first]-pre[f[fy].first-f[fy].second]<<endl;
	ans-=pre[f[fx].first]-pre[f[fx].first-f[fx].second];
	ans-=pre[f[fy].first]-pre[f[fy].first-f[fy].second];
	f[fy].second+=f[fx].second;
	ans+=pre[f[fy].first]-pre[f[fy].first-f[fy].second];
	//cout<<"ADD:"<<pre[f[fy].first]-pre[f[fy].first-f[fy].second]<<endl<<endl;
	f[fx].second=0;
	f[fx].first=fy;
}
#define endl '\n'
signed main(){
	//freopen("C:\\Users\\egoist\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\egoist\\Desktop\\out.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q; o=n+m;
	pre=vector<int>(o+10,0);
	f=p=vector<pii>(o+10);
	for(int i=1;i<=o;i++){
		int x; cin>>x;
		p[i]={x,i<=n};
		ans+=x*(i<=n);
	}
	sort(p.begin()+1,p.begin()+1+o);
	std::priority_queue<edge>pq;
	for(int i=1;i<=o;i++){
		if(i!=o)pq.push({i,p[i+1].first-p[i].first});
		pre[i]=pre[i-1]+p[i].first;
		f[i]={i,p[i].second};
	}
	for(int i=1;i<=q;i++){
		cin>>Q[i].w; Q[i].id=i;
	}
	sort(Q+1,Q+1+q,cmp1);
	for(int i=1;i<=q;i++){
		int W=Q[i].w;
		edge now=pq.top();
		while(now.w<=W){
			cout<<"Merge: "<<now.id<<" "<<now.id+1<<" in:"<<W<<endl;
			merge(now.id,now.id+1);
			pq.pop();
			now=pq.top();
		}
		Q[i].ans=ans;
	} 
	sort(Q+1,Q+1+q,cmp2);
	for(int i=1;i<=q;i++)cout<<Q[i].ans<<endl;
}

