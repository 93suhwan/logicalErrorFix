#include <bits/stdc++.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
  

#define pb              push_back
#define ll              long long
#define int             ll
#define SETUP           ios_base::sync_with_stdio(0);cin.tie(0);init();
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define bug(x)          cout << #x << " = " << x << "\n";
#define bug_v(v)        for(int i=0;i<(int)v.size();i++)cout << i << ':' <<v[i] << '\n';
#define bug_m(map)      auto it=map.begin();while(it!=map.end()){cout << it->ff << " " << it->ss << '\n';it++;}
#define TEST            int t;cin >> t;while(t--)tc();
#define TEST0           tc();
#define SORT(v)         sort(all(v));
#define REV(v)          reverse(all(v));
#define loop(i,n)       for(int i=0;i<n;i++)
#define ed              '\n'
#define vi              vector<int>
#define mpii            map<int,int>
#define here            cout << "here\n"
#define prii            pair<int,int>
#define input(a,n)      for(int i=0;i<n;i++) cin >> a[i];
//#define ONLINE_JUDGE

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> oset;

void init(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}
template <typename t>
t gcd(t x, t y){
    if(y==0)return x;
    return gcd(y,x%y);}
template <typename t>
t vgcd(vector<t>a){t res = a[0];ll n= a.size();for(ll i=1;i<n;i++){res = gcd(a[i],res);if(res==1)return 1;}return res;}
bool cmp_str_len(string s1,string s2){return s1.size()<s2.size();}
bool cmp_pair_f(pair<int,int>x,pair<int,int>y){return x.ff<y.ff;}
bool cmp_pair_s(pair<int,int>x,pair<int,int>y){return x.ff>y.ff;}
template <typename t>
t ncr(t n , t r){
    if(r==0){
        return 1;
    }
    ll N = 1;
    ll R = 1;
    while(r){
        N*=n;
        R*=r;
        ll g = gcd(N,R);
        N/=g;
        R/=g;
        n--,r--;
    }
    return N;}
template <typename t>
t powermod(t x, t y, t m){
    int r = 1;
    x=x%m;
    if(!x)return 0;
    while(y>0){
    if(y&1){
        r = (r*x)%m;
    }
    y = y>>1;
    x = (x*x)%m;}return r;}
vector<int> prefix(vector<int>a){
    int n = (int)a.size();
    int s = 0;
    vector<int>r;
    r.pb(0);
    for(int i=0;i<n;i++){
        s+=a[i];
        r.pb(s);
    }
    return r;
}
const int mod = 1e9+7;
//===================================================================================================================================================
void tc(){

       int n;
       cin >> n;
       vector<int>a(n);

       for(int i=0;i<n;i++){
        cin >> a[i];
       }

       SORT(a)

       int m = 1;

       int ans = 0;


       for(int i=0;i<n;i++){

        if(a[i]>=1 && a[i]<=n){
            m++;
            continue;
        }else if(2*m<a[i]){
            ans++;
            m++;
        }else{
            cout << -1 << ed;
            return;
        }

       }

       cout << ans << ed;

}

signed main(){
      SETUP

      TEST

}
