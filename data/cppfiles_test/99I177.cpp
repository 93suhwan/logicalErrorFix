///  In the name of ALLAH
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
#define PB push_back
#define PF push_front
#define FF first
#define SS second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).rbegin,(a).rend()
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define fix fixed<<setprecision(10)
 
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
 
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return a*(b/__gcd(a,b)); }

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

/// Policy Based Data Structure 
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item
*/
 
/**************************************************************start**************************************************************/

void Solution(void){
    
    ll a,b;
    cin>>a>>b;

    if(b<4){
        for(ll i=1; i<=b; i++){
            if(a&1LL){
                a+=i;
            }
            else{
                a-=i;
            }
        }
        cout<<a<<endl;
        return;
    }

    ll mod=b%4LL;

    if(mod==0){
        cout<<a<<endl;
    }
    else{
        
        ll i=((1LL*(b/4LL))*4LL) + 1LL,j=0;

        for(; j<mod; j++,i++){
            if(a&1LL){
                a+=i;
            }
            else{
                a-=i;
            }
        }
    }
    cout<<a<<endl;
    return;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    
    optimize();
    
//	#ifndef ONLINE_JUDGE
//    	freopen("input.txt", "r", stdin);
//    	freopen("output.txt", "w", stdout);
//    	freopen("Error.txt", "w", stderr);
//	#endif

    int testcase;	cin>>testcase;

    for(int tc=1; tc<=testcase; tc++){
        Solution();
    }
    
    return 0;
}

/// ALHAMDULILLAH