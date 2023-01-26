#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using minheap=priority_queue<T , vector<T> , greater<T> > ;
template<class T> using maxheap=priority_queue<T>;
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define mod 1000000007 
#define pie 3.14159265359
const ll inf=1e15;	
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
#define debug(n) cout<<#n<<" "<<n<<"\n";
#define pii pair<ll,pair<ll,ll>>
#define pi pair<ll,ll>
int main()
{
	//fast;
	ll t;
	t=1;
	while(t--)
	{
		ll n,i,j;
		cin>>n;
		vector<ll> a(n+1),b(n+1);
		for(i=1;i<=n;i++)
		cin>>a[i];
		for(i=1;i<=n;i++)
		cin>>b[i];
		
		vector<ll> par(n+1,-1);
		vector<ll> slide(n+1,-1);
		vector<ll> dis(n+1,inf);
		dis[n]=0;
		minheap<pair<ll,ll>> q;
		q.push({dis[n],n});
		ll mark=n;
		while(!q.empty())
		{
			auto p=q.top();
			q.pop();
			ll node=p.ss;
			ll low=node-a[node];
			ll high=node;
			if(low==0)
			{
				par[0]=node;
				dis[0]=dis[node]+1;
				break;
			}
			for(i=low;i<min(mark,high);i++)
			{
				par[i]=node;
				ll next=(i+b[i]);
				if(dis[next]>dis[node]+1)
				{
					dis[next]=1+dis[node];
					q.push({dis[next],next});
					slide[next]=i;
				}
			}
			mark=low;
		}
		
		dis[0]=(dis[0]<inf) ? dis[0]:-1;
		cout<<dis[0]<<" \n";
		vector<ll> path;
		ll node=0;
		while(1)
		{
			path.pb(node);
			node=par[node];
			if(node==-1)
			break;
			node=slide[node];
			if(node==-1)
			break;
		}
		reverse(path.begin(),path.end());
		for(auto x:path)
		cout<<x<<" ";
	}
}