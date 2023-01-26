#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define pb push_back 
#define mod 1000000007
#include <iomanip>
#define LL_MAX 9223372036854775807

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef  vector<ll> vi;
typedef vector<vector<ll> > vvi;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}

int ceilab(int a,int b){
    if(a%b==0){
        return a/b;
    }
    return (a/b) +1;
}

int grecomdiv(int a, int b)
{
    if (b == 0)
        return a;
    return grecomdiv(b, a % b);
     
}

//int dp[501][501];
int dp[200005];

void solve(){      

int a;
cin>>a;

vi v;
for(int i=0;i<a;i++){
    int a1;
    cin>>a1;
    v.pb(a1);
}

ordered_set os;
ll ans =0;
unordered_map <int,int> mp;

os.insert(v[0]);
mp[v[0]] = 1;

for(int i=1;i<a;i++){
    int temp = 0;
    if(mp.find(v[i])!=mp.end()){
        temp = mp[v[i]];
    }
    
    int k = os.order_of_key(v[i]);
    int kk = min(k,i-k-temp);
    os.insert(v[i]);
    ans = ans + kk;
    mp[v[i]]++;
}
cout<<ans<<endl;


//return
}
    
    

// ctrl+b to run file
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test=1;
    cin>>test;
    
    for(int i=0;i<100005;i++){
        dp[i] = 0;
    }

    while(test--){
        
        solve();
        
    }
    return 0;
}

/*
 printf("%0.9f\n", aa); // to set the precision of 9 after decimal

 sort(v.begin(),v.end());
 sort(s.begin(),s.end());
    int b;
    cin>>b;
 
    ll a;
    cin>>a;
    vi v;
    for(int i=0;i<a;i++){
       ll a1;
       cin>>a1;
       v.pb(a1);
    }
       
    for(int i=0;i<secvec.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

*/