/*
    (     )
    (     )
     ^^^^^^
     | 0 0|-----------------
     |    |\                )_____
     (O--O) \               )_____\      
             \------------- )     \\
               ||\      ||\       ****    
               ||\\     ||\\       ***
               || \\    || \\       *
               ||  \\   ||  \\
             
*/
#include<bits/stdc++.h>
#define forL(i,j,k) for(ll i=j; i<k; ++i)
#define pb push_back
#define ll long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define all(v) v.begin(),v.end()
#define inMap(m,x) m.count(x) 
using namespace std;

// vector
// map
// queue
// stack
// unordered_map
// unordered_set
// pair

void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

/*bool prime[1000001];
sieve from shubhgod
void sieve(ll n = 1000001) {
    memset(prime, true, n);
 
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; (ll)(p * p) <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
}*/

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}

ll msb(ll n)
{
    ll t=-1;
    while(n)
    {
        n=n>>1;
        ++t;
    }
    return t;
}

bool isPrime(ll n)
{
    for(ll i=2; i*i < n; ++i)
    {
        if(n%i == 0)
        return false;
    }
    return true;
}

const ll mod=1e9+7;

ll mypow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a)%mod;
        b /= 2;
        a = (ans*a)%mod;
    }
    return ans;
}

class comp
{
    public:
    bool operator()(const pair<ll,ll> & p1, const pair<ll,ll> & p2)
    {
        return p1.second <= p2.second;
    }
};

bool is(ll * a, ll n, ll x)
{
    if(x != -1)
    {
        ll t=a[x+1];
        a[x+1]=a[x];
        a[x]=t;    
    }
    

    forL(i,1,n)
    {
        if(a[i+1] < a[i])
        return false;
    }
    
    return true;
}

void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> grid(n);
    forL(i,0,n)
    {
        ll x;
        cin>>x;
        forL(j,0,x)
        {
            ll t;
            cin>>t;
            grid[i].pb(t);
        }
    }
    
    vector<pair<ll,ll>> intervals;
    forL(i,0,n)
    {
        ll maxNum=INT_MIN;
        ll ind;
        forL(j,0,grid[i].size())
        {
            // if(grid[i][j] > maxNum)
            // {
            //     maxNum=grid[i][j];
            //     ind=j;
            // }
            maxNum=max(maxNum , grid[i][j]-j+1);
        }
        
        // ll t=maxNum-ind+1;
        intervals.pb({maxNum , maxNum+grid[i].size()});
    }
    
    sort(intervals.begin(),intervals.end(),comp());
    
    vector<ll> left,right;
    forL(i,0,intervals.size())
    {
        left.pb(intervals[i].first);
        right.pb(intervals[i].second);
        // cout<<left[i]<<" "<<right[i]<<endl;
    }
    
    ll mins[(ll)(left.size())]={0};
    mins[(ll)(left.size())-1]=left.back();
    for(ll i=((ll)(left.size())-2); i>=0; --i)
    {
        mins[i]=min(mins[i+1] , left[i]);
    }
    
    // forL(i,0,left.size())
    // {
    //     cout<<mins[i]<<" "<<left[i]<<" "<<right[i]<<endl;
    // }
    
    ll c,xxx=INT_MIN;
    forL(i,0,left.size())
    {
        if(left[i] > xxx)
        {
            xxx=left[i];
            c=i;
        }
    }
    
    while(true)
    {
        ll x=lower_bound(right.begin(),right.end(),mins[c]) - right.begin();
        if(x == c)
        {
            cout<<left[c];
            break;
        }
        c=x;
    }
}

int main() {
    speed();
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
        cout<<endl;
    }
};