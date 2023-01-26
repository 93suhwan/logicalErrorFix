#include<bits/stdc++.h>
using  namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define _io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll _binpow(ll a,ll b){ll res=1;while(b){if(b&1){res=res*a;}a=a*a;b=b>>1;}return res;}
ll _fib(ll n){double phi = (1 + sqrt(5)) / 2;return round(pow(phi, n) / sqrt(5));}
bool _isprime(ll n)
{
    if(n==1)return false;
    if(n==2 || n==3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5;i*i<=(n);i=i+6){if(n%i==0 || n%(i+2)==0)return false;}
    return true;
}
void _sieve(ll n,vector<ll>&B)
{
	vector<bool> A(n+ 1, true);
	for(ll i=2;i<=n;i++){if(A[i]){B.push_back(i);for(ll j=i*i;j<=n;j=j+i){A[j]=false;}}}
}
void _segmentedSieve(ll n,vector<ll>&Ans)
{
	ll limit = floor(sqrt(n))+1;
	vector<ll> prime;
	_sieve(limit,prime);
	Ans=prime;
	ll low = limit;
	ll high = 2*limit;
	while (low < n){if (high >= n)high = n;bool mark[limit+1];
		memset(mark, true, sizeof(mark));
		for (ll i = 0; i < prime.size(); i++){ll loLim = floor(low/prime[i]) * prime[i];if (loLim < low)loLim += prime[i];for (ll j=loLim; j<=high; j+=prime[i])mark[j-low] = false;}
		for (ll i = low; i<high; i++)if (mark[i - low] == true)Ans.push_back(i);low = low + limit;high = high + limit;}
}
ll _gcd(ll a,ll b){return b==0?a:_gcd(b,a%b);}
ll _lcm(ll a,ll b){ll gc=_gcd(a,b);return a*b/gc;}
ll _gcdext(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=_gcdext(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
ll _lookup(ll n){ll k=8,res=0;ll A[256];A[0]=0;for(ll i=1;i<256;i++){A[i]=(i&1)+A[i/2];}while(k--){res=res+A[n&(0xff)];n=n>>8;}return res;}
bool _issolution(ll a,ll b,ll c){return (c%_gcd(a,b)==0);}//For Diophantine equation to check if solution exist or not....
vector<ll> _phi(ll n){vector<ll>p(n+1,0);for(ll i=1;i<=n;i++){p[i]=i;}for(ll i=2;i<=n;i++){if(p[i]==i){p[i]=i-1;for(ll j=2*i;j<=n;j=j+i){p[j]=(p[j]/i)*(i-1);}}}return p;}
ll derange(ll n)
{
    ll A[n+1]={0};
    A[1]=0;
    A[2]=1;
    for(ll i=3;i<=n;i++)
    {
     A[i]=(i-1)*(A[i-1]+A[i-2]);
    }
  return A[n];
}
template <typename T>
void _display(vector<T>A)
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
ll _countdivsum(ll n){ll res=1;for(ll i=2;i*i<=n;i++){ll sum=1;ll term=1;while(n%i==0){n=n/i;term=term*i;sum=sum+term;}res=res*sum;}if(n>=2)res=res*(n+1);return res;}
ll _phiforone(ll n)
{
    ll res=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res-res/i;
            while(n%i==0)
            {
                n=n/i;
            }
        }
    }
    if(n>1)res=res-res/n;
    return res;
}
ll _binomialCoeff(ll n, ll k){ll res = 1;if (k > n - k)k = n - k;for (ll i = 0; i < k; ++i) {res *= (n - i);res /= (i + 1);}return res;}
ll _modinverse(ll n,ll m){ll x,y;ll g=_gcdext(n,m,x,y);if(g!=1)return 0;else{if(x<0){x=(x+m)%m;}return x;}}
vector<ll> _catla(ll n){vector<ll>dp(n+1,0);ll p=0;dp[0]=1;for(ll i=0;i<=n;i++){for(ll j=0;j<i;j++){dp[i]=(dp[i]+(dp[j]*dp[i-j-1]));}}return dp;}
void str(string s,int i)
{
    if(i==s.size()-1)
    {
        cout<<s<<endl;
    }
    else
    {
        for(ll j=i;j<s.size();j++)
        {
            swap(s[i],s[j]);
            str(s,i+1);
            swap(s[j],s[i]);
        }
    }
}
ll _grundy(ll coin,vector<ll>picks, ll sizeofA)
{
    vector<ll>A(coin+1,0);
    A[0]=0;
    for(ll i=1;i<=coin;i++)
    {
        unordered_set<ll>s;
        for(ll j=0;j<sizeofA;j++)
        {
            if(i-picks[j]>=0)
            {
                s.insert(A[i-picks[j]]);
            }
        }
        for(ll j=0;j<=s.size();j++)
        {
            if(s.find(j)==s.end())
            {
                A[i]=j;
            }
        }
    }
    return A[coin];
}
 ll _getSum(ll n){ ll sum = 0;while (n != 0) {sum = sum + n % 10;n = n / 10;}return sum;}
vector<ll> _div(ll n)
{
    vector<ll>A;
    ll i=1;
  for(;i*i<=n;i++)
  {
    if(n%i==0)
    {
        A.push_back(i);
    }
  }
  i--;
  for(;i>=1;i--)
  {
      if(n%i==0 && n/i!=i)
      {
          A.push_back(n/i);
      }
  }

  return A;
}
//vector<ll> A[1000000];
//int lev[1000000];
//int subtree[1000000];
/*
void dfs(ll node, ll par, ll level=1)
{
    lev[node]=level;
    ll sum=0;
 for(auto it:A[node])
 {
     if(it!=par)
     {
         dfs(it,node,level+1);
         sum=sum+subtree[it];
     }
 }
 subtree[node]=1+sum;
}
  for(ll k=2;k<=n;k=k+2)
       {
                ll cnt0=0;
                ll cnt1=0;
       for(ll i=0;i<k;i++)
       {
            if(A[i]==0)cnt0++;
            if(A[i]==1)cnt1++;
       }
       if(cnt0==(cnt1*cnt1))
       {
           cntg++;
       }
       ll l1=0;
       ll r1=k-1;
       while(r1+1<n)
       {
         if(A[l1]==0)
         {
             cnt0--;
         }
          if(A[l1]==1)
         {
             cnt1--;
         }
         l1++;
         r1++;
        if(A[r1]==0)
         {
             cnt0++;
         }
          if(A[r1]==1)
         {
             cnt1++;
         }
          if(cnt0==(cnt1*cnt1))
       {
           cntg++;
       }

       }
       }
       cout<<cntg<<endl;

   }
*/
ll _sqrt(ll n)
{
    ll k=n/2;
    ll l=1, r=n/2;

    ll Ans=0;
    while(l<=r)
    {
          ll mid=(l+r)/2;
        if(mid*mid==n)
        {
           return mid;
        }
        if(mid*mid<n)
        {
            l=mid+1;
            Ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    return Ans;
}
int _hammingDist(string str1, string str2)
{
    int i = 0, count = 0;
    while(str1[i]!='\0')
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}
ll _mincoin(vector<ll>A,ll am,int dp[])
{
  if(am==0)return 0;
  if(dp[am]!=0)return dp[am];
  ll Ans=INT_MAX;
  for(int i=0;i<A.size();i++)
  {
      ll a;
     if(am-A[i]>=0)
     {
         a=_mincoin(A,am-A[i],dp)+1;
         Ans=min(Ans,a);
     }
  }
  return dp[am]=Ans;
}
int main()
{
ll T;
cin>>T;
while(T--)
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>A;
    for(ll i=0;i<s.size();i++)
    {
        A.push_back(int(s[i])-int('0'));
    }
    ll l=0;
    ll r=s.size()-1;
    ll Ans=0;
    while(l<r)
    {
        if(A[r]!=0)
        {
            Ans=Ans+A[r];
            A[r]=0;
        }
        if(A[l]!=0)
        {
            Ans=Ans+1+A[l];
            l++;
        }
        else
        {
            l++;
        }
    }
    cout<<Ans<<endl;
}
}

