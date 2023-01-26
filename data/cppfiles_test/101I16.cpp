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
#define mod 998244353  
#define pie 3.14159265359
const ll inf=1e15;
#define minheap priority_queue<int , vector<int> , greater<int> > 
#define maxheap priority_queue<int> 	
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
#define debug(n) cout<<#n<<" "<<n<<"\n";
#define pii pair<ll,pair<ll,ll>>
#define pi pair<ll,ll>

int main()
{
	fast;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,k,i,j;
		cin>>n>>m>>k;
		vector<ll> ax,ay;
		for(i=0;i<n;i++)
		{
			cin>>j;
			ax.pb(j);
		}
		for(i=0;i<m;i++)
		{
			cin>>j;
			ay.pb(j);
		}
		sort(ax.begin(),ax.end());
		sort(ay.begin(),ay.end());
		vector<pair<ll,ll>> v(k);
		vector<ll> x(k),y(k);
		map<ll,vector<ll>> mpx,mpy;
		for(i=0;i<k;i++)
		{
			cin>>v[i].ss>>v[i].ff;
			x[i]=v[i].ss;
			y[i]=v[i].ff;
			mpx[x[i]].pb(y[i]);
			mpy[y[i]].pb(x[i]);
		}
		for(auto x:mpx)
		{
			sort(mpx[x.ff].begin(),mpx[x.ff].end());
		}
		for(auto x:mpy)
		{
			sort(mpy[x.ff].begin(),mpy[x.ff].end());
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		sort(v.begin(),v.end());
		ll ansx=0;
		ll ansy=0;
		for(i=0;i<k;i++)
		{
			ll px=v[i].ss;
			ll py=v[i].ff;
			bool isX=false,isY=false;
			if(binary_search(ax.begin(),ax.end(),px))
			isX=true;
			if(binary_search(ay.begin(),ay.end(),py))
			isY=true;
			if(isX && isY)
			continue;
			if(isX)
			{
				// find the nearest Y-road upwards;
				ll nearY=*lower_bound(ay.begin(),ay.end(),py);
				// find the # of elements bw Y-road and py;
				ll num1=(lower_bound(y.begin(),y.end(),nearY)-y.begin());
				ll num2=(upper_bound(y.begin(),y.end(),py)-y.begin());
				ansx=(ansx+(num1-num2));
				// minus which are at the same x
				num1=(lower_bound(mpx[px].begin(),mpx[px].end(),nearY)-mpx[px].begin());
				num2=(upper_bound(mpx[px].begin(),mpx[px].end(),py)-mpx[px].begin());
				ansx=(ansx-(num1-num2));
				continue;
			}
			// isY
			ll highX=*upper_bound(ax.begin(),ax.end(),px);
			auto it=lower_bound(ax.begin(),ax.end(),px);
			it--;
			ll lowX=*it;
			ll num1=lower_bound(x.begin(),x.end(),highX)-x.begin();
			// #pts with X>low
			ll num2=(upper_bound(x.begin(),x.end(),lowX)-x.begin());
			// #pts with X>=high
			ansy+=(num1-num2);
			
			num1=(lower_bound(mpy[py].begin(),mpy[py].end(),highX)-mpy[py].begin());
			num2=(upper_bound(mpy[py].begin(),mpy[py].end(),lowX)-mpy[py].begin());
			ansy=(ansy-(num1-num2));
		}
		ansy/=2;
		ll ans=(ansx+ansy);
		cout<<ans<<"\n";
		
	}
}