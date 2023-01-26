/*OM NAMAH SHIVAAY*/
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required 
// #include <boost/lexical_cast.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) 
#define forrc(i,r,l) for (int i= (int)(r); i>= (int)(l); --i)

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin, (x).rend() 


#define tr(c,i) for(_typeof_((c)).begin() i = (c).begin(); i != (c).end(); i++)


#define present(c,x) ((c).find(x) != (c).end())


#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sz(a) int((a).size())

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

#define count1(x) __builtin_popcount(x)
#define count1ll(x) __builtin_popcountll(x)
#define leadzero(x) __builtin_clz(x)
#define trailzero(x) __builtin_ctz(x)


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<ll,ll>> vpll;
typedef double ld;
typedef long long ll;
typedef unsigned long long int ull;
//ORDERED STATISTICS TREE
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T> using ordered_map =  tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T> using ordered_multimap =  tree<T, int, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//IMPORTANT FUNCTIONS OF ORDERED STATISTICS TREE:
//order_of_key() : gives number of elements with keys strictly smaller than passed key.
//find_by_order() : gives the iterator to the k_th key. 

//unhackable unordered_map and gp_hash_table:-
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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


ull binpow(ull a, ull b, ull m) {
    a %= m;
    ll rem = 1;
    while (b > 0) {
        if (b & 1)
            rem = rem * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return rem;
}


const int MOD=1000000007;
int no_of_bits(long long n)
{
    int count=0;
    while(n>0)
    {
        n=n>>1;
        count++;
    }
    return count;
}
ll GCD_coeff(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
ll LCM(ll a,ll b){
    ll x,y;
    return a/GCD_coeff(a,b,x,y)*b;
}
const int INF=-2000;
const ll INF_=1e13;
ll minll(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll maxll(ll a,ll b){
    if(a<b) return b;
    else return a;
}
void make_set(vll &parent,vll &rank,int v){
    parent[v]=v;
    rank[v]=0;
}
int find_set(vll &parent,int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent,parent[v]);
}
void union_sets(vll &parent,vll &rank,int a,int b){
    a=find_set(parent,a);
    b=find_set(parent,b);
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b]=a;
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}


void solve(){
    ll n,k;
    cin>>n>>k;
    set<vector<ll>>ycor,timer,xcor;
    vector<vector<ll>>val;
    for(int i=0;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        vll v={x,y,z};
        val.push_back(v);
        timer.insert({z,x,y,i});
        xcor.insert({x,y,z,i});
        ycor.insert({y,x,z,i});
    }
    
    vll parent(n),rank(n);
    for(int i=0;i<n;i++){
        make_set(parent,rank,i);
    }
    
    while(timer.size()){
        auto p=*timer.rbegin();
        queue<vector<ll>>q;
        q.push(p);
        
        while(q.size()){
            auto p=q.front();
            q.pop();
            timer.erase(p);
            xcor.erase({p[1],p[2],p[0],p[3]});
            ycor.erase({p[2],p[1],p[0],p[3]});
            auto r=xcor.upper_bound({p[1]-k-1,-1,-1,-1});
            for(auto s=r;s!=xcor.end();s++){
                auto t=*s;
                if(abs(t[0]-p[1])<=k&&p[2]==t[1]){
                    q.push({t[2],t[0],t[1],t[3]});
                    parent[t[3]]=parent[p[3]];
                }
                else if(abs(t[0]-p[1])>k)break;
            }
            r=ycor.upper_bound({p[2]-k-1,-1,-1,-1});
            for(auto s=r;s!=ycor.end();s++){
                auto t=*s;
                if(abs(t[0]-p[2])<=k&&t[1]==p[1]){
                    q.push({t[2],t[1],t[0],t[3]});
                    parent[t[3]]=parent[p[3]];
                }
                else if(abs(t[0]-p[2])>k) break;
            }
        }
    }
    set<vector<ll>>s;
    for(int i=0;i<n;i++){
        s.insert({val[parent[i]][2],parent[i]});
    }
    vector<ll>ans;
    for(auto x:s){
        ans.push_back(x[0]);
    }
    ll ans2=1000000007,count=0;
    for(ll i=ans.size()-1;i>=0;i--){
        
        if(i>0){
            ans2=minll(ans2,maxll(count,ans[i-1]));
        }
        else{
            ans2=minll(ans2,count);
        }
        count++;
    }
    cout<<ans2<<'\n';
}
int main(){
    
//  auto start = chrono::high_resolution_clock::now(); 
  
    // unsync the I/O of C and C++. 
    // ios_base::sync_with_stdio(false); 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    // t=1;
    int i=0;
    while(i++<t){
        solve();
    }
    
  
    // auto end = chrono::high_resolution_clock::now(); 
  
    // Calculating total time taken by the program. 
    // double time_taken =  
    //   chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    // time_taken *= 1e-9; 
  
    // cout << "Time taken by program is : " << fixed  
        //  << time_taken << setprecision(9); 
  
}