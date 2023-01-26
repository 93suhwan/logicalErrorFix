#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18+7
#define MAX 1000000005
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define psll pair<string,ll>
bool sortbysec(const pair<string,ll> &a,const pair<string,ll> &b)
{
    return (a.second < b.second);
}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPalindrome(string sp)
{
    ll n=sp.size();
    for (ll k = 0; k <n; k++)
    {
        ll i = n - k - 1;
        if (sp[k] != sp[i])
            return false;
    }
    
    return true;
}
string ok(string s, ll k)
{
    ll n=s.size();
    string ans="";
    for(ll i=0;i<k;i++)
    {
        ans+=(char)(s[i%n]);
    }
    return ans;
}

ll lcm(ll a, ll b) 
{ 
    return (a * b) / __gcd(a, b); 
}
void swap(ll *xp, ll *yp)
{
    ll temp = *xp;
    *xp = *yp;
    *yp = temp;
}
ll mod_add(ll a,ll b)
{
    return ((a%MOD)+(b%MOD))%MOD;
}
ll mod_sub(ll a,ll b)
{
    return ((a%MOD)-(b%MOD)+MOD)%MOD;
}
ll mod_multi(ll a,ll b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

ll cmp (ll a, ll b)
{
    return a > b ;
}
void solve()
{
    ll n,k,a,b,c=0,sum=0,count=0,sum2=0,count1=0,sum1=1,flag=0,ans=1;
    // cin>>n;
    // ll arr[n];
    // for(ll i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    string s;
    cin>>s;
    k=s.size();
    if(s[0]!=s[k-1])
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) 
    {
    
        solve();
    }

    return 0;
}
