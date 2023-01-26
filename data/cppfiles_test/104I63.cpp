#include<bits/stdc++.h>
//#pragma GCC optimize "trapv"
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define fast_az_fuk      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll               long long
#define lll              __int128
#define ull              unsigned ll
#define ld               long double 
#define pb               push_back 
#define pf               push_front
#define dll              deque<ll> 
#define vll              vector<ll>
#define vvll             vector<vll> 
#define pll              pair<ll,ll> 
#define vpll             vector<pll>
#define dpll             deque<pll>
#define mapll            map<ll,ll>
#define umapll           umap<ll,ll>
#define endl             "\n" 
#define all(v)           v.begin(),v.end() 
#define ms(a,x)          memset(a,x,sizeof(a))
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)


//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//using namespace __gnu_pbds;

template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}

const bool tests = 1;
void solve_case(){
    ll n,m; cin>>n>>m;
    vpll v(n); cin>>v;
    ll sum = 0;
    for(int i=0;i<n;i++) sum += v[i].first - v[i].second;
    sum += m*n;
    ll maxS = 0,minS = 0;
    for(int i=0;i<n;i++){
        maxS += min(m,v[i].first);
        minS += max(0LL,m-v[i].second);
    }
    if(sum < 0){
        cout<<abs(sum - 2*minS)<<endl;
        for(int i=0;i<n;i++){
            cout<<max(0LL,m-v[i].second)<<' '<<m-max(0LL,m-v[i].second)<<endl;
        }
        return;
    }
    if(maxS <= sum/2){
        cout<<sum - 2*maxS<<endl;
        for(int i=0;i<n;i++){
            cout<<min(m,v[i].first)<<' '<<min(m,v[i].first)<<endl;
        }
        return;
    }
    if(minS >= sum/2){
        cout<<abs(sum - 2*minS)<<endl;
        for(int i=0;i<n;i++){
            cout<<max(0LL,m-v[i].second)<<' '<<m-max(0LL,m-v[i].second)<<endl;
        }
        return;
    }
    ll x = sum/2;
    vll ans(n,0); for(int i=0;i<n;i++) ans[i] = max(0LL,m-v[i].second),x-=ans[i];
    for(int i=0;i<n;i++){
        ll mx = min(m,v[i].first) - ans[i];
        if(mx <= x){
            ans[i] += mx; x -= mx;
        }
        else{
            ans[i] += x; break;
        }
    } 
    cout<<sum - 2*(sum/2)<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' '<<m-ans[i]<<endl;
    }
}

int32_t main()
{
    #ifdef LOCAL
        freopen("error.txt", "w", stderr);
        clock_t clk = clock();
    #endif
    fast_az_fuk
    ll testcase=1; if(tests) cin>>testcase;
    cout<<fixed<<setprecision(10);
    for(ll test=1;test<=testcase;test++)
    {//cout<<"Case #"<<test<<": ";
        solve_case();
    }
    #ifdef LOCAL
        cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    #endif
    return 0;
}