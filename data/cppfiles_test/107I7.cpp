//Author - Bhoopen
#include "bits/stdc++.h"
#define f(i,a,b) for(auto i = a; i <b; i++)
#define print(v) for(auto x:v) { cout << x <<" ";} cout << endl;
#define print_pair(v) for(auto x:v) { cout << x.first <<" "<<x.second<<endl;} //cout << endl;
#define mp make_pair
#define lb lower_bound
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define all(v) v.begin(), v.end()
#define ub upper_bound
#define pb push_back
#define mod 1000000007
#define ll long long
#define inf 2e9
#define nl "\n" 
using namespace std;

ll lcm(ll a, ll b){
    return (a / __gcd(a, b)) * b;
}

ll factorial(ll n) 
{ 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 

bool isPrime(ll n){ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}

void FAST(){   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
} 

bool mycomp(pair<ll, ll> &a, pair<ll, ll> &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % mod;
            p /= 2;
        }        
        else {
            res = res * 1ll * a % mod;
            p--;
        }
    }
  return res;
}

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res = res * 1ll * i % mod;
    }
    return res;
}

void ffin(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    FAST();
}

ll nCk(ll n, ll k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}

//Instructions - 
// double outputs as 3.33333e+008 but required output maybe 333333334
// just typecast the output as ll for that

void solve(){
    ll n, a, b;
    cin>>n>>a>>b;
    vector<ll> x(n);
    if(a>=b){
        ll l=1, h=n;
        for(ll i=0;i<n;i+=2){
            x[i]=l;
            l++;
        }
        for(ll i=1;i<n;i+=2){
            x[i]=h;
            h--;
        }
    }
    else{
        ll l=1, h=n;
        for(ll i=0;i<n;i+=2){
            x[i]=h;
            h--;
        }
        for(ll i=1;i<n;i+=2){
            x[i]=l;
            l++;
        }
    }
    // print(x);
    
    if(max(a, b)>((n/2)-1) and n%2==0){
        cout<<-1<<endl;
    }
    else if(max(a, b)>(n/2) and n%2==1)
        cout<<-1<<endl;
    else if(abs(a-b)>1){
        cout<<-1<<endl;
    }
    else{
        if(a==0 and b==0){
            for(ll i=0;i<n;i++){
                x[i]=i+1;
            }
        }
        else {
            ll aa=0, bb=0;
            for(ll i=1;i<n-1;i++){
                if(x[i]>x[i+1] and x[i]>x[i-1]){
                    aa++;
                }
                else if(x[i]<x[i+1] and x[i]<x[i-1]){
                    bb++;
                }
                if(aa==a and bb==b){
                    if(x[i]>x[i+1] and x[i]>x[i-1])
                        sort(x.begin()+i+1, x.end(), greater<ll>());
                    else
                        sort(x.begin()+i+1, x.end());
                    break;
                }
            }
        }
        print(x);
    }
    
}

int main(){
    FAST();
    ll tests=1;
    cin>>tests;
    ll t=1;
    while(t<=tests){
        //cout<<"Case #"<<t<<": ";
        solve();
        t++;
    }
} 