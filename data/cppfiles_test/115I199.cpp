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

void solve(){
   ll n,h;
   cin>>n>>h;
   vll v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   ll l=1,r=1000000000;
   ll ans=0;
   while(l<=r){
       int mid=l+(r-l)/2;
       ll f=0,temp=h,prev=-1000000007;
       for(int i=0;i<n;i++)
       {
           if(v[i]-prev>=mid){
               temp-=mid;
           }
           else {
               temp-=v[i]-prev;
           }
           if(temp<=0){
               f=1;
               break;
           }
           prev=v[i];
       }
       if(f){
           ans=mid;
           r=mid-1;
       }
       else {
           l=mid+1;
       }
   }
   cout<<ans<<'\n';
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