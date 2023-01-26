#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
#define endl             '\n'
#define f_i_o          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff          first
#define ss          second
#define stt          sort(li.rbegin(), li.rend());
#define pb          push_back
#define te             ll  t; cin >> t; for(ll i=1;i<=t;i++)
#define pr          pair<ll,ll>
#define ve    vector<ll>
#define mp          make_pair
#define mii             map<ll ,ll >
#define pqbig           priority_queue<ll >
#define pqsmall         priority_queue<ll ,vi,greater<ll > >

#define pw(b,p)         pow(b,p) + 0.1
#define fo      front
#define MOD           1e9+7
#define test(x)             cerr<<#x<<' '<<x<<endl;

#define all(x)                x.begin(),x.end()
#define vi                 vector<ll >
#define er          erase
#define st         set<ll>
#define p(x,y)          fixed<<setprecision(y)<<x
// #define prll (x)        for(auto el : x) cout<<el<<' '; cout<<'\n';

#define re          return 0;
#define l0        for(ll  i = 0; i < n; i++)
#define l1              for(ll i=0;i<m;i++)
#define l2            for(ll j=z;j<y+1;j++)
#define l3         for(ll i=0;i<aa.size();i++)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

//-------------------------------------------------------------------------------------------
template<typename T1, typename T2>istream& operator>>(istream& in, pair<T1, T2> &a) {in >> a.fr >> a.sc; return in;}
template<typename T1, typename T2>ostream& operator<<(ostream& out, pair<T1, T2> a) {out << a.fr << " " << a.sc; return out;}
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
void google(ll x) {cout << "Case #" << x << ": ";}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b;}

ll  power(ll x, ll y, ll p)
{
    //fast
    ll res = 1;     x = x % p;  if (x == 0) return 0;
    while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1;  x = (x * x) % p;} return res;
}
bool isInteger(double N)
{ // Convert float value
    // of N to integer
    int X = N;double temp2 = N - X;// If N is not equivalent
// to any integer
    if (temp2 > 0) {
return false;} return true;
}
//----------------------------------------------------------------------------------



void solve()
{
 ll p;
 cin>>p;
 

for(ll i=2;i<p-1;i++)
{

if((p % i)==(p%(i+2)))
{cout<<i<<' '<<i+2<<endl;
return ;
    
}
// 1 
// 2 1
// 15 16 17 
}

}



signed main() {
    f_i_o



    ll t; cin >> t;
    while (t--)

{    solve();
}


    return 0;
}
