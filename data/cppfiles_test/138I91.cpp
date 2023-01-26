#include <bits/stdc++.h>
#define pb push_back
#define sc second
#define fr first
#define mk make_pair
#define ll long long
#define ii pair<ll,ll>
#define mp make_pair
#define scn(x) scanf("%d",&x)
#define Kart ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef  long long intt;
using namespace std;
const int N=500004;
multiset<int> need[N],notNeed[N];
int a[N];
int b[N];
int par[N];
ll ans=0;
vector<ll> res;
vector<ii> oo;
struct qy
{
    int value;
    int type;
    int idx;
};
vector<qy> op;
void mem()
{
    int i;
    for(i=0; i<N; i++)
        par[i]=i;
}
bool com(qy a,qy b)
{
    if(a.value!=b.value)
        return a.value<b.value;
    return a.type<b.type;
}
int findd(int u)
{
    if(u==par[u])
        return u;
    return par[u]=findd(par[u]);
}
void unite(int a, int b){
	a = findd(a), b = findd(b);
	if (notNeed[a].size() + need[a].size() < notNeed[b].size() + need[b].size()) swap(a, b);
	for (auto it : notNeed[b])
		notNeed[a].insert(it);
	for (auto it : need[b])
		need[a].insert(it);
	notNeed[b].clear();
	need[b].clear();
	while (!need[a].empty() && !notNeed[a].empty() && *need[a].begin() < *notNeed[a].rbegin()){
		ans -= *need[a].begin();
		ans += *notNeed[a].rbegin();
		need[a].insert(*notNeed[a].rbegin());
		notNeed[a].insert(*need[a].begin());
		need[a].erase(need[a].begin());
		notNeed[a].erase(--notNeed[a].end());
	}
	par[b] = a;
}
int main()
{
    Kart;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        mem();
        int i;
        for(i=0; i<n; i++)
            cin>>a[i],ans+=a[i],oo.pb({a[i],1});
        for(i=0; i<m; i++)
            cin>>b[i],oo.pb({b[i],0});
        sort(oo.begin(),oo.end());

        for(i=0; i<n+m; i++)
        {
            par[i] = i;
		need[i].clear();
		notNeed[i].clear();
            if(oo[i].sc)
                need[i].insert(oo[i].fr);
            else
                notNeed[i].insert(oo[i].fr);
        }
        for(i=0; i<n+m-1 ;i++)
        {
            op.pb({oo[i+1].fr-oo[i].fr,0,i});

        }
        for(i=0; i<q; i++)
        {
            int x;
            cin>>x;
            op.pb({x,1,i});
        }
        sort(op.begin(),op.end(),com);
        for(i=0; i<op.size(); i++)
        {
            if(op[i].type==1)
                res.pb(ans);
            else
            {
              unite(op[i].idx,op[i].idx+1);

            }
        }
        for(i=0; i<res.size(); i++)
            cout<<res[i]<<endl;

    }




    return 0;
}
