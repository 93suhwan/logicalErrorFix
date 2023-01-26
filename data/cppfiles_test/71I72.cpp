//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,k,badnd,dx[N],dy[N];
map<pair<ll,ll>,pair<ll,ll> > mp;
vector<pair<ll,ll> > nd;
double ans;
double getdist(ll tx1,ll ty1,ll tx2,ll ty2)
{
	return sqrt((double)((tx1-tx2)*(tx1-tx2))+(double)((ty1-ty2)*(ty1-ty2)));
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&k);
	k--;
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
	}
	for(i=1;i<n;i++)
	{
		pair<ll,ll> gras=make_pair(dx[i]-dx[0],dy[i]-dy[0]);
		if(gras.F<0)
		{
			gras.F=-gras.F;
			gras.S=-gras.S;
		}
		ll g=__gcd(gras.F,gras.S);
		gras.F/=g;
		gras.S/=g;
		if(mp.count(gras))
		{
			mp[gras].F++;
		}
		else
		{
			mp[gras]=make_pair(1,i);
		}
	}
	if(mp.size()==2)
	{
		map<pair<ll,ll>,pair<ll,ll> >::iterator it=mp.begin();
		if(it->S.F==1)
		{
			badnd=it->S.S;
		}
		else
		{
			it++;
			badnd=it->S.S;
		}
	}
	else
	{
		badnd=0;
	}
	for(i=0;i<n;i++)
	{
		if(i!=badnd)
		{
			nd.push_back(make_pair(dx[i],dy[i]));
		}
	}
	sort(nd.begin(),nd.end());
	ll stx=nd[0].F,sty=nd[0].S,edx=nd[nd.size()-1].F,edy=nd[nd.size()-1].S;
	if(k==badnd)
	{
		ans=min(getdist(stx,sty,dx[k],dy[k]),getdist(edx,edy,dx[k],dy[k]))+getdist(stx,sty,edx,edy);
	}
	else
	{
		for(i=0;i<nd.size();i++)
		{
			if(nd[i].F==dx[k])
			{
				k=i;
				break;
			}
		}
		ans=LINF;
		for(i=0;i<nd.size();i++)
		{
			//k->0->n->badnd or k->n->0->badnd
			double cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(edx,edy,dx[badnd],dy[badnd]);
			cur=min(cur,getdist(nd[k].F,nd[k].S,edx,edy)+getdist(stx,sty,dx[badnd],dy[badnd]));
			cur+=getdist(stx,sty,edx,edy);
			ans=min(ans,cur);
			//k->i->badnd->0->n or k->i->badnd->n->0
			cur=getdist(nd[k].F,nd[k].S,nd[i].F,nd[i].S)+getdist(nd[i].F,nd[i].S,dx[badnd],dy[badnd])+getdist(stx,sty,edx,edy);
			cur+=min(getdist(dx[badnd],dy[badnd],stx,sty),getdist(dx[badnd],dy[badnd],edx,edy));
			ans=min(ans,cur);
			//k->0->i->badnd->n->max(k+1,i+1)
			cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(nd[i].F,nd[i].S,stx,sty);
			cur+=getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S)+getdist(dx[badnd],dy[badnd],edx,edy);
			if(max(k+1,i+1)<nd.size())
			{
				cur+=getdist(nd[max(k+1,i+1)].F,nd[max(k+1,i+1)].S,edx,edy);
			}
			ans=min(ans,cur);
			//k->n->i->badnd->0->min(k-1,i-1)
			cur=getdist(nd[k].F,nd[k].S,edx,edy)+getdist(nd[i].F,nd[i].S,edx,edy);
			cur+=getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S)+getdist(dx[badnd],dy[badnd],stx,sty);
			if(min(k-1,i-1)>=0)
			{
				cur+=getdist(nd[min(k-1,i-1)].F,nd[max(k-1,i-1)].S,edx,edy);
			}
			ans=min(ans,cur);
			//k->0->badnd->i->n->k+1 or k->0->badnd->i->k+1->n (i>k)
			if(i>k)
			{
				cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(stx,sty,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S);
				cur+=getdist(nd[k+1].F,nd[k+1].S,edx,edy)+min(getdist(nd[i].F,nd[i].S,edx,edy),getdist(nd[i].F,nd[i].S,nd[k+1].F,nd[k+1].S));
				ans=min(ans,cur);
			}
			//k->n->badnd->i->0->k-1 or k->n->badnd->i->k-1->0 (i<k)
			if(i<k)
			{
				cur=getdist(nd[k].F,nd[k].S,edx,edy)+getdist(edx,edy,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S);
				cur+=getdist(nd[k-1].F,nd[k-1].S,stx,sty)+min(getdist(nd[i].F,nd[i].S,stx,sty),getdist(nd[i].F,nd[i].S,nd[k-1].F,nd[k-1].S));
				ans=min(ans,cur);
			}
		}
	}
	printf("%.15lf\n",ans);
	return 0;
}