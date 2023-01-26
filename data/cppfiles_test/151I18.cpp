#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define modulo  998244353
#define PI 3.141592653589793238462643
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template<class T> using orderedset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
/*long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}*/
bool prime[1000005];
int spf[100006];
void SieveOfEratosthenes()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    //bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=1000005; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=1000005; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers

}
void smallestprime()
{
 for(int i=0;i<100005;i++)
 {
    spf[i]=i;
 }
 for(int i=2;i<100005;i++)
 {
    if((i%2)==0)
    spf[i]=2;
 }
 for(int i=3;i*i<100005;i+=2)
 {
   if(spf[i]==i)
   {
    for(int j=i*i;j<100005;j+=i)
    {
     if(spf[j]=j)
        spf[j]=i;
    }
   }
 }
}
int con(string s)
{
 int num=0;
 for(int i=0;i<s.length();i++)
 {
    num=num*10+(s[i]-'0');
 }
 return num;
}
void findSmallestNumber(ll n)
{

    // Iterate in range[N, N + 2520]
    ll no=ceil((1.0*n)/2520);
    no=no*2520;
    for (ll i = n; i <= no; ++i) {

        bool possible = 1;

        // Store the number in a temporary
        // variable
        ll temp = i;
        while (temp) {
            if (temp % 10 != 0) {
                int digit = temp % 10;
                if (i % digit != 0) {
                    possible = 0;
                    break;
                }
            }
            temp /= 10;
        }

        if (possible == 1) {
            cout << i;
            return;
        }
    }
}
ll countDivisibles(ll A, ll B, ll M)
{

    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    // A is not divisible by M
    return (B / M) - (A / M);
}
ll fin(ll r,ll lcm,ll b)
{
 ll div=r/lcm;
 ll pro=div*lcm;
 ll tot=r;
 if(div!=0)
 {
    tot=tot-(div-1)*b;
    tot=tot-min(b,r-pro+1);
 }
 return tot-min(r,b-1);
}
ll fact[200005];
ll ifact[200005];
void factorial()
{
 for(int i=0;i<200005;i++)
 {
    fact[i]=0;
    ifact[i]=0;
 }
 fact[0]=1;
 ifact[0]=1;
 for(int i=1;i<200005;i++)
 {
    fact[i]=((fact[i-1])*i)%modulo;
    ifact[i]=(expo(fact[i],modulo-2,modulo))%modulo;
 }
}
//int dp[200005];
/*struct val
{
 int t,f,s;
};*/
/*bool comp(dimen &d1,dimen &d2)
{
// if(d1.h!=d2.h)
    return d1.h<d2.h;

}
map<ll,ll>mp;
void primeFactors(ll n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
           mp[i]++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        mp[n]++;
}
//vector<vector<int>>adj;
/*bool comp(pair<ll,ll>&a,pair<ll,ll>&b)
{
 if(a.first!=b.first)
 {
    return a.first<b.first;
 }
 return a.second>b.second;
}
/*struct grp
{
 int p;
 int r;
};
struct grp par[1002];
struct grp par1[1002];
int fin(int val)
{
 if(par[val].p!=val)
    par[val].p=fin(par[val].p);

    return par[val].p;
}
int fin1(int val)
{
  if(par1[val].p!=val)
    par1[val].p=fin1(par1[val].p);

    return par1[val].p;
}
int merg(int u,int v)
{
  if(par[u].r<par[v].r)
    {par[u].p=v;
    // par[v].r++;
    }
  else if(par[v].r<par[u].r)
  {
    par[v].p=u;
    //par[u].r++;
  }
  else
  {
    par[v].p=u;
    par[u].r++;
  }
 //par[v]=par[u];
}
int merg1(int u,int v)
{
  if(par1[u].r<par1[v].r)
    {par1[u].p=v;
    // par1[v].r++;
    }
  else if(par1[v].r<par1[u].r)
  {
    par1[v].p=u;
   // par1[u].r++;
  }
  else
  {
    par1[v].p=u;
    par1[u].r++;
  }
}*/
/*int a[200005][2];
ll RightAngled( ll n)
{

    // To store the number of points
    // has same x or y coordinates
    unordered_map<ll,ll> xpoints;
    unordered_map<ll,ll> ypoints;

    for (ll i = 0; i < n; i++) {
        xpoints[a[i][0]]++;
        ypoints[a[i][1]]++;
    }

    // Store the total count of triangle
    ll cnt = 0;

    // Iterate to check for total number
    // of possible triangle
    for (ll i = 0; i < n; i++) {

        if (xpoints[a[i][0]] >= 1
            && ypoints[a[i][1]] >= 1) {

            // Add the count of triangles
            // formed
            cnt += (xpoints[a[i][0]] - 1)
                     * (ypoints[a[i][1]] - 1);
        }
    }

    // Total possible triangle
    return cnt;
}
bool comp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{

    return p1.second< p2.second;
}
//vector<vector<int>>adj;
string solve(string a,string b)
{
 string r=b;
 int carry=0;
 int n=a.size(),m=b.size();
 for(int i=(m-1);i>=0;i--)
 {
    r[i]=b[i]+carry+((i>=(m-n))?(a[i-(m-n)]-'0'):0);
    if(r[i]>'9')
    {
     r[i]=r[i]-10;
     carry=1;
    }
    else
         carry=0;
 }
 return r;
}
//bool comp()
void convertTobasen(ll N,vector<ll>&v,ll k)
{
    // Base case
    if (N == 0)
        return;

    // Finding the remainder
    // when N is divided by 3
    ll x = N % k;
    N /= k;
    if (x < 0)
        N += 1;

    // Recursive function to
    // call the function for
    // the integer division
    // of the value N/3
    convertTobasen(N,v,k);

    // Handling the negative cases
    if (x < 0)
    {
        v.push_back(x + (k * -1));
    }
    else
        {
         v.push_back(x);
        }
}
*/
//int is1=0,is2=0;
/*int dp[51][51];
int maxi=INT_MIN;
int solve(string &s,string &s1,int n,int m)
{
 if(n==0||m==0)
    return 0;
 if(dp[n][m]!=-1)
    return dp[n][m];
    int c=0;
 if(s[n-1]==s1[m-1])
 {
   c=1+solve(s,s1,n-1,m-1);
   maxi=max(maxi,c);
 }
 dp[n][m]=c;
 solve(s,s1,n-1,m);
 solve(s,s1,n,m-1);
 return c;
}*/
/*bool chk(ll arr[],ll val,ll h)
{
 vector<ll>v;
 for(int i=0;i<val;i++)
 {
    v.push_back(arr[i]);
 }
 sort(v.begin(),v.end());
 ll p=h;
 for(int i=v.size()-1;i>=0;i=i-2)
 {
  p=p-v[i];
 }

 //cout<<"\n";
 if(p>=0)
    return true;
 else
    return false;
*/
ll stringTointeger(string str)
{
    ll temp = 0;
    for (ll i = 0; i < str.length(); i++) {


        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

int main()
{
 fast
 ll t;
 t=1;
 //SieveOfEratosthenes();
 while(t--)
  {
    ll q;
    cin>>q;
    vector<pair<ll,pair<ll,ll>>>v;
    for(int i=0;i<q;i++)
    {
     ll type;
     cin>>type;
     if(type==1)
     {
        ll l;
        cin>>l;
        v.push_back(make_pair(type,make_pair(l,l)));
     }
     else
     {
        ll l,r;
        cin>>l>>r;
        v.push_back(make_pair(type,make_pair(l,r)));
     }
    }
    map<ll,ll>vis;
    stack<ll>st;
    for(int i=v.size()-1;i>=0;i--)
    {
     pair<ll,pair<ll,ll>>p=v[i];
     if(v[i].first==1)
     {
        ll val=v[i].second.first;
        if(vis[val]==0)
        {
         st.push(val);
        }
        else
        {
         st.push(vis[val]);
        }
     }
     else
     {
        ll f=v[i].second.first;
        ll s=v[i].second.second;
        vis[f]=s;
        if(vis[s]!=0)
            vis[f]=vis[s];
        else
           vis[f]=s;
     }
    }
    while(!st.empty())
    {
     cout<<st.top()<<" ";
     st.pop();
    }
   cout<<"\n";
  }
}