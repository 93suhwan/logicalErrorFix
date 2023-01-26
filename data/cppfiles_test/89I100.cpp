#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define mod 1000000007 
#define pie 3.14159265359
const ll inf=1e15;
#define minheap priority_queue<int , vector<int> , greater<int> > 
#define maxheap priority_queue<int> 	
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
#define debug(n) cout<<#n<<" "<<n<<"\n";
#define pii pair<ll,pair<ll,ll>>
#define pi pair<ll,ll>
const ll N=2e5+5;
vector<ll> g[N];
ll bud_leaf,buds,leaf;
ll parent[N];
vector<ll> which;
ll isbud[N];
void dfs(ll node,ll par)
{
	ll cnt=0;
	parent[node]=par;
	for(auto x:g[node])
	{
		if(x==par)
		continue;
		if(g[x].sz==1)
		cnt++;
	}
	if(node!=1)
	{
		if(cnt==(g[node].sz-1))
		{
			bud_leaf+=cnt;
			buds++;
			which.pb(node);
			return ;
		}
	}
	leaf+=cnt;
	for(auto x:g[node])
	{
		if(x==par || (g[x].sz==1))
		continue;
		dfs(x,node);
	}
	
}
int main()
{
	//fast;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,j;
		ll u,v;
		cin>>n;
		for(i=1;i<=n;i++)
		g[i].clear(),parent[i]=-1,isbud[i]=-1;
		buds=0;
		bud_leaf=0;
		leaf=0;
		for(i=0;i<n-1;i++)
		{
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1,-1);
		ll ct=0;
		
		for(auto x:which)
		{
			ll par=parent[x];
			cout<<par<<" curently: \n";
			if(par==1)
			continue;
			if(par==-1)
			break;
			if(isbud[par]==1)
			continue;
			if(isbud[par]==0)
			continue;
			bool check=true;
			ll count=0;
			while(par!=1)
			{
				ll sy=(g[par].sz);
				if(sy==1)
				{
				if(count==1)
				break;
				count++;
				par=parent[par];
				continue;
				}
				bool check=true;
				for(auto y:g[par])
				{
					if(y==parent[par])
					continue;
					if(g[y].sz!=1)
					{
						check=false;
						break;
					}
				}
				if(check==false)
				{
					isbud[par]=0;
					break;
				}
			}
			if(par==1)
			{
				ct++;
			}
			
		}
		ll ans=0;
		if(buds>0)
		ans+=(bud_leaf-(buds-1));
		ans=max(ans,0ll);
		if(buds>0)
		leaf--;
		leaf=max(0ll,leaf);
		ans+=leaf;
		ans+=ct;
		cout<<ans<<"\n";
	}
}
