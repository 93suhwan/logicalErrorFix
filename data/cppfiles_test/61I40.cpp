#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;
#define vc vector
#define mapll map<ll,ll>
#define setll set<ll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define loopf(i,a,b) for(ll i=a;i<b;i++)
#define loopb(i,b,a) for(ll i=a-1;i>=b;i--)
typedef vector<ll> vll;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll>> vpl;
#define read(v) for(int i=0;i<(int)v.size();++i) cin>>v[i]
#define read1(v) for(int i=1;i<(int)v.size();++i) cin>>v[i]
#define print(v) for(int i=0;i<(int)v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define print1(v) for(int i=1;i<(int)v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define ANS cout<<ans<<endl
#define ub upper_bound
#define lb lower_bound
#define max_heap priority_queue<ll>
#define min_heap priority_queue<ll, vector<ll>, greater<ll>>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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
#define umapll unordered_map<ll,ll,custom_hash>
//const ll M=(ll)1e9+7;

void solve();
int main() {
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);


ll t=1;
cin>>t;
while(t--){
    solve();
}
return 0;
}
 
void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll q=0;
    loopf(i,0,n)if(s[i]=='?')q++;
    if(q==0){cout<<s<<endl; return;}
    if(q==n){
        for(ll i=0;i<n;i+=2)s[i]='B';
        for(ll i=1;i<n;i+=2)s[i]='R';
        cout<<s<<endl;
        return;
    }
    ll i=0;
    ll last = -1;
    while(i<n){
        if(s[i]!='?'){
            last = i;
            ll j=i-1;
            char c = s[i];
            char d;
            if(s[i]=='R')d='B';
            else d='R';
            while(j>=0 && s[j]=='?'){
                if((i-j)%2==0)s[j]=c;
                else{
                    s[j]=d;
                }
                j--;
            }
        }
        i++;
    }
    if(last==n-1){cout<<s<<endl; return;}
    i=last;
    char c = s[i];
            char d;
            if(s[i]=='R')d='B';
            else d='R';
    ll j=i+1;
    while(j<n){
        if((j-i)%2==0)s[j]=c;
                else{
                    s[j]=d;
                }
                j++;
    }
}