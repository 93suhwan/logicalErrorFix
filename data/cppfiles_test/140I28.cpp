#include<bits/stdc++.h> 
using namespace std;
#define modulo 1000000007   
#define wow ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
#define nl "\n"
#define pii pair<long int,long int>
#define vpii vector<pair<long int,long int>> 
#define vpsi vector<pair<int,string>>
#define vpci vector<pair<char, int>>
#define vpss vector<pair<string,string>>
#define vi vector<ll>
#define vs vector<string>
#define umi unordered_map<long int,long int>
#define mii map<int,int>
#define min(a,b) ((a)<(b)?(a):(b)) 
#define max(a,b) ((a)>(b)?(a):(b))
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define vll vector<ll>
#define msl multiset<long long>
void solve()
{
    ll n;
    cin>>n;
    ll count=0;
    if(n==1)
    {
        cout<<1<<nl;
        return;
    }
    for(int i=1;i<n;i++)
    {
        ll x=i*i*i*i*i*i;
        if(x>n)
        {
            count-=i-1;
            break;
        }
    }
    for(int i=1;i<n;i++)
    {
        ll x=i*i;
        ll y=x*i;
        if(x<=n)
            count++;
        else
            break;
        if(y<=n)
            count++;
    }
    cout<<count<<nl;
}
int main()
{
    std::cout << std::fixed << std::setprecision(12);
    wow;  
    int t;
    cin>>t;
    while(t--)
        solve();
}