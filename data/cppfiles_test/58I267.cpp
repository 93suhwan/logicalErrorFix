#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define _setIO() ios::sync_with_stdio(0); cin.tie(0);
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* *oset.find_by_order(index_in_set) :: ret element*/

#define ll long long int
#define ld long double
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll mod = 1000000007;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;

/* _SIEVE_PRIME_FLAG */
int vis[(int)1e6+10];
set<int> primeSet;
void prime_flag(){
for(int i=2; i<(int)1e6+1; i++)
    {if(vis[i]==0){primeSet.insert(i);for(int j=i; j<=1e6; j+=i){vis[j]=1;}}}
}

/*_SORT_FLAG*/
template<typename ty>
bool isrt(vector<ty> v){ 
    if(is_sorted(v.begin(),v.end()) == true)
        return true;
    else return false;}

/*(_BASE, _POW, #mod)*/
long long fastP(long long a, long long b, long long modulus){long long res = 1;while (b > 0){
        if (b & 1)
            res = (res * a) % modulus;
        a = (a * a) % modulus;b = b >> 1;}return res;}

/* _CHECK_PERFECT_SQUARE_FLAG */
bool check_PS(long long n){ 
    double sqrt_n = sqrt(n);if(sqrt_n == int(sqrt_n)){return true;}else{return false;}
}

#define pb push_back
#define inp(type,vec) type x;cin>>x;vec.pb(x); 
#define inc(i,x,n) for(ll i=x;i<n;i++)
#define dec(i,x,n) for(ll i=x;i>=n;i--)
#define step(TC) ll TC;cin>>TC;while(TC--)
#define im INT_MAX
#define in INT_MIN
#define upBound(arr,x) upper_bound(arr.begin(),arr.end(),x)
#define loBound(arr,x) lower_bound(arr.begin(),arr.end(),x)

struct Node{int data;Node *left;Node *right;};
struct node{ll data; node *next; node *prev;};
mt19937 rng;
int getRandomNumber(int l, int r)
{uniform_int_distribution<int> dist(l, r); return dist(rng);}
template<typename T>
void printa(T arr[],ll n){inc(i,0,n){cout<<arr[i]<<" ";}cout<<"\n";}
int __lcm(int a, int b){return (a * b) / __gcd(a, b);}

#define v(x,name) vector<x> name
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define reverse(v) reverse(v.begin(),v.end())
#define sort(v) sort(v.begin(),v.end())
#define digits(n) floor(log10(n)) + 1
#define printv(ar) for(auto x:ar){cout<<x<<" ";}cout<<endl;

/*void init_code(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}*/

#define one_built_ll(n) __builtin_popcountll(n)
#define one_built_int(n) __builtin_popcount(n)

#define mx_ele(dyn) *max_element(dyn.begin(),dyn.end())  
#define mn_ele(dyn) *min_element(dyn.begin(),dyn.end())  
#define mset(arr,x) memset(arr,x,sizeof(arr))

/*-----start-----*/

void solve(){
    //generateCases
    step(TC){
        ll n;
        cin>>n;
        char m[2][n];
        inc(i,0,2){
            inc(j,0,n){
                cin>>m[i][j];
            }
        }
        bool kr = true;
        inc(i,0,n-1){
            if(m[0][i] == '1' and m[0][i+1] == '1' and m[1][i+1] == '1' and m[1][i]=='1'){
                kr=false;
            }
        }
        if(kr==true){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
int main(){
    _setIO()
    solve();
}