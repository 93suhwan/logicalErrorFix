#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll                          long long int
#define M                           1000000007
#define inf                         1e18
#define ff                          first
#define ss                          second
#define fast                        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test                        int t; cin>>t; while(t--)
#define pb                          push_back
#define hmap                        unordered_map
#define pqb(t)                      priority_queue<t>
#define pqs(t)                      priority_queue<t,vector<t>,greater<t>>
#define all(s)                      s.begin(),s.end()
#define upto(n)                     std::cout << std::fixed;  std::cout << std::setprecision(n);
#define inp(t,a,n)                  vector<t> a(n); for(int i=0;i<n;i++) cin>>a[i];
#define inp_index(t,a,n)            vector<pair<t,t>> a(n); for(int i=0;i<n;i++){ cin>>a[i].ff>>a[i].ss;}
#define out(a)                      for(auto I:a) cout<<I<<" "; cout<<endl;
//Debugging
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " is " << a << endl;
    err(++it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(v.begin(),v.end(),rng);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//order_of_key(k),find_by_order(k)

void build()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void solve(){
    int n,k;
    cin>>n>>k;
    inp(int,a,n)
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[a[i]].pb(i);
    }
    vector<int> rest;
    for(auto i:mp){
        if(i.ss.size()>k){
            for(int j=0;j<k;j++){
                a[i.ss[j]]=j+1;
            }
            for(int j=k;j<i.ss.size();j++){
                a[i.ss[j]]=0;
            }
        }else{
            for(int j=0;j<i.ss.size();j++){
                rest.pb(i.ss[j]);
            }
        }
    }
    int color=1;
    for(int i=0;i<(rest.size()/k)*k;i++){
        a[rest[i]]=color++;
        if(color>k) 
            color=1;
    }
    out(a)
}

int main()
{
    fast
    build();
    test
    {
        solve();
        // cout << endl;
    }
    return 0;
}
