#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
//This template is compiled by zscoder.
 
//O(V^2E) Dinic Flow
//Initialize : MaxFlow<# of vertices, Max Value> M;
template<int MX, ll INF> struct MaxFlow //by yutaka1999, have to define INF and MX (the Max number of vertices)
{
    struct edge
    {
        int to,cap,rev;
        edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
    };
    vector <edge> vec[MX];
    int level[MX];
    int iter[MX];
    
    void addedge(int s,int t,int c) //adds an edge of cap c to the flow graph
    {
        int S=vec[s].size(),T=vec[t].size();
        vec[s].push_back(edge(t,c,T));
        vec[t].push_back(edge(s,0,S));
    }
    void bfs(int s)
    {
        memset(level,-1,sizeof(level));
        queue <int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty())
        {
            int v = que.front();que.pop();
            for(int i=0;i<vec[v].size();i++)
            {
                edge&e=vec[v][i];
                if (e.cap>0&&level[e.to]<0)
                {
                    level[e.to]=level[v]+1;
                    que.push(e.to);
                }
            }
        }
    }
    ll flow_dfs(int v,int t,ll f)
    {
        if (v==t) return f;
        for(int &i=iter[v];i<vec[v].size();i++)
        {
            edge &e=vec[v][i];
            if (e.cap>0&&level[v]<level[e.to])
            {
                ll d=flow_dfs(e.to,t,min(f,ll(e.cap)));
                if (d>0)
                {
                    e.cap-=d;
                    vec[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll maxflow(int s,int t) //finds max flow using dinic from s to t
    {
        ll flow = 0;
        while(1)
        {
            bfs(s);
            if (level[t]<0) return flow;
            memset(iter,0,sizeof(iter));
            while (1)
            {
                ll f=flow_dfs(s,t,INF);
                if(f==0) break;
                flow += f;
            }
        }
    }
};
//End Dinic Flow
 
//Sparse Table Struct
//SparseTable<ll, 1000001, 20, ll(1e18)> ST;
template<typename TT, int MX, int LG, ll INF> struct SparseTable //Warning : Change query return value manually if needed. INF is the dummy val
{
    TT st[LG][MX];
    TT initial[MX];
    
    TT combine(TT a, TT b) //warning : change if neccesary
    {
        if(a<b) return a;
        return b;
    }
    
    SparseTable()
    {
        for(int i = 0; i < MX; i++) initial[i] = INF;
    }
    
    void init()
    {
        for(ll j = 0; j < LG; j++)
        {
            for(ll i = 0; i < MX; i++)
            {
                st[j][i] = INF;
                if(i + (1<<j) - 1 < MX)
                {
                    if(j == 0) st[j][i] = initial[i];
                    else st[j][i] = combine(st[j-1][i], st[j-1][i + (1<<(j-1))]);
                }
            }
        }
    }
    
    TT query(int l, int r)
    {
        int k = 31 - __builtin_clz(r-l);
        if(l==r) k=0;
        return combine(st[k][l], st[k][r - (1<<k) + 1]);
    }
};
 
//Segment Tree Lazy Prop begin. node and update are just samples and should be changed according to problem
//use init, upd, and query function ([l, r])
//REMEMBER TO SET WIDTH WHEN INIT LEAVES!
template<typename T, typename U> struct SegmentTree //by socketnaut. see http://codeforces.com/blog/entry/20528
{
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty; //a.k.a is_lazy
    vector<U> prop; //the update array
 
    SegmentTree<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void init(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};
 
struct node 
{
    int sum, width;
    
    node operator+(const node &n) 
    {
        node tmp;
        tmp.sum = sum + n.sum;
        tmp.width = width + n.width;
        return tmp;
    }    
};
 
struct update {
    bool type; // 0 for add, 1 for reset
    int value;
 
    node operator()(const node &n) 
    {
        node tmp;
        if (type) 
        {
            tmp.sum = n.width * value;
            tmp.width = n.width;
        }
        else 
        {
            tmp.sum = n.sum + n.width * value;
            tmp.width = n.width;
        }
        return tmp;
    }
 
    update operator+(const update &u) 
    {
        update tmp;
        if (u.type) return u; //since it's a reset
        tmp.type = type;
        tmp.value = value + u.value;
        return tmp;
    }
};
bool isPower(long long int x, long long int y)
{
   
    long long int res1 = log(y) / log(x);
    long double res2 = log(y) / log(x); 
 

    return (res1 == res2);
}
bool isPrime(long long int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
long long primef(long long int n)
{
    long long int c=0;
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        
        while (n % i == 0)
        {
            c++;
            n = n/i;
        }
    }
    if(n>2)
        c++;
   return c;
}
bool isPowerOfTwo (long long int x) 
{ 
   
    return x && (!(x&(x-1))); 
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(-9999999999999ms);
    long long int t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll a[n];
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
       }
       string s;
       cin>>s;
       vector<long long int>v;
       long long int c=0;
       for(int i=0;i<n;i++)
       {
        v.pb(0);
        if((s[i]=='R' && a[i]>n) || (s[i]=='B' && a[i]<=0))
            c++;
       }
       //cout<<c<<endl;
       if(c==0)
       {
           long long int k=0,k1=0;
           for(int i=0;i<s.length();i++)
           {
            if(s[i]=='R')
            {
                if(a[i]==n)
                    k++;
            }
            if(s[i]=='B')
            {
                if(a[i]==1)
                    k1++;
            }
           }
           if(k>=2 || k1>=2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

   else
   {
    cout<<"NO"<<endl;
   }

    }
}