#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sl;
typedef vector<string> vs;
typedef vector<char>vc;

//lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
//upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
#define in(v,n) for(ll i=0;i<n;i++)cin>>v[i]
#define inp(v,n) for(ll i=0;i<n;i++)cin>>v[i].first>>v[i].second
#define banao(x,y) memset(x,y,sizeof(x));
#define PI (2*acos(0.0))
#define pb push_back
#define show(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define showpair(v) for(int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << endl;
#define ff first
#define ss second
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define forn(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define forr(i,e) for(i=e;i>=0;i--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sortn(v) sort(all(v))
#define sortr(v) sort(rall(v))
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
//transform(a.begin(), a.end(), a.begin(), ::tolower);
//a.erase(remove(a.begin(), a.end(), ' '), a.end());
string decToBinary(int n)
{
    string s="";
    int i = 0;
    while (n > 0)
    {
        s =to_string(n % 2)+s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for(int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n)
{
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0||n%3==0)return false;
    for(int i=5; i*i<=n; i=i+6)if(n%i==0||n%(i+2)==0)return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if(n==0)return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b) * b);
}
#define sz 1000006
vll prime;
bool vis[sz];


void siv()
{
    for(ll i=3; i*i<=sz; i+=2)
    {
        if(vis[i]==0)
        {
            for(ll j=i*i; j<=sz; j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
    prime.pb(2);
    for(ll i=3; i<=sz; i+=2)
    {
        if(vis[i]==0)
            prime.pb(i);
    }

}

ll cntdiv(ll n)
{
    ll ans=1;
    for(ll i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            ll cnt=1;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];

            }
            ans=ans*cnt;
        }
    }
    if(n>1)
    {
        ans=ans*2;
    }
    return ans-1;
}


ll strToInt(string s)
{
    ll x=0;
    ll base=1;
    for(ll i=s.size()-1; i>=0; i--)
    {
        x+=((s[i]-'0')*base);
        base*=10;
    }
    return x;
}
//euler function
const ll mx=1e6+5e5;;
ll phi[mx];
ll primee[mx];
ll is_prime[mx];
ll prime_cnt;
void euler()
{
    phi[1]=1;
    for(ll i=2; i<mx; i++)
        is_prime[i]=1;
    for(ll i=2; i<mx; i++)
    {
        if(is_prime[i])
        {
            primee[++prime_cnt]=i;
            phi[i]=i-1;
        }
        for(ll j=1; j<=prime_cnt; j++)
        {
            if(i*primee[j]>=mx)
                break;
            is_prime[i*primee[j]]=0;
            if(i%primee[j]==0)
            {
                phi[i*primee[j]]=phi[i]*primee[j];
                break;
            }
            else
                phi[i*primee[j]]=phi[i]*(primee[j]-1);
        }
    }

}


void solve()
{
    ll n;
    cin>>n;
    vll v(n);
    in(v,n);
    sortn(v);
    if(v[0]==v[n-1])
    {
        cout<<0<<endl;
        return ;
    }
    ll d=v[n-1]-v[0];
    if(d+2==n)
    {
        cout<<0<<endl;
        return ;
    }
    cout<<1<<endl;

}
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
