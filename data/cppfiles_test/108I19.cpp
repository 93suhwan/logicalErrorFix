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
//const int mod = 998244353;
const int mod = 1000000007;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;







//Note to self: Check for overflow

struct lazytree
{
    int k=1;
    li val[550001],upd[550001];
    int l[550001],r[550001];

    void Build(int n)
    {
        while (k<n) k*=2;
        ff(i,0,k) l[i+k]=i,r[i+k]=i;
        bff(i,1,k) l[i]=l[2*i],r[i]=r[2*i+1];
        ff(i,0,k) val[i+k]=1;
        bff(i,1,k) val[i]=val[2*i]+val[2*i+1];
    }

    void Upd(int p)
    {
        val[p]+=(li)(r[p]-l[p]+1)*upd[p];
        if (p<k) upd[2*p]+=upd[p],upd[2*p+1]+=upd[p];
        upd[p]=0;
    }

    void Add(int p, int ll, int rr, int x)
    {
        if (ll>r[p] || rr<l[p]) Upd(p);
        else if (ll<=l[p] && rr>=r[p]) upd[p]+=x,Upd(p);
        else Upd(p),Add(2*p,ll,rr,x),Add(2*p+1,ll,rr,x),val[p]=val[2*p]+val[2*p+1];
    }

    li Sum(int p, int ll, int rr)
    {
        if (ll>r[p] || rr<l[p]) return 0;
        if (ll<=l[p] && rr>=r[p]) return Upd(p),val[p];
        return Upd(p),Sum(2*p,ll,rr)+Sum(2*p+1,ll,rr);
    }
} ST;

struct node
{
    int mx1,mx2;
    int c1,c2;

    node operator+ (node X)
    {
        vector<pii> cnt,ret;
        cnt.pb({mx1,c1});
        cnt.pb({mx2,c2});
        cnt.pb({X.mx1,X.c1});
        cnt.pb({X.mx2,X.c2});
        sort(all(cnt));
        bff(i,0,3)
        {
            if (cnt[i].xx==cnt[i+1].xx) cnt[i].yy+=cnt[i].yy;
            else ret.pb(cnt[i+1]);
        }
        ret.pb(cnt[0]);

        return {ret[0].xx,ret[1].xx,ret[0].yy,ret[1].yy};
    }
} val[550001];
int upd[550001];
int l[550001],r[550001];
int k=1;

void Upd(int p) ///must guarantee **upd[p]>val[p].mx2** !!!
{
    if (upd[p]>=val[p].mx1) return;
    val[p].mx1=upd[p];
    if (p<k) upd[2*p]=min(upd[2*p],upd[p]),
    upd[2*p+1]=min(upd[2*p+1],upd[p]);
}

void push(int p, int x)
{
    Upd(p);
    if (x>=val[p].mx1) return;
    else if (x>val[p].mx2)
    {
        ST.Add(1,x+1,val[p].mx1,-val[p].c1);
        upd[p]=min(upd[p],x),Upd(p);
        return;
    }

    push(2*p,x),push(2*p+1,x);
    val[p]=val[2*p]+val[2*p+1];
}

void Minw(int p, int ll, int rr, int x)
{
    if (ll>r[p] || rr<l[p]) Upd(p);
    else if (ll<=l[p] && rr>=r[p]) push(p,x);
    else Upd(p),Minw(2*p,ll,rr,x),Minw(2*p+1,ll,rr,x),val[p]=val[2*p]+val[2*p+1];
}

void Set(int p, int s, int x)
{
    if (s>r[p] || s<l[p]) Upd(p);
    else if (s<=l[p] && s>=r[p]) Upd(p),ST.Add(1,val[p].mx1+1,x,1),val[p]={x,-1,1,0};
    else Upd(p),Set(2*p,s,x),Set(2*p+1,s,x),val[p]=val[2*p]+val[2*p+1];
}

int main()
{
    FAST;

    int n,q; cin>>n>>q;
    ST.Build(n);

    while (k<n) k*=2;
    ff(i,0,k) l[i+k]=i,r[i+k]=i;
    bff(i,1,k) l[i]=l[2*i],r[i]=r[2*i+1];
    ff(i,0,k) val[i+k]={i,-1,1,0};
    bff(i,1,k) val[i]=val[2*i]+val[2*i+1];
    ff(i,1,2*k) upd[i]=mod;

    //ispisi();

    while (q--)
    {
        int t; cin>>t;
        if (t==1)
        {
            int s,x;
            cin>>s>>x;
            s--,x--;
            Set(1,s,x);
            Minw(1,0,s-1,s-1);
        }
        else
        {
            int ll,rr; cin>>ll>>rr; ll--,rr--;
            cout<<ST.Sum(1,ll,rr)<<"\n";
        }

        //cout<<flush;
        //ispisi();
    }
}

//Note to self: Check for overflow

/*

10 15
1 2 5
1 2 6
1 6 9
1 8 8
1 1 9
1 7 10
1 4 8
1 1 5
1 7 7
1 4 5
1 2 3
1 6 7
1 2 5
1 4 10
2 3 10

*/
