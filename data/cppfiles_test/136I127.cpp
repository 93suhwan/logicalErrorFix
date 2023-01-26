#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#define debug(x);
#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif


typedef long long ll;
typedef long double ld;
const ll MOD =1e9+7;

typedef unsigned long long ull;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/************************Copied Template ends here :')****************************/
void show_arr(ll arr[] ,ll n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void show_vec(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    
    
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> b(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            sum+=b[i];
        }
        if(sum%(n*(n+1)/2!=0)){
            cout<<"NO\n";
        }
        else{
            ll sum_a=sum*2/(n*(n+1));
            vector<ll> ans(n,-10);
            ans[0]=(sum_a-b[0]+b[n-1])/n;
            for(int i=1;i<n;i++){
                ans[i]=(sum_a-b[i]+b[i-1])/n;
            }
            bool flag=true;
            for(int i=0;i<n;i++){
                if(ans[i]<=0){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
                for(int i=0;i<n;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
            }
        }
        
        
    }
    

    #ifndef ONLINE_JUDGE
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    #endif
}