#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007.0
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,k,x[200010],y[200010];
bool vis[200010];

double dist(int xa,int ya,int xb,int yb)
{
	return sqrt(1ll*(xa-xb)*(xa-xb)+1ll*(ya-yb)*(ya-yb));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	vector<pair<int,int> > v;
	v.push_back(make_pair(x[1],1));
	v.push_back(make_pair(x[2],2));
	for(int i=3;i<=n;i++){
		if(1ll*(y[2]-y[1])*(x[i]-x[1])==1ll*(y[i]-y[1])*(x[2]-x[1])) v.push_back(make_pair(x[i],i));
	}
	if(v.size()!=n-1){
		v.clear();
		v.push_back(make_pair(x[1],1));
		v.push_back(make_pair(x[3],3));
		for(int i=2;i<=n;i++) if(i!=3){
			if(1ll*(y[3]-y[1])*(x[i]-x[1])==1ll*(y[i]-y[1])*(x[3]-x[1])) v.push_back(make_pair(x[i],i));
		}
		if(v.size()!=n-1){
			v.clear();
			v.push_back(make_pair(x[2],2));
			v.push_back(make_pair(x[3],3));
			for(int i=1;i<=n;i++) if(i!=2&&i!=3){
				if(1ll*(y[3]-y[2])*(x[i]-x[2])==1ll*(y[i]-y[2])*(x[3]-x[2])) v.push_back(make_pair(x[i],i));
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) vis[v[i].second]=1;
	int id=-1;
	for(int i=1;i<=n;i++) if(!vis[i]){
		id=i;break;
	}
	int pos=-1;
	for(int i=0;i<v.size();i++) if(v[i].second==k){
		pos=i;break;
	}
	double now=dist(v[0].first,y[v[0].second],v.back().first,y[v.back().second]);
	if(pos==-1){
		double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
		double val2=dist(v.back().first,y[v.back().second],x[id],y[id]);
		cout<<fixed<<setprecision(10)<<min(val1,val2)+now<<'\n';
	}
	else if(pos==0){
		double ans=INF;
		for(int i=0;i<v.size()-1;i++){
			double val=dist(v[0].first,y[v[0].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[i+1].first,y[v[i+1].second],x[id],y[id]);
			double val2=dist(v.back().first,y[v.back().second],x[id],y[id]);
			double t=dist(v[i+1].first,y[v[i+1].second],v.back().first,y[v.back().second]);
			ans=min(ans,val+min(val1,val2)+t);
		}
		double len=dist(v.back().first,y[v.back().second],x[id],y[id]);
		ans=min(ans,dist(v[0].first,y[v[0].second],v.back().first,y[v.back().second])+len);
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	else if(pos==v.size()-1){
		double ans=INF;
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size()-1;i++){
			double val=dist(v[0].first,y[v[0].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[i+1].first,y[v[i+1].second],x[id],y[id]);
			double val2=dist(v.back().first,y[v.back().second],x[id],y[id]);
			double t=dist(v[i+1].first,y[v[i+1].second],v.back().first,y[v.back().second]);
			ans=min(ans,val+min(val1,val2)+t);
		}
		double len=dist(v.back().first,y[v.back().second],x[id],y[id]);
		ans=min(ans,dist(v[0].first,y[v[0].second],v.back().first,y[v.back().second])+len);
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	else{
		double ans=INF;
		for(int i=pos;i<v.size()-1;i++){
			double val=dist(v[pos].first,y[v[pos].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v.back().first,y[v.back().second],x[id],y[id]);
			ans=min(ans,val+min(val1,val2)+now);
		}
		double u=dist(v[pos].first,y[v[pos].second],v.back().first,y[v.back().second]);
		for(int i=v.size()-1;i>=pos;i--){
			double val=dist(v[i].first,y[v[i].second],v.back().first,y[v.back().second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v[pos-1].first,y[v[pos-1].second],x[id],y[id]);
			double t=dist(v[0].first,y[v[0].second],v[pos-1].first,y[v[pos-1].second]);
			ans=min(ans,u+val+min(val1,val2)+t);
		}
		u*=2.0;
		for(int i=pos-1;i>0;i--){
			double val=dist(v[pos].first,y[v[pos].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v[i-1].first,y[v[i-1].second],x[id],y[id]);
			double t=dist(v[0].first,y[v[0].second],v[i-1].first,y[v[i-1].second]);
			ans=min(ans,u+val+min(val1,val2)+t);
		}
		u+=dist(v[pos].first,y[v[pos].second],v[0].first,y[v[0].second]);
		ans=min(ans,u+dist(v[0].first,y[v[0].second],x[id],y[id]));
		reverse(v.begin(),v.end());pos=v.size()-pos-1;
		for(int i=pos;i<v.size()-1;i++){
			double val=dist(v[pos].first,y[v[pos].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v.back().first,y[v.back().second],x[id],y[id]);
			ans=min(ans,val+min(val1,val2)+now);
		}
		u=dist(v[pos].first,y[v[pos].second],v.back().first,y[v.back().second]);
		for(int i=v.size()-1;i>=pos;i--){
			double val=dist(v[i].first,y[v[i].second],v.back().first,y[v.back().second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v[pos-1].first,y[v[pos-1].second],x[id],y[id]);
			double t=dist(v[0].first,y[v[0].second],v[pos-1].first,y[v[pos-1].second]);
			ans=min(ans,u+val+min(val1,val2)+t);
		}
		u*=2.0;
		for(int i=pos-1;i>0;i--){
			double val=dist(v[pos].first,y[v[pos].second],v[i].first,y[v[i].second]);
			val+=dist(v[i].first,y[v[i].second],x[id],y[id]);
			double val1=dist(v[0].first,y[v[0].second],x[id],y[id]);
			double val2=dist(v[i-1].first,y[v[i-1].second],x[id],y[id]);
			double t=dist(v[0].first,y[v[0].second],v[i-1].first,y[v[i-1].second]);
			ans=min(ans,u+val+min(val1,val2)+t);
		}
		u+=dist(v[pos].first,y[v[pos].second],v[0].first,y[v[0].second]);
		ans=min(ans,u+dist(v[0].first,y[v[0].second],x[id],y[id]));
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	return 0;
}