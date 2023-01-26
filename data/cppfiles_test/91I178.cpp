#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define inv(n) power((n), mod - 2)
#define ff(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define fff(i,a,b) for (int (i) = (a); (i) <= b; (i)++)
#define bff(i,a,b) for (int (i) = (b)-1; (i) >= (a); (i)--)
#define bfff(i,a,b) for (int (i) = (b); (i) >= (a); (i)--)
#define sum_overflow(a,b) __builtin_add_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)
#define mul_overflow(a,b) __builtin_mul_overflow_p (a, b, (__typeof__ ((a) + (b))) 0)

using namespace std;
long double typedef ld;
unsigned int typedef ui;
long long int typedef li;
pair<int,int> typedef pii;
pair<li,li> typedef pli;
pair<ld,ld> typedef pld;
vector<vector<int>> typedef graph;
unsigned long long int typedef ull;
const int mod = 998244353;
//const int mod = 1000000007;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;







//Note to self: Check for overflow

multiset<li> zbirs;
multiset<li> out[100005];

set<pair<int,pii>> ed;
map<pii,int> veza;

li outer(int x)
{
    if (out[x].size()<3) return 1e13;
    int ans=0;
    auto it=out[x].begin();
    ans+=*it++,ans+=*it++;
    return ans+*it;
}

void Add(int u, int v, int w)
{
    if (u>v) swap(u,v);
    veza[{u,v}]=w;
    ed.insert({w,{u,v}});
    auto it=zbirs.find(outer(u));
    if (it!=zbirs.end()) zbirs.erase(it);
    it=zbirs.find(outer(v));
    if (it!=zbirs.end()) zbirs.erase(it);
    out[u].insert(w);
    out[v].insert(w);
    zbirs.insert(outer(u));
    zbirs.insert(outer(v));
    ed.insert({w,{u,v}});
}

void Remove(int u, int v)
{
    if (u>v) swap(u,v);
    int w=veza[{u,v}];
    ed.erase({w,{u,v}});
    auto it=zbirs.find(outer(u));
    if (it!=zbirs.end()) zbirs.erase(it);
    it=zbirs.find(outer(v));
    if (it!=zbirs.end()) zbirs.erase(it);
    out[u].erase(out[u].find(w));
    out[v].erase(out[v].find(w));
    zbirs.insert(outer(u));
    zbirs.insert(outer(v));
}

li zbuni()
{
    if (zbirs.empty()) return 1e13;
    return *zbirs.begin();
}

bool conflict(pii a, pii b){
    return a.xx==b.xx || a.xx==b.yy || a.yy==b.xx || a.yy==b.yy;
}

li rijesi(vector<pair<int,pii>> eds)
{
    li ans=1e13;
    ff(i,1,eds.size()) ff(j,0,i)
        if (!conflict(eds[i].yy,eds[j].yy))
            ans=min(ans,(li)eds[i].xx+eds[j].xx);
    return ans;
}

vector<pair<int,pii>> convert(set<pair<int,pii>> &exd)
{
    vector<pair<int,pii>> ans;
    int br=0;
    for (auto it : exd)
    {
        if (br==6) break;
        ans.pb(it),br++;
    }
    return ans;
}

int main()
{
    FAST;

    int n,m; cin>>n>>m;
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Add(u,v,w);
    }

    //fff(i,1,n) cout<<outer(i)<<" "; cout<<endl;

    cout<<min(zbuni(),rijesi(convert(ed)))<<"\n";

    int q; cin>>q;
    while (q--)
    {
        int t; cin>>t;
        if (t==0)
        {
            int u,v;
            cin>>u>>v;
            Remove(u,v);
        }
        else
        {
            int u,v,w;
            cin>>u>>v>>w;
            Add(u,v,w);
        }

        cout<<min(zbuni(),rijesi(convert(ed)))<<"\n";
    }
}

//Note to self: Check for overflow
