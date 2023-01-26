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
struct qy {
    int value;
    int type;
    int idx;
};
vector<qy> op;
void mem()
{
    int i;
    for(i=0;i<N;i++)
        par[i]=i;
}
bool com(qy a,qy b)
{
    if(a.value==b.value)
        return a.type<b.type;
    return a.value<b.value;
}
int findd(int u)
{
    if(u==par[u])
        return u;
    return par[u]=findd(par[u]);
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
        for(i=0;i<n;i++)
          cin>>a[i],ans+=a[i],oo.pb({a[i],1});
        for(i=0;i<m;i++)
        cin>>b[i],oo.pb({b[i],0});
        sort(oo.begin(),oo.end());
        for(i=0;i<oo.size()-1;i++)
        {
            op.pb({oo[i+1].fr-oo[i].fr,0,i});

        }
        for(i=0;i<oo.size();i++)
        {
            if(oo[i].sc)
                need[i].insert(oo[i].fr);
            else
                notNeed[i].insert(oo[i].fr);
        }
        for(i=0;i<q;i++)
        {
            int x;
            cin>>x;
            op.pb({x,1,i});
        }
        sort(op.begin(),op.end(),com);
        for(i=0;i<op.size();i++)
        {
            if(op[i].type==1)
                res.pb(ans);
            else
            {
                int aa=findd(op[i].idx);
                int bb=findd(op[i].idx+1);
                if(aa==bb)
                    continue;
                if(need[aa].size()+notNeed[aa].size()<need[bb].size()+notNeed[bb].size())
                    swap(aa,bb);
                multiset<int> ::iterator it=need[bb].begin();
                for(it;it!=need[bb].end();it++)
                    need[aa].insert(*it);
                need[bb].clear();
                it=notNeed[bb].begin();
                for(it;it!=notNeed[bb].end();it++)
                   notNeed[aa].insert(*it);
                notNeed[bb].clear();
                while(!need[aa].empty()&&!notNeed[aa].empty())
                {
                    int one=*need[aa].begin();
                    int two=*(--notNeed[aa].end());
                    if(one>=two)
                        break;
                    need[aa].erase(need[aa].begin());
                    notNeed[aa].erase(--notNeed[aa].end());
                    need[aa].insert(two);
                    notNeed[aa].insert(one);
                    ans-=one;
                    ans+=two;
                }
                par[bb]=aa;

            }
        }
        for(i=0;i<res.size();i++)
            cout<<res[i]<<endl;

    }




    return 0;
}
