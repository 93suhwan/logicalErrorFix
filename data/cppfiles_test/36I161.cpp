#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;

#define make_it_fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define ll long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define imn (ll)-1e16
#define imx (ll)1e16
#define verdict(con) cout<<((con)?"YES":"NO")<<endl;

ld pi=3.14159265358979323846;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 20
#endif

ll mod=1e9+7;
ll power(ll a,ll b,ll m)
{
    a%=m;
    if(b==1)
    return a;
    if(b==0)
    return 1LL;
    ll ret=power(a,b/2,m);
    ret=(ret*ret)%m;
    if(b&1)
    ret=(ret*a)%m;
    return ret;
}

ll power(ll a,ll b)
{
    if(b==1)
    return a;
    if(b==0)
    return 1LL;
    ll ret=power(a,b/2);
    ret=(ret*ret);
    if(b&1)
    ret=(ret*a);
    return ret;
}

ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}

bool isprime(ll x){
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

void answer_nikaal()
{
    ll n,i;
    cin>>n;
    ll a[n],s=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(isprime(s)){
        for(i=0;i<n;i++){
            if(a[i]&1)
                break;
        }
        ll x=i;
        cout<<n-1<<endl;
        for(i=0;i<n;i++){
            if(i==x)
                continue;
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<n<<endl;
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    make_it_fast;
    int TEST_CASES=1;
    cin>>TEST_CASES;
    while(TEST_CASES--)
    {
        answer_nikaal();
    }
    return 0;
}