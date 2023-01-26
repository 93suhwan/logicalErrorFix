#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//Define's
#define ull               unsigned long long
#define lld               long double
#define lli               long long int
#define inf               1e18
#define fio               ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define bpc               __builtin_popcount
#define rep(i,a,b)        for(lli i=a;i<b;i++)
#define per(i,a,b)        for(lli i=a;i>=b;i--)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define fi                first
#define se                second
#define sz(x)             (int)((x).size())
#define all(x)            (x).begin(),(x).end()
#define alr(s)            s.rbegin(),s.rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define vi                vector<lli>
#define vvi               vector<vector<lli>>
#define vpi               vector<pair<lli,lli>>
#define pi                pair<lli,lli>
#define pq_max            priority_queue<lli>
#define pqp_max           priority_queue<pi>
#define pq_min            priority_queue<lli, vector<lli>, greater<lli>>
#define pqp_min           priority_queue<pi, vector<pi>, greater<pi>>
#define m_pi              3.141592653589793238

//Typedef's
typedef tree<pair<lli, lli>, null_type, less<pair<lli, lli>>, rb_tree_tag, tree_order_statistics_node_update> omultiset; // store ind on sec
typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<lli, null_type, greater<lli>, rb_tree_tag, tree_order_statistics_node_update> oset1; // decreasing
typedef tree<pair<lli, lli>, null_type, greater<pair<lli, lli>>, rb_tree_tag, tree_order_statistics_node_update> omultiset1;
/*
    member functions :
                1. order_of_key(k) : number of elements strictly lesser than k
                2. find_by_order(k) : k-th element in the set (counting from zero)
*/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(lli t)
{
    cerr << t;
}
void _print(int t)
{
    cerr << t;
}
void _print(string t)
{
    cerr << t;
}
void _print(char t)
{
    cerr << t;
}
void _print(lld t)
{
    cerr << t;
}
void _print(double t)
{
    cerr << t;
}
void _print(ull t)
{
    cerr << t;
}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p)
{
    cerr << "{";
    _print(p.fi);
    cerr << ",";
    _print(p.se);
    cerr << "}";
}
template <class T> void _print(vector <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map <T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
bool is_power_of_two(int a)
{
    return a && (!(a & (a - 1)));
}
bool isSquare(lli x)
{
    lli y = sqrt(x);
    return y * y == x;
}
lli fast_mod_exp(lli a, lli b, lli m)
{
    if(a == 0)
        return (b == 0);
    lli res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;

        a = (a * a) % m;
        b = b >> 1;
    }

    return res;
}
lli power(lli x, lli n)
{
    lli result, y;
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    y = power(x, n / 2);
    result = (y * y);
    if(n % 2 == 1)
        result = (result * x);
    return result;
}
// void sieve()
// {
//     for (int p = 2; p * p < N; p++)
//     {
//         if (prime[p] == true)
//         {

//             for (int i = p * p; i <N; i += p)
//                 prime[i] = false;
//         }
//     }

// }
lli leftmostsetbit(lli n)
{
    lli k = (int)(log2(n));
    return k;
}
lli rightmostsetbit(lli n)
{
    return log2(n & (~(n - 1)));
}
/*
//For changing sorting function in sets

struct compare{
    bool operator()(const pair<lli,lli>& x,const pair<lli,lli>& y)const{  //pass datatypes here
    //write conditions here
        if(x.fi<y.fi) return true;
        else if(x.fi>y.fi) return false;
        else return (x.se>y.se);
    }
};*/


/*lli a[N],seg[2*N];
void build(lli idx,lli low,lli high){
    if(low==high){
        seg[idx]=a[low];
        return;
    }
    lli mid=(low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = (seg[2*idx+1]+seg[2*idx+2]);
}
lli query(lli idx,lli low,lli high,lli l,lli r){
    if(low>=l&&high<=r){
        return seg[idx];
    }
    if(high<l||low>r){
        return 0;
    }
    lli mid=(low+high)>>1;
    lli left = query(2*idx+1,low,mid,l,r);
    lli right = query(2*idx+2,mid+1,high,l,r);
    return (left+right);
}
void update(lli idx,lli low,lli high,lli node,lli val){
    if(low==high){
        seg[idx]=val;
        return;
    }
    lli mid = (low+high)>>1;
    if(node<=mid&&node>=low) update(2*idx+1,low,mid,node,val);
    else update(2*idx+2,mid+1,high,node,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];

}*/
void precalc()
{
    
}
void solve()
{   
    lli n,m,k;
    cin>>n>>m>>k;
    lli bp = (n+m-1)/m; // number of elements in big group
    lli tb = n%m; //number of big groups
    lli sp = n/m; // number of elements in small group
    lli ts = m-n%m;  // number of small groups
    lli tbp = bp*(n%m);
    lli tsp = n-tbp;
    if(tbp==0)
    {
        swap(tbp,tsp);
        swap(sp,bp);
        swap(ts,tb);
    }
    // cout<<bp<<" "<<sp<<" "<<tb<<" "<<ts<<endl;
    lli si = 1;
    while(k--)
    {
        if(tbp)
        {
            for(lli j=0;j<tb;j++)
            {
                cout<<bp<<" ";
                lli cnt = 0;
                lli i;
                for(i=si;;i=i%n+1)
                {
                    cnt++;
                    cout<<i<<" ";
                    if(cnt==bp) break;
                }
                si = i%n+1;
                cout<<endl;
            }
        }
        if(tsp)
        {
            lli sis = si;
            for(lli j=0;j<ts;j++)
            {
                cout<<sp<<" ";
                lli cnt = 0;
                lli i;
                for(i=sis;;i=i%n+1)
                {
                    cnt++;
                    cout<<i<<" ";
                    if(cnt==sp) break; 
                }
                cout<<endl;
                sis = i+1;
            }
        }
        // cout<<endl;
    }
    cout<<endl;
}     
int main()
{
    fio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    precalc();
    // cout << fixed << setprecision(10);
    //Things that can lead to TLE:
    // 1) Not using fio
    // 2) Using endl instead of '\n'
    // 3) Using lli everywhere instead of int

    lli t = 1;
    cin >> t;
    while(t--)
    {
        solve();
        //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    }
}